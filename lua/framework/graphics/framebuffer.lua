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

function framebuffer:framebuffer( width, height )
	if ( not width and not height ) then
		width, height = framework.graphics.getSize()
	end

	self.width  = width
	self.height = height

	self.framebuffer = ffi.new( "GLuint[1]" )
	GL.glGenFramebuffers( 1, self.framebuffer )
	framework.graphics.setFramebuffer( self )

	self.texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, self.texture )
	GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )

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
		nil
	)

	GL.glFramebufferTexture2D(
		GL.GL_FRAMEBUFFER,
		GL.GL_COLOR_ATTACHMENT0,
		GL.GL_TEXTURE_2D,
		self.texture[0],
		0
	)

	framework.graphics.clear()
	framework.graphics.setFramebuffer()

	setproxy( self )
end

function framebuffer:draw( x, y, r, sx, sy, ox, oy, kx, ky )
	framework.graphics.setMatrixMode( "projection" )
	framework.graphics.push()
		local mat4          = framework.graphics.getTransformation()
		local width, height = framework.graphics.getSize()
		kazmath.kmMat4OrthographicProjection(
			mat4, 0, width, 0, height, -1.0, 1.0
		)
		image.draw( self, x, y, r, sx, sy, ox, oy, kx, ky )
	framework.graphics.pop()
	framework.graphics.setMatrixMode( "model" )
end

function framebuffer:__gc()
	GL.glDeleteTextures( 1, self.texture )
	GL.glDeleteFramebuffers( 1, self.framebuffer )
end
