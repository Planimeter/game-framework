--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.graphics.opengl" )
require( "framework.graphics.primitive" )
require( "framework.graphics.shader" )
require( "framework.graphics.transformation" )
local GL  = require( "opengl" )
local ffi = require( "ffi" )
local SDL = require( "sdl" )

local framework = framework
local require   = require
local tostring  = tostring

module( "framework.graphics" )

function draw( drawable, x, y, r, sx, sy, ox, oy, kx, ky )
	x = x or 0
	y = y or 0
	drawable:draw( x, y, r, sx, sy, ox, oy, kx, ky )
end

function getFont()
	return _font
end

function getFramebuffer()
	return _framebuffer
end

function getSize()
	local width  = ffi.new( "int[1]" )
	local height = ffi.new( "int[1]" )
	SDL.SDL_GL_GetDrawableSize( framework.window.window, width, height )
	return width[0], height[0]
end

function newFont( filename, size )
	require( "framework.graphics.font" )
	local font = framework.graphics.font
	return font( filename, size )
end

function newFramebuffer( width, height )
	require( "framework.graphics.framebuffer" )
	local framebuffer = framework.graphics.framebuffer
	return framebuffer( width, height )
end

function newImage( filename )
	require( "framework.graphics.image" )
	local image = framework.graphics.image
	return image( filename )
end

function newModel( filename )
	require( "framework.graphics.model" )
	local model = framework.graphics.model
	return model( filename )
end

function print( text, x, y, r, sx, sy, ox, oy, kx, ky )
	text = tostring( text )
	x = x or 0
	y = y or 0
	getFont():print( text, x, y, r, sx, sy, ox, oy, kx, ky )
end

function setFont( font )
	_font = font
end

function setFramebuffer( framebuffer )
	if ( framebuffer and framebuffer.framebuffer ) then
		GL.glBindFramebuffer( GL.GL_FRAMEBUFFER, framebuffer.framebuffer[0] )
		local width, height = framebuffer.width, framebuffer.height
		GL.glViewport( 0, 0, width, height )
		framework.graphics.push()
	else
		framework.graphics.pop()
		GL.glBindFramebuffer( GL.GL_FRAMEBUFFER, 0 )
	end

	_framebuffer = framebuffer
end

function setVSync( vsync )
	SDL.SDL_GL_SetSwapInterval( vsync and 1 or 0 )
end

function clear()
	GL.glClear( GL.GL_COLOR_BUFFER_BIT )
end
