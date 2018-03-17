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

function cubemap:cubemap( filenames )
	self.images = ffi.new( "ILuint[6]" )
	IL.ilGenImages( 6, self.images )
	IL.ilBindImage( self.images[0] )

	self.texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, self.texture )
	GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )

	local buffer, length = framework.filesystem.read( filename )
	if ( buffer == nil ) then
		error( length, 3 )
	end
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
	GL.glTexImage2D(
		GL.GL_TEXTURE_2D,
		0,
		GL.GL_RGBA,
		width,
		height,
		0,
		GL.GL_RGBA,
		GL.GL_UNSIGNED_BYTE,
		pixels
	)

	setproxy( self )
end

function cubemap:__gc()
	GL.glDeleteTextures( 1, self.texture )
	IL.ilDeleteImages( 6, self.images )
end
