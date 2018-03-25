--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
require( "framework.graphics.image" )
local GL      = require( "opengl" )
local ffi     = require( "ffi" )
local kazmath = require( "kazmath" )

local image = framework.graphics.image

class( "framework.graphics.framebuffer" )

local framebuffer = framework.graphics.framebuffer

function framebuffer:framebuffer( type, width, height )
	local format     = GL.GL_RGBA
	local dataType   = GL.GL_UNSIGNED_BYTE
	local attachment = GL.GL_COLOR_ATTACHMENT0
	if ( type == "depth" ) then
		format     = GL.GL_DEPTH_COMPONENT
		dataType   = GL.GL_FLOAT
		attachment = GL.GL_DEPTH_ATTACHMENT
	end

	if ( not width and not height ) then
		width, height = framework.graphics.getSize()
	end

	self.width  = width
	self.height = height

	self.framebuffer = ffi.new( "GLuint[1]" )
	GL.glGenFramebuffers( 1, self.framebuffer )
	local framebuffer = framework.graphics.getFramebuffer()
	framework.graphics.setFramebuffer( self )

	self.texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, self.texture )
	GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )

	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_BASE_LEVEL, 0 )
	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAX_LEVEL, 0 )
	GL.glTexImage2D(
		GL.GL_TEXTURE_2D,
		0,
		format,
		width,
		height,
		0,
		format,
		dataType,
		nil
	)

	if ( type == "depth" ) then
		GL.glDrawBuffer( GL.GL_NONE )
		GL.glReadBuffer( GL.GL_NONE )
	end

	GL.glFramebufferTexture2D(
		GL.GL_FRAMEBUFFER,
		attachment,
		GL.GL_TEXTURE_2D,
		self.texture[0],
		0
	)

	framework.graphics.clear()
	framework.graphics.setFramebuffer( framebuffer )

	setproxy( self )
end

function framebuffer:draw( x, y, r, sx, sy, ox, oy, kx, ky )
	image.draw( self, x, y, r, sx, sy, ox, oy, kx, ky )
end

function framebuffer:__gc()
	GL.glDeleteTextures( 1, self.texture )
	GL.glDeleteFramebuffers( 1, self.framebuffer )
end
