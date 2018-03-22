--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
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
	local position       = GL.glGetAttribLocation( shader, "position" )
	local texcoord       = GL.glGetAttribLocation( shader, "texcoord" )
	local defaultTexture = framework.graphics.getDefaultTexture()
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, defaultVBO[0] )
	GL.glBufferData( GL.GL_ARRAY_BUFFER, size, pVertices, GL.GL_STREAM_DRAW )
	GL.glVertexAttribPointer( position, 2, GL.GL_FLOAT, 0, 0, nil )
	GL.glDisableVertexAttribArray( texcoord )
	framework.graphics.updateTransformations()
	GL.glBindTexture( GL.GL_TEXTURE_2D, defaultTexture[0] )
	framework.graphics.drawArrays( mode, 0, #vertices / 2 )
end

local function roundedRectangle( mode, x, y, width, height, r )
	local segments = math.floor( r * math.pi * 2 / 4 )
	local vertices = {
		x + width  / 2,
		y + height / 2
	}
	local angleDelta = 1 / segments * math.pi / 2
	local cornerVertices = {
		x + width - r, y + height - r,
		x + r,         y + height - r,
		x + r,         y + r,
		x + width - r, y + r
	}
	for corner = 0, 3 do
		local angle = corner * math.pi / 2
		local cornerCenterX = cornerVertices[ corner * 2 + 1 ]
		local cornerCenterY = cornerVertices[ corner * 2 + 2 ]
		for i = 1, segments do
			vertices[ #vertices+1 ] = cornerCenterX + math.cos( angle ) * r
			vertices[ #vertices+1 ] = cornerCenterY + math.sin( angle ) * r
			angle = angle + angleDelta
		end
	end
	vertices[ #vertices+1 ] = x + width
	vertices[ #vertices+1 ] = y + height - r
	mode = mode == "fill" and GL.GL_TRIANGLE_FAN or mode
	polygon( mode, vertices )
end

function rectangle( mode, x, y, width, height, r )
	if ( r and r > 0 ) then
		roundedRectangle( mode, x, y, width, height, r )
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

function skybox( cubemap )
	local vertices = {
		-1.0,  1.0, -1.0,
		-1.0, -1.0, -1.0,
		 1.0, -1.0, -1.0,
		 1.0, -1.0, -1.0,
		 1.0,  1.0, -1.0,
		-1.0,  1.0, -1.0,

		-1.0, -1.0,  1.0,
		-1.0, -1.0, -1.0,
		-1.0,  1.0, -1.0,
		-1.0,  1.0, -1.0,
		-1.0,  1.0,  1.0,
		-1.0, -1.0,  1.0,

		 1.0, -1.0, -1.0,
		 1.0, -1.0,  1.0,
		 1.0,  1.0,  1.0,
		 1.0,  1.0,  1.0,
		 1.0,  1.0, -1.0,
		 1.0, -1.0, -1.0,

		-1.0, -1.0,  1.0,
		-1.0,  1.0,  1.0,
		 1.0,  1.0,  1.0,
		 1.0,  1.0,  1.0,
		 1.0, -1.0,  1.0,
		-1.0, -1.0,  1.0,

		-1.0,  1.0, -1.0,
		 1.0,  1.0, -1.0,
		 1.0,  1.0,  1.0,
		 1.0,  1.0,  1.0,
		-1.0,  1.0,  1.0,
		-1.0,  1.0, -1.0,

		-1.0, -1.0, -1.0,
		-1.0, -1.0,  1.0,
		 1.0, -1.0, -1.0,
		 1.0, -1.0, -1.0,
		-1.0, -1.0,  1.0,
		 1.0, -1.0,  1.0
	}
	local defaultVBO     = framework.graphics._defaultVBO
	local pVertices      = ffi.new( "GLfloat[?]", #vertices, vertices )
	local size           = ffi.sizeof( pVertices )
	local shader         = framework.graphics.getShader()
	local position       = GL.glGetAttribLocation( shader, "position" )
	local defaultTexture = framework.graphics.getDefaultTexture()
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, defaultVBO[0] )
	GL.glBufferData( GL.GL_ARRAY_BUFFER, size, pVertices, GL.GL_STREAM_DRAW )
	GL.glVertexAttribPointer( position, 3, GL.GL_FLOAT, 0, 0, nil )
	framework.graphics.updateTransformations()
	GL.glBindTexture( GL.GL_TEXTURE_CUBE_MAP, cubemap.texture[0] )
	GL.glDepthMask( GL.GL_FALSE )
	framework.graphics.drawArrays( GL.GL_TRIANGLES, 0, #vertices / 3 )
	GL.glDepthMask( GL.GL_TRUE )
end
