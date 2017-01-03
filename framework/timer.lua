--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )

module( "framework.timer" )

function sleep( seconds )
	SDL.SDL_Delay( seconds * 1000 )
end

function getTime()
	return SDL.SDL_GetTicks()
end
