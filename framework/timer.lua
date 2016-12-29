--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )

module( "framework.timer" )

function sleep( seconds )
	if ( seconds > 0 ) then
		SDL.SDL_Delay( seconds * 1000 )
	end
end

function getTime()
	return SDL.SDL_GetTicks()
end
