--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "sdl" )

local ipairs = ipairs

module( "framework.keyboard" )

function isPressed( ... )
	local state = SDL.SDL_GetKeyboardState( nil )
	for key in ipairs( { ... } ) do
		key = SDL.SDL_GetKeyFromName( key )
		key = SDL.SDL_GetScancodeFromKey( key )
		if ( state[ key ] ) then return true end
	end
	return false
end

function isScancodePressed( ... )
	local state = SDL.SDL_GetKeyboardState( nil )
	for key in ipairs( { ... } ) do
		key = SDL.SDL_GetScancodeFromName( key )
		if ( state[ key ] ) then return true end
	end
	return false
end
