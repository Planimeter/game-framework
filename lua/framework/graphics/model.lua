--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local assimp = require( "assimp" )
local ffi    = require( "ffi" )
local bit    = require( "bit" )
local GL     = require( "opengl" )
local physfs = require( "physicsfs" )

class( "framework.graphics.model" )

local model = framework.graphics.model

local function PHYSFSReadProc( self, buffer, size, count )
	local file = ffi.cast( "void *", self.UserData )
	return physfs.PHYSFS_read( file, buffer, size, count )
end

local function PHYSFSWriteProc( self, buffer, size, count )
	local file = ffi.cast( "void *", self.UserData )
	return physfs.PHYSFS_write( file, buffer, size, count )
end

local function PHYSFSTellProc( self )
	local file = ffi.cast( "void *", self.UserData )
	return physfs.PHYSFS_tell( file )
end

local function PHYSFSFileSizeProc( self )
	local file = ffi.cast( "void *", self.UserData )
	return physfs.PHYSFS_fileLength( file )
end

local function PHYSFSSeekProc( self, offset, whence )
	local file = ffi.cast( "void *", self.UserData )
	local ret  = physfs.PHYSFS_seek( file, offset )
	if ( ret ~= 0 ) then
		return ffi.C.aiReturn_SUCCESS
	else
		-- TODO: Return ffi.C.aiReturn_OUTOFMEMORY.
		return ffi.C.aiReturn_FAILURE
	end
end

local function PHYSFSFlushProc( self )
	local file = ffi.cast( "void *", self.UserData )
	physfs.PHYSFS_flush( file )
end

local function PHYSFSOpenProc( self, filename, mode )
	local file        = ffi.new( "struct aiFile" )
	file.ReadProc     = PHYSFSReadProc
	file.WriteProc    = PHYSFSWriteProc
	file.TellProc     = PHYSFSTellProc
	file.FileSizeProc = PHYSFSFileSizeProc
	file.SeekProc     = PHYSFSSeekProc
	file.FlushProc    = PHYSFSFlushProc
	local handle      = physfs.PHYSFS_openRead( filename )
	file.UserData     = ffi.cast( "void *", handle )
	return handle ~= nil and file or nil
end

local function PHYSFSCloseProc( self, file )
	physfs.PHYSFS_close( ffi.cast( "void *", file.UserData ) )
end

local function getPHYSFSFileIO()
	if ( model._fileIO ) then
		return model._fileIO
	end

	local fileIO     = ffi.new( "struct aiFileIO" )
	fileIO.OpenProc  = PHYSFSOpenProc
	fileIO.CloseProc = PHYSFSCloseProc
	model._fileIO    = fileIO
	return fileIO
end

local textureTypes = {
	diffuse      = ffi.C.aiTextureType_DIFFUSE,
	specular     = ffi.C.aiTextureType_SPECULAR,
	ambient      = ffi.C.aiTextureType_AMBIENT,
	emissive     = ffi.C.aiTextureType_EMISSIVE,
	height       = ffi.C.aiTextureType_HEIGHT,
	normals      = ffi.C.aiTextureType_NORMALS,
	shininess    = ffi.C.aiTextureType_SHININESS,
	opacity      = ffi.C.aiTextureType_OPACITY,
	displacement = ffi.C.aiTextureType_DISPLACEMENT,
	lightmap     = ffi.C.aiTextureType_LIGHTMAP,
	reflection   = ffi.C.aiTextureType_REFLECTION
}

local function getMaterialTexture( self, mesh, type )
	local texIndex = 0
	local texFound = ffi.C.aiReturn_SUCCESS

	local path = ffi.new( "struct aiString" )

	repeat
		texFound = assimp.aiGetMaterialTexture(
			self.scene.mMaterials[mesh.mMaterialIndex],
			type,
			texIndex,
			path,
			nil,
			nil,
			nil,
			nil,
			nil,
			nil
		)
		if ( texFound == ffi.C.aiReturn_SUCCESS ) then
			local filename  = self.filename
			local directory = string.match( filename, "(.+/)[^/]*$" ) or ""
			filename        = directory .. ffi.string( path.data, path.length )
			return filename
		end
		texIndex = texIndex + 1
	until ( texFound ~= ffi.C.aiReturn_SUCCESS )
end

local function processMaterials( self, mesh )
	local textures = {}
	for k, type in pairs( textureTypes ) do
		textures[ k ] = getMaterialTexture( self, mesh, type )
	end
	return textures
end

