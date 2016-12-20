--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )

module( "framework.event" )

function poll()
	event = event or SDL.SDL_Event()
	return SDL.SDL_PollEvent( event ) ~= 0 and event
end
