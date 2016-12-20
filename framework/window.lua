--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )
local GL  = require( "lib.opengl" )
local ffi = require( "ffi" )

module( "framework.window" )

function createWindow( title, x, y, width, height )
	x = x or SDL.SDL_WINDOWPOS_UNDEFINED
	y = y or SDL.SDL_WINDOWPOS_UNDEFINED

	local flags = ffi.C.SDL_WINDOW_OPENGL
	window      = SDL.SDL_CreateWindow( title, x, y, width, height, flags )
	context     = SDL.SDL_GL_CreateContext( window )

	GL.glViewport( 0, 0, width, height )
	GL.glOrtho( 0, width, height, 0, -1, 1 )
end

function swap()
	SDL.SDL_GL_SwapWindow( window )
end
