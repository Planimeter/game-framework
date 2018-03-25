--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
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

function getSystemCursor( id )
	if ( id == "arrow" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_ARROW
	elseif ( id == "ibeam" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_IBEAM
	elseif ( id == "wait" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_WAIT
	elseif ( id == "crosshair" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_CROSSHAIR
	elseif ( id == "waitarrow" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_WAITARROW
	elseif ( id == "sizenwse" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_SIZENWSE
	elseif ( id == "sizenesw" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_SIZENESW
	elseif ( id == "sizewe" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_SIZEWE
	elseif ( id == "sizens" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_SIZENS
	elseif ( id == "sizeall" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_SIZEALL
	elseif ( id == "no" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_NO
	elseif ( id == "hand" ) then
		id = ffi.C.SDL_SYSTEM_CURSOR_HAND
	end
	return SDL.SDL_CreateSystemCursor( id )
end

function setCursor( cursor )
	SDL.SDL_SetCursor( cursor )
end

function setVisible( visible )
	SDL.SDL_ShowCursor( visible and SDL.SDL_ENABLE or SDL.SDL_DISABLE )
end
