--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )

local framework = framework

module( "framework.graphics" )

function polygon( vertices )
	local pVertices = ffi.new( "GLfloat[?]", #vertices, vertices )
	local shader    = framework.graphics.getShader()
	local vertex    = GL.glGetAttribLocation( shader, "vertex" )
	GL.glVertexAttribPointer( vertex, 2, GL.GL_FLOAT, 0, 0, pVertices )
	framework.graphics.updateTransform()
	GL.glBindTexture( GL.GL_TEXTURE_2D, framework.graphics.getDefaultTexture()[0] )
	GL.glDrawArrays( GL.GL_TRIANGLES, 0, #vertices / 2 )
end

function rectangle( x, y, width, height )
	local vertices = {
		x,         y + height,
		x + width, y + height,
		x,         y,
		x + width, y + height,
		x + width, y,
		x,         y
	}
	polygon( vertices )
end
