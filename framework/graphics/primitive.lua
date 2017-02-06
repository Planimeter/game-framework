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
	local defaultVBO     = framework.graphics._defaultVBO
	local pVertices      = ffi.new( "GLfloat[?]", #vertices, vertices )
	local size           = ffi.sizeof( pVertices )
	local shader         = framework.graphics.getShader()
	local vertex         = GL.glGetAttribLocation( shader, "vertex" )
	local texCoord       = GL.glGetAttribLocation( shader, "texcoord" )
	local defaultTexture = framework.graphics.getDefaultTexture()
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, defaultVBO[0] )
	GL.glBufferData( GL.GL_ARRAY_BUFFER, size, pVertices, GL.GL_STREAM_DRAW )
	GL.glVertexAttribPointer( vertex, 2, GL.GL_FLOAT, 0, 0, nil )
	GL.glDisableVertexAttribArray( texCoord )
	framework.graphics.updateTransformations()
	GL.glBindTexture( GL.GL_TEXTURE_2D, defaultTexture[0] )
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

function setLineWidth( lineWidth )
	_lineWidth = lineWidth
end

function getLineWidth()
	return _lineWidth
end

function line( ... )
	local points   = { ... }
	local vertices = {}
	for i = 1, #points, 2 do
		local x1, y1 = points[ i ],     points[ i + 1 ]
		local x2, y2 = points[ i + 2 ], points[ i + 3 ]
	end
	polygon( "fill", vertices )
end
