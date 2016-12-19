--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )

module( "framework.window" )

function createWindow( title, x, y, width, height )
	SDL.SDL_InitSubsystem( SDL.SDL_INIT_VIDEO )
	window = SDL.SDL_CreateWindow( title, x, y width, height, flags )
end
