--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local GL  = require( "opengl" )
local ffi = require( "ffi" )

local framework = framework

module( "framework.graphics" )

function polygon( mode, vertices )
	if ( mode == "line" ) then
		mode = GL.GL_LINE_LOOP
	elseif ( mode == "fill" ) then
		mode = GL.GL_TRIANGLES
	end
	local pVertices = ffi.new( "GLfloat[?]", #vertices, vertices )
	local size      = ffi.sizeof( pVertices )
	local shader    = framework.graphics.getShader()
	local vertex    = GL.glGetAttribLocation( shader, "vertex" )
	local texCoord  = GL.glGetAttribLocation( shader, "texcoord" )
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, defaultVBO[0] )
	GL.glBufferData( GL.GL_ARRAY_BUFFER, size, pVertices, GL.GL_STREAM_DRAW )
	GL.glVertexAttribPointer( vertex, 2, GL.GL_FLOAT, 0, 0, nil )
	GL.glDisableVertexAttribArray( texCoord )
	framework.graphics.updateTransform()
	GL.glBindTexture( GL.GL_TEXTURE_2D, framework.graphics.getDefaultTexture()[0] )
	framework.graphics.drawArrays( mode, 0, #vertices / 2 )
end

function rectangle( mode, x, y, width, height )
	local vertices = {
		x,         y + height,
		x + width, y + height,
		x,         y,
		x + width, y + height,
		x + width, y,
		x,         y
	}
	polygon( mode, vertices )
end
