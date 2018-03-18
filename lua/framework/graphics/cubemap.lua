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
	right  = GL.GL_TEXTURE_CUBE_MAP_POSITIVE_X,
	left   = GL.GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
	top    = GL.GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
	bottom = GL.GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
	front  = GL.GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
	back   = GL.GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
}

function cubemap:cubemap( filenames )
	self.images = ffi.new( "ILuint[?]", #filenames )
	IL.ilGenImages( #filenames, self.images )

	self.texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, self.texture )
	GL.glBindTexture( GL.GL_TEXTURE_CUBE_MAP, self.texture[0] )

	local mipmapLevels = #filenames / 6
	if ( mipmapLevels == 1 ) then
		GL.glTexParameteri( GL.GL_TEXTURE_CUBE_MAP, GL.GL_TEXTURE_MIN_FILTER, GL.GL_LINEAR )
		GL.glTexParameteri( GL.GL_TEXTURE_CUBE_MAP, GL.GL_TEXTURE_MAG_FILTER, GL.GL_LINEAR )
	else
		GL.glTexParameteri( GL.GL_TEXTURE_CUBE_MAP, GL.GL_TEXTURE_MIN_FILTER, GL.GL_LINEAR_MIPMAP_LINEAR )
		GL.glTexParameteri( GL.GL_TEXTURE_CUBE_MAP, GL.GL_TEXTURE_MAG_FILTER, GL.GL_LINEAR )
	end

	self.pixels = {}

	for i, face in ipairs( filenames ) do
		IL.ilBindImage( self.images[i - 1] )

		local target   = face[ 1 ]
		local filename = face[ 2 ]
		local level    = math.ceil( i / 6 ) - 1
		local buffer, length = framework.filesystem.read( filename )
		if ( buffer == nil ) then
			error( length, 3 )
		end
		IL.ilLoadL( IL.IL_TYPE_UNKNOWN, buffer, length )
		IL.ilConvertImage( IL.IL_RGBA, IL.IL_UNSIGNED_BYTE )
		local width      = IL.ilGetInteger( IL.IL_IMAGE_WIDTH )
		local height     = IL.ilGetInteger( IL.IL_IMAGE_HEIGHT )
		local pixels     = IL.ilGetData()
		self.pixels[ i ] = pixels

		GL.glTexImage2D(
			faces[ target ],
			level,
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
	IL.ilDeleteImages( #self.pixels, self.images )
end
