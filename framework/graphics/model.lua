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

function model:model( filename )
	local buffer, length = framework.filesystem.read( filename )
	self.scene = assimp.aiImportFileFromMemory( buffer, length, bit.bor(
		ffi.C.aiProcess_CalcTangentSpace,
		ffi.C.aiProcess_GenSmoothNormals,
		ffi.C.aiProcess_JoinIdenticalVertices,
		ffi.C.aiProcess_ImproveCacheLocality,
		ffi.C.aiProcess_LimitBoneWeights,
		ffi.C.aiProcess_RemoveRedundantMaterials,
		ffi.C.aiProcess_SplitLargeMeshes,
		ffi.C.aiProcess_Triangulate,
		ffi.C.aiProcess_GenUVCoords,
		ffi.C.aiProcess_SortByPType,
		ffi.C.aiProcess_FindDegenerates,
		ffi.C.aiProcess_FindInvalidData,
		ffi.C.aiProcess_FindInstances,
		ffi.C.aiProcess_ValidateDataStructure,
		ffi.C.aiProcess_OptimizeMeshes,
		ffi.C.aiProcess_Debone
	), nil )

	for i = 0, self.scene.mNumMaterials do
	end

	setproxy( self )
end

function model:draw( x, y, r, sx, sy, ox, oy, kx, ky )
	if ( mode == "line" ) then
		mode = GL.GL_LINE_LOOP
	elseif ( mode == "fill" ) then
		mode = GL.GL_TRIANGLES
	end
	local defaultVBO = framework.graphics._defaultVBO
	local pVertices  = ffi.new( "GLfloat[?]", #vertices, vertices )
	local size       = ffi.sizeof( pVertices )
	local shader     = framework.graphics.getShader()
	local vertex     = GL.glGetAttribLocation( shader, "vertex" )
	local texCoord   = GL.glGetAttribLocation( shader, "texcoord" )
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, defaultVBO[0] )
	GL.glBufferData( GL.GL_ARRAY_BUFFER, size, pVertices, GL.GL_STREAM_DRAW )
	GL.glVertexAttribPointer( vertex, 3, GL.GL_FLOAT, 0, 0, nil )
	GL.glDisableVertexAttribArray( texCoord )
	framework.graphics.updateTransformations()
	local defaultTexture = framework.graphics.getDefaultTexture()
	GL.glBindTexture( GL.GL_TEXTURE_2D, defaultTexture[0] )
	framework.graphics.drawArrays( mode, 0, #vertices / 3 )
end

function model:__gc()
	assimp.aiReleaseImport( self.scene )
end
