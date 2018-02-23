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
	local position       = GL.glGetAttribLocation( shader, "position" )
	local stride         = ( 3 + 3 + 3 + 2 ) * ffi.sizeof( "GLfloat" )
	local pointer        = ffi.cast( "GLvoid *", 3 * ffi.sizeof( "GLfloat" ) )
	local normal         = GL.glGetAttribLocation( shader, "normal" )
	local tangent        = GL.glGetAttribLocation( shader, "tangent" )
	local texcoord       = GL.glGetAttribLocation( shader, "texcoord" )
	local defaultTexture = framework.graphics.getDefaultTexture()
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, self.vbo[0] )
	GL.glVertexAttribPointer( position, 3, GL.GL_FLOAT, 0, stride, nil )
	GL.glVertexAttribPointer( normal, 3, GL.GL_FLOAT, 0, stride, pointer )
	pointer = ffi.cast( "GLvoid *", ( 3 + 3 ) * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( tangent, 3, GL.GL_FLOAT, 0, stride, pointer )
	pointer = ffi.cast( "GLvoid *", ( 3 + 3 + 3 ) * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( texcoord, 2, GL.GL_FLOAT, 0, stride, pointer )
	framework.graphics.updateTransformations()
	GL.glBindTexture( GL.GL_TEXTURE_2D, defaultTexture[0] )
	framework.graphics.drawArrays( GL.GL_TRIANGLES, 0, self.count )
end

function mesh:__gc()
	GL.glDeleteBuffers( 1, self.vbo )
end
