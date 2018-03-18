--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local IL  = require( "devil" )
local ffi = require( "ffi" )
local GL  = require( "opengl" )

IL.ilInit()

class( "framework.graphics.cubemap" )

local cubemap = framework.graphics.cubemap

local faces = {
	{ "right",  GL.GL_TEXTURE_CUBE_MAP_POSITIVE_X },
	{ "left",   GL.GL_TEXTURE_CUBE_MAP_NEGATIVE_X },
	{ "top",    GL.GL_TEXTURE_CUBE_MAP_POSITIVE_Y },
	{ "bottom", GL.GL_TEXTURE_CUBE_MAP_NEGATIVE_Y },
	{ "front",  GL.GL_TEXTURE_CUBE_MAP_POSITIVE_Z },
	{ "back",   GL.GL_TEXTURE_CUBE_MAP_NEGATIVE_Z }
}

function cubemap:cubemap( filenames )
	self.images = ffi.new( "ILuint[6]" )
	IL.ilGenImages( 6, self.images )

	self.texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, self.texture )
	GL.glBindTexture( GL.GL_TEXTURE_CUBE_MAP, self.texture[0] )

	GL.glTexParameteri( GL.GL_TEXTURE_CUBE_MAP, GL.GL_TEXTURE_BASE_LEVEL, 0 )
	GL.glTexParameteri( GL.GL_TEXTURE_CUBE_MAP, GL.GL_TEXTURE_MAX_LEVEL, 0 )

	self.width  = {}
	self.height = {}
	self.pixels = {}

	for i = 1, #faces do
		IL.ilBindImage( self.images[i - 1] )

		local face   = faces[ i ]
		local k      =  face[ 1 ]
		local target =  face[ 2 ]
		local buffer, length = framework.filesystem.read( filenames[ k ] )
		if ( buffer == nil ) then
			error( length, 3 )
		end
		IL.ilLoadL( IL.IL_TYPE_UNKNOWN, buffer, length )
		IL.ilConvertImage( IL.IL_RGBA, IL.IL_UNSIGNED_BYTE )
		local width      = IL.ilGetInteger( IL.IL_IMAGE_WIDTH )
		local height     = IL.ilGetInteger( IL.IL_IMAGE_HEIGHT )
		local pixels     = IL.ilGetData()
		self.width[ i ]  = width
		self.height[ i ] = height
		self.pixels[ i ] = pixels

		GL.glTexImage2D(
			target,
			0,
			GL.GL_RGBA,
			width,
			height,
			0,
			GL.GL_RGBA,
			GL.GL_UNSIGNED_BYTE,
			pixels
		)
	end

	setproxy( self )
end

function cubemap:__gc()
	GL.glDeleteTextures( 1, self.texture )
	IL.ilDeleteImages( 6, self.images )
end
