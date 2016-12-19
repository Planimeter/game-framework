--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )
local ffi = require( "ffi" )

module( "framework.window" )

function createWindow( title, x, y, width, height )
	SDL.SDL_InitSubSystem( SDL.SDL_INIT_VIDEO )

	local flags = ffi.C.SDL_WINDOW_OPENGL
	window = SDL.SDL_CreateWindow(
		title,
		x or SDL.SDL_WINDOWPOS_UNDEFINED,
		y or SDL.SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		flags
	)
end
