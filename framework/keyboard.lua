--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )

module( "framework.keyboard" )

function setTextInput( enable )
	if ( enable ) then
		SDL.SDL_StartTextInput()
	else
		SDL.SDL_StopTextInput()
	end
end
