--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local GL  = require( "opengl" )
local ffi = require( "ffi" )

class( "framework.graphics.mesh" )

local mesh = framework.graphics.mesh

function mesh:mesh( vertices, count )
	self.vbo = ffi.new( "GLuint[1]" )
	GL.glGenBuffers( 1, self.vbo )
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, self.vbo[0] )

	local size = ffi.sizeof( vertices )
	GL.glBufferData( GL.GL_ARRAY_BUFFER, size, vertices, GL.GL_STATIC_DRAW )
	self.vertices = vertices
	self.count    = count

	setproxy( self )
end

function mesh:draw( x, y, r, sx, sy, ox, oy, kx, ky )
	local shader         = framework.graphics.getShader()
	local vertex         = GL.glGetAttribLocation( shader, "vertex" )
	local texCoord       = GL.glGetAttribLocation( shader, "texcoord" )
	local defaultTexture = framework.graphics.getDefaultTexture()
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, self.vbo[0] )
	GL.glVertexAttribPointer( vertex, 3, GL.GL_FLOAT, 0, 0, nil )
	GL.glDisableVertexAttribArray( texCoord )
	framework.graphics.updateTransformations()
	GL.glBindTexture( GL.GL_TEXTURE_2D, defaultTexture[0] )
	framework.graphics.drawArrays( GL.GL_TRIANGLES, 0, self.count )
end

function mesh:__gc()
	GL.glDeleteBuffers( 1, self.vbo )
end
