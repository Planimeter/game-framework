--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
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
local bit = require( "bit" )

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

function getPolygonMode()
	local mode = ffi.new( "GLint[1]" )
	GL.glGetIntegerv( GL.GL_POLYGON_MODE, mode )
	if ( mode[0] == GL.GL_LINE ) then
		return "line"
	elseif( mode[0] == GL.GL_FILL ) then
		return "fill"
	end
end

function getSize()
	local width  = ffi.new( "int[1]" )
	local height = ffi.new( "int[1]" )
	SDL.SDL_GL_GetDrawableSize( framework.window._window, width, height )
	return width[0], height[0]
end

function newCubemap( type, filenames )
	require( "framework.graphics.cubemap" )
	local cubemap = framework.graphics.cubemap
	return cubemap( type, filenames )
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

function newImage( filename, params )
	require( "framework.graphics.image" )
	local image = framework.graphics.image
	return image( filename, params )
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
	local font = getFont()
	font:print( text, x, y, r, sx, sy, ox, oy, kx, ky )
end

function setBackgroundColor( color )
	GL.glClearColor(
		( color[ 1 ] or 0 ) / 255,
		( color[ 2 ] or 0 ) / 255,
		( color[ 3 ] or 0 ) / 255,
		( color[ 4 ] or 0 )
	)
end

function setFont( font )
	_font = font
end

function setFramebuffer( framebuffer )
	if ( framebuffer ) then
		GL.glBindFramebuffer( GL.GL_FRAMEBUFFER, framebuffer.framebuffer[0] )
	else
		GL.glBindFramebuffer( GL.GL_FRAMEBUFFER, 0 )
	end

	_framebuffer = framebuffer
end

function setPolygonMode( mode )
	if ( mode == "line" ) then
		mode = GL.GL_LINE
	elseif ( mode == "fill" ) then
		mode = GL.GL_FILL
	end
	GL.glPolygonMode( GL.GL_FRONT_AND_BACK, mode )
end

function setVSync( vsync )
	SDL.SDL_GL_SetSwapInterval( vsync and 1 or 0 )
end

function clear()
	GL.glClear( bit.bor( GL.GL_COLOR_BUFFER_BIT, GL.GL_DEPTH_BUFFER_BIT ) )
end
