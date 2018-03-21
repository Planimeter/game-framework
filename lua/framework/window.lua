--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "sdl" )
local ffi = require( "ffi" )
local bit = require( "bit" )
local GL  = require( "opengl" )

local pairs     = pairs
local framework = framework

module( "framework.window" )

function createWindow( title, x, y, width, height, flags, glattrs )
	x = x or SDL.SDL_WINDOWPOS_UNDEFINED
	y = y or SDL.SDL_WINDOWPOS_UNDEFINED

	local defaultFlags = bit.bor(
		ffi.C.SDL_WINDOW_OPENGL,
		ffi.C.SDL_WINDOW_ALLOW_HIGHDPI
	)
	flags = bit.bor( defaultFlags, flags or 0 )

	SDL.SDL_InitSubSystem( SDL.SDL_INIT_VIDEO )
	SDL.SDL_GL_SetAttribute(
		ffi.C.SDL_GL_CONTEXT_PROFILE_MASK,
		ffi.C.SDL_GL_CONTEXT_PROFILE_CORE
	)

	for k, v in pairs( glattrs ) do
		SDL.SDL_GL_SetAttribute( ffi.C[ k ], v )
	end

	_window  = SDL.SDL_CreateWindow( title, x, y, width, height, flags )
	_context = SDL.SDL_GL_CreateContext( _window )

	width, height = framework.graphics.getSize()
	GL.glViewport( 0, 0, width, height )
	GL.glEnable( GL.GL_DEPTH_TEST )
	GL.glDepthFunc( GL.GL_LEQUAL )
	GL.glEnable( GL.GL_BLEND )
	GL.glBlendFunc( GL.GL_SRC_ALPHA, GL.GL_ONE_MINUS_SRC_ALPHA )
	GL.glEnable( GL.GL_TEXTURE_CUBE_MAP_SEAMLESS )

	if ( glattrs.SDL_GL_MULTISAMPLESAMPLES > 0 ) then
		GL.glEnable( GL.GL_MULTISAMPLE )
	end

	framework.graphics.createDefaultVAO()
	framework.graphics.createDefaultVBO()
	framework.graphics.setShader( "default2d" )

	local font = framework.graphics.newFont( "fonts/Vera.ttf" )
	framework.graphics.setFont( font )
end

function getPixelScale()
	local gw = framework.graphics.getSize()
	local ww = getSize()
	return gw / ww
end

function getSize()
	local width  = ffi.new( "int[1]" )
	local height = ffi.new( "int[1]" )
	SDL.SDL_GetWindowSize( framework.window._window, width, height )
	return width[0], height[0]
end

function resize( width, height )
	GL.glViewport( 0, 0, width, height )
	framework.graphics.setOrthographicProjection( width, height )
end

local fullScreenFlags = {
	exclusive = ffi.C.SDL_WINDOW_FULLSCREEN,
	desktop   = ffi.C.SDL_WINDOW_FULLSCREEN_DESKTOP
}

function setFullscreen( fullscreen, type )
	type = type or "desktop"
	return SDL.SDL_SetWindowFullscreen(
		framework.window._window, fullscreen and fullScreenFlags[ type ] or 0
	) == 0
end

function swap()
	SDL.SDL_GL_SwapWindow( _window )
	framework.graphics._drawCalls = 0
end
