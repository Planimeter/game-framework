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
	GL.glVertexAttribPointer( vertex, 2, 0x1406, 0, 0, pVertices )
	GL.glBindTexture( 0x0DE1, framework.graphics.getDefaultTexture()[0] )
	GL.glDrawArrays( 0x0004, 0, #vertices / 2 )
end

function rectangle( x, y, width, height )
	local vertices = {
		x,         y + height, -- Bottom-left
		x + width, y + height, -- Bottom-right
		x,         y,          -- Top-left
		x + width, y + height, -- Bottom-right
		x + width, y,          -- Top-right
		x,         y           -- Top-left
	}
	polygon( vertices )
end
