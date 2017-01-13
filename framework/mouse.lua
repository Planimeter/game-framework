--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
local SDL = require( "sdl" )

module( "framework.mouse" )

function getPosition()
	local x = ffi.new( "int[1]" )
	local y = ffi.new( "int[1]" )
	SDL.SDL_GetMouseState( x, y )
	return x[0], y[0]
end

function setVisible( visible )
	SDL.SDL_ShowCursor( visible and SDL.SDL_ENABLE or SDL.SDL_DISABLE )
end