local function processMesh( self, mesh, transformation )
	local stride   = ( 3 + 3 + 3 + 2 )
	local vertices = ffi.new( "GLfloat[?]", stride * mesh.mNumVertices )
	for i = 0, mesh.mNumVertices - 1 do
		do
			vertices[stride * i + 0]  = mesh.mVertices[i].x
			vertices[stride * i + 1]  = mesh.mVertices[i].y
			vertices[stride * i + 2]  = mesh.mVertices[i].z
		end

		if ( mesh.mNormals ~= nil ) then
			vertices[stride * i + 3]  = mesh.mNormals[i].x
			vertices[stride * i + 4]  = mesh.mNormals[i].y
			vertices[stride * i + 5]  = mesh.mNormals[i].z
		end

		if ( mesh.mTangents ~= nil ) then
			vertices[stride * i + 6]  = mesh.mTangents[i].x
			vertices[stride * i + 7]  = mesh.mTangents[i].y
			vertices[stride * i + 8]  = mesh.mTangents[i].z
		end

		if ( mesh.mTextureCoords[0] ~= nil ) then
			vertices[stride * i + 9]  = mesh.mTextureCoords[0][i].x
			vertices[stride * i + 10] = mesh.mTextureCoords[0][i].y
		end
	end

	local textures = processMaterials( self, mesh )
	require( "framework.graphics.mesh" )
	return framework.graphics.mesh(
		vertices, mesh.mNumVertices, textures, transformation
	)
end

local function processNode( self, node, transformation )
	local prev = ffi.new( "struct aiMatrix4x4[1]" )
	prev[0] = transformation[0]

	assimp.aiMultiplyMatrix4( transformation, node.mTransformation )

	for i = 0, node.mNumMeshes - 1 do
		local mesh = self.scene.mMeshes[node.mMeshes[i]]
		table.insert( self.meshes, processMesh( self, mesh, transformation ) )
	end

	for i = 0, node.mNumChildren - 1 do
		processNode( self, node.mChildren[i], transformation )
	end
	transformation[0] = prev[0]
end

function model:model( filename )
	self.filename = filename
	self.scene    = assimp.aiImportFileEx( filename, bit.bor(
		ffi.C.aiProcess_CalcTangentSpace,
		ffi.C.aiProcess_GenNormals,
		ffi.C.aiProcess_Triangulate,
		ffi.C.aiProcess_GenUVCoords,
		ffi.C.aiProcess_SortByPType,
		ffi.C.aiProcess_FlipUVs
	), getPHYSFSFileIO() )
	if ( self.scene == nil ) then
		error( ffi.string( assimp.aiGetErrorString() ), 3 )
	end

	self.meshes = {}

	if ( self.scene.mRootNode ~= nil ) then
		local transformation = ffi.new( "struct aiMatrix4x4[1]" )
		assimp.aiIdentityMatrix4( transformation )

		processNode( self, self.scene.mRootNode, transformation )
	end

	setproxy( self )
end

function model:draw( x, y, r, sx, sy, ox, oy, kx, ky )
	for _, mesh in ipairs( self.meshes ) do
		framework.graphics.push()
			framework.graphics.draw( mesh, x, y, r, sx, sy, ox, oy, kx, ky )
		framework.graphics.pop()
	end
end

function model:getBoundingBox( min, max )
	local transformation = ffi.new( "struct aiMatrix4x4[1]" )
	assimp.aiIdentityMatrix4( transformation )

	min.x =  1e10
	min.y =  1e10
	min.z =  1e10
	max.x = -1e10
	max.y = -1e10
	max.z = -1e10
	if ( self.scene.mRootNode ~= nil ) then
		self:getBoundingBoxForNode(
			self.scene.mRootNode, min, max, transformation
		)
	end
end

function model:getBoundingBoxForNode( node, min, max, transformation )
	local prev = ffi.new( "struct aiMatrix4x4[1]" )
	prev[0] = transformation[0]

	assimp.aiMultiplyMatrix4( transformation, node.mTransformation )

	for n = 0, node.mNumMeshes - 1 do
		local mesh = self.scene.mMeshes[node.mMeshes[n]]
		for t = 0, mesh.mNumVertices - 1 do

			local tmp = mesh.mVertices[t]
			assimp.aiTransformVecByMatrix4( tmp, transformation )

			min.x = math.min( min.x, tmp.x )
			min.y = math.min( min.y, tmp.y )
			min.z = math.min( min.z, tmp.z )

			max.x = math.max( max.x, tmp.x )
			max.y = math.max( max.y, tmp.y )
			max.z = math.max( max.z, tmp.z )
		end
	end

	for n = 0, node.mNumChildren - 1 do
		self:getBoundingBoxForNode(
			node.mChildren[n], min, max, transformation
		)
	end
	transformation[0] = prev[0]
end

function model:__gc()
	assimp.aiReleaseImport( self.scene )
end
