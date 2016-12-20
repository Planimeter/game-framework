--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )
local ffi = require( "ffi" )

module( "framework.window" )

function createWindow( title, x, y, width, height )
	x = x or SDL.SDL_WINDOWPOS_UNDEFINED
	y = y or SDL.SDL_WINDOWPOS_UNDEFINED

	local flags = ffi.C.SDL_WINDOW_OPENGL
	window = SDL.SDL_CreateWindow( title, x, y, width, height, flags )
end

function swap()
	SDL.SDL_GL_SwapWindow( window )
end
