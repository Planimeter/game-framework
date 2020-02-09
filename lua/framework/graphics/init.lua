--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.graphics.opengl" )
require( "framework.graphics.primitive" )
require( "framework.graphics.shader" )
require( "framework.graphics.transformation" )
local GL      = require( "opengl" )
local ffi     = require( "ffi" )
local SDL     = require( "sdl" )
local kazmath = require( "kazmath" )
local bit     = require( "bit" )

local unpack    = unpack
local framework = framework
local require   = require
local tostring  = tostring

module( "framework.graphics" )

_backgroundColor = _backgroundColor or { 0, 0, 0, 0 }

_viewport  = _viewport or {
	x      = 0,
	y      = 0,
	width  = 800,
	height = 600
}

function draw( drawable, x, y, r, sx, sy, ox, oy, kx, ky )
	x  = x  or 0
	y  = y  or 0
	r  = r  or 0
	sx = sx or 1
	sy = sy or sx
	ox = ox or 0
	oy = oy or 0
	kx = kx or 0
	ky = ky or 0
	drawable:draw( x, y, r, sx, sy, ox, oy, kx, ky )
end

function getBackgroundColor()
	return unpack( _backgroundColor )
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

function newFramebuffer( type, width, height )
	require( "framework.graphics.framebuffer" )
	local framebuffer = framework.graphics.framebuffer
	return framebuffer( type, width, height )
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

function newText( font, textstring )
	require( "framework.graphics.text" )
	local text = framework.graphics.text
	return text( font, textstring )
end

function newQuad( x, y, width, height, sw, sh )
	require( "framework.graphics.quad" )
	return quad( x, y, width, height, sw, sh )
end

function newSpriteBatch( image, maxSprites )
	require( "framework.graphics.spritebatch" )
	local spritebatch = framework.graphics.spritebatch
	return spritebatch( image, maxSprites )
end

function print( text, x, y, r, sx, sy, ox, oy, kx, ky )
	text = tostring( text )
	x = x or 0
	y = y or 0
	local font = getFont()
	font:print( text, x, y, r, sx, sy, ox, oy, kx, ky )
end

function setBackgroundColor( color )
	_backgroundColor[ 1 ] = color[ 1 ]
	_backgroundColor[ 2 ] = color[ 2 ]
	_backgroundColor[ 3 ] = color[ 3 ]
	_backgroundColor[ 4 ] = color[ 4 ]
end

function setFont( font )
	_font = font
end

function setFramebuffer( framebuffer )
	if ( framebuffer ) then
		GL.glBindFramebuffer( GL.GL_FRAMEBUFFER, framebuffer.framebuffer[0] )
		local mode = framework.graphics.getMatrixMode()
		framework.graphics.setMatrixMode( "projection" )
			local mat4   = framework.graphics.getTransformation()
			local width  = framebuffer.width
			local height = framebuffer.height
			kazmath.kmMat4OrthographicProjection(
				mat4, 0, width, 0, height, -1.0, 1.0
			)
		framework.graphics.setMatrixMode( mode )
		framework.graphics.updateTransformations()

		local dpiScale = framework.window.getPixelScale()
		setViewport( 0, 0, width * dpiScale, height * dpiScale )
	else
		GL.glBindFramebuffer( GL.GL_FRAMEBUFFER, 0 )
		framework.graphics.setOrthographicProjection( width, height )

		local width, height = getSize()
		setViewport( 0, 0, width, height )
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

function setScissor( x, y, width, height )
	if ( _framebuffer ~= nil ) then
		GL.glScissor( x, y, width, height )
	else
		GL.glScissor( x, _viewport.height - ( y + height ), width, height )
	end
end

function setViewport( x, y, width, height )
	GL.glViewport( x, y, width, height )
	_viewport.x      = x
	_viewport.y      = y
	_viewport.width  = width
	_viewport.height = height
end

function setVSync( vsync )
	SDL.SDL_GL_SetSwapInterval( vsync and 1 or 0 )
end

function clear( r, g, b, a )
	r = r or 0
	g = g or 0
	b = b or 0
	a = a or 0
	GL.glClearColor( r, g, b, a )
	GL.glClear( bit.bor( GL.GL_COLOR_BUFFER_BIT, GL.GL_DEPTH_BUFFER_BIT ) )
end
