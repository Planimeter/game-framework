--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )

module( "framework.mouse" )

function setVisible( visible )
	SDL.SDL_ShowCursor( visible and SDL.SDL_ENABLE or SDL.SDL_DISABLE )
end
