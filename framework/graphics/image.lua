--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local IL  = require( "devil" )
require( "class" )
local ffi = require( "ffi" )
local GL  = require( "opengl" )

IL.ilInit()

class( "framework.graphics.image" )

local image = framework.graphics.image

function image:image( filename )
	self.image = ffi.new( "ILuint[1]" )
	IL.ilGenImages( 1, self.image )
	IL.ilBindImage( self.image[0] )

	self.texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, self.texture )
	GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )

	local buffer, length = framework.filesystem.read( filename )
	IL.ilLoadL( IL.IL_TYPE_UNKNOWN, buffer, length )
	IL.ilConvertImage( IL.IL_RGBA, IL.IL_UNSIGNED_BYTE )
	local width  = IL.ilGetInteger( IL.IL_IMAGE_WIDTH )
	local height = IL.ilGetInteger( IL.IL_IMAGE_HEIGHT )
	local pixels = IL.ilGetData()
	self.width   = width
	self.height  = height
	self.pixels  = pixels

	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_BASE_LEVEL, 0 )
	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAX_LEVEL, 0 )
	GL.glTexImage2D( GL.GL_TEXTURE_2D, 0, GL.GL_RGBA, width, height, 0, GL.GL_RGBA, GL.GL_UNSIGNED_BYTE, pixels )

	setproxy( self )
end

function image:draw( x, y, r, sx, sy, ox, oy, kx, ky )
	local width    = self.width
	local height   = self.height
	local vertices = {
		-- vertex              -- texcoord
		x,         y + height, 0.0, 1.0,
		x + width, y + height, 1.0, 1.0,
		x,         y,          0.0, 0.0,
		x + width, y + height, 1.0, 1.0,
		x + width, y,          1.0, 0.0,
		x,         y,          0.0, 0.0
	}
	local pVertices = ffi.new( "GLfloat[?]", #vertices, vertices )
	local size      = ffi.sizeof( pVertices )
	local shader    = framework.graphics.getShader()
	local vertex    = GL.glGetAttribLocation( shader, "vertex" )
	local stride    = 4 * ffi.sizeof( "GLfloat" )
	local texcoord  = GL.glGetAttribLocation( shader, "texcoord" )
	local pointer   = ffi.cast( "GLvoid *", 2 * ffi.sizeof( "GLfloat" ) )
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, framework.graphics.defaultVBO[0] )
	GL.glBufferData( GL.GL_ARRAY_BUFFER, size, pVertices, GL.GL_STREAM_DRAW )
	GL.glVertexAttribPointer( vertex, 2, GL.GL_FLOAT, 0, stride, nil )
	GL.glEnableVertexAttribArray( texcoord )
	GL.glVertexAttribPointer( texcoord, 2, GL.GL_FLOAT, 0, stride, pointer )
	framework.graphics.updateTransform()
	GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )
	framework.graphics.drawArrays( GL.GL_TRIANGLES, 0, #vertices / 2 )
end

function image:__gc()
	GL.glDeleteTextures( 1, self.texture )
	IL.ilDeleteImages( 1, self.image )
end
