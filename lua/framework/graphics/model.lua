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

class( "framework.graphics.model" )

local model = framework.graphics.model

local function processMesh( self, mesh )
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
	require( "framework.graphics.mesh" )
	return framework.graphics.mesh( vertices, mesh.mNumVertices )
end

local function processNode( self, node )
	for i = 0, node.mNumMeshes - 1 do
		local mesh = self.scene.mMeshes[node.mMeshes[i]]
		table.insert( self.meshes, processMesh( self, mesh ) )
	end

	for i = 0, node.mNumChildren - 1 do
		processNode( self, node.mChildren[i] )
	end
end

function model:model( filename )
	local buffer, length = framework.filesystem.read( filename )
	if ( buffer == nil ) then
		error( length, 3 )
	end
	local hint = string.match( filename, "%.([^%.]+)$" )
	self.scene = assimp.aiImportFileFromMemory( buffer, length, bit.bor(
		ffi.C.aiProcess_CalcTangentSpace,
		ffi.C.aiProcess_GenNormals,
		ffi.C.aiProcess_Triangulate,
		ffi.C.aiProcess_GenUVCoords,
		ffi.C.aiProcess_SortByPType
	), hint )
	if ( self.scene == nil ) then
		error( ffi.string( assimp.aiGetErrorString() ), 3 )
	end

	self.meshes = {}

	if ( self.scene.mRootNode ~= nil ) then
		processNode( self, self.scene.mRootNode )
	end

	setproxy( self )
end

function model:draw( x, y, r, sx, sy, ox, oy, kx, ky )
	for _, mesh in ipairs( self.meshes ) do
		framework.graphics.draw( mesh, x, y, r, sx, sy, ox, oy, kx, ky )
	end
end

function model:__gc()
	assimp.aiReleaseImport( self.scene )
end
