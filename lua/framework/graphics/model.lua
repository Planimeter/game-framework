--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
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
	local vertices = ffi.new( "GLfloat[?]", 3 * mesh.mNumVertices )
	for i = 0, mesh.mNumVertices - 1 do
		vertices[3 * i + 0] = mesh.mVertices[i].x
		vertices[3 * i + 1] = mesh.mVertices[i].y
		vertices[3 * i + 2] = mesh.mVertices[i].z
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
	self.scene = assimp.aiImportFileFromMemory( buffer, length, bit.bor(
		ffi.C.aiProcess_Triangulate
	), nil )

	self.meshes = {}
	processNode( self, self.scene.mRootNode )

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
