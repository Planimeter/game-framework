--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )
local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )

local framework = framework
local print     = print

module( "framework.window" )

function createWindow( title, x, y, width, height )
	x = x or SDL.SDL_WINDOWPOS_UNDEFINED
	y = y or SDL.SDL_WINDOWPOS_UNDEFINED

	SDL.SDL_InitSubSystem( SDL.SDL_INIT_VIDEO )
	SDL.SDL_GL_SetAttribute(
		ffi.C.SDL_GL_CONTEXT_PROFILE_MASK,
		ffi.C.SDL_GL_CONTEXT_PROFILE_CORE
	)

	local flags = ffi.C.SDL_WINDOW_OPENGL
	window      = SDL.SDL_CreateWindow( title, x, y, width, height, flags )
	context     = SDL.SDL_GL_CreateContext( window )

	GL.glViewport( 0, 0, width, height )
end

function resize( width, height )
	GL.glViewport( 0, 0, width, height )
end

function setTitle( title )
	SDL.SDL_SetWindowTitle( window, title )
end

function swap()
	SDL.SDL_GL_SwapWindow( window )
end
