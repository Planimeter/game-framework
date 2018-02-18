--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local GL  = require( "opengl" )
local ffi = require( "ffi" )
local math = math

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

function rectangle( mode, x, y, width, height, cornerRadius )
	if ( cornerRadius and cornerRadius > 0 ) then
		local segmentsPerCorner = math.floor( cornerRadius * math.pi * 2 / 4 )
		local vertices = { x + width / 2, y + height / 2 }
		local angleDelta = 1 / segmentsPerCorner * math.pi / 2
		local cornerCenterVerts = {
			x + width - cornerRadius, y + height - cornerRadius,
			x + cornerRadius,         y + height - cornerRadius,
			x + cornerRadius,         y + cornerRadius,
			x + width - cornerRadius, y + cornerRadius
		}
		for corner=0, 3 do
			local angle = corner * math.pi / 2
			local cornerCenterX = cornerCenterVerts[ corner * 2 + 1 ]
			local cornerCenterY = cornerCenterVerts[ corner * 2 + 2 ]
			for s = 1, segmentsPerCorner do
				vertices[ #vertices+1 ] = cornerCenterX + math.cos( angle ) * cornerRadius
				vertices[ #vertices+1 ] = cornerCenterY + math.sin( angle ) * cornerRadius
				angle = angle + angleDelta
			end
		end
		vertices[ #vertices+1 ] = x + width
		vertices[ #vertices+1 ] = y + height - cornerRadius
		mode = mode == "fill" and GL.GL_TRIANGLE_FAN or mode
		polygon( mode, vertices )
		return
	end
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
