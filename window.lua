--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )

module( "window" )

function createWindow()
	window = SDL.SDL_CreateWindow()
end
