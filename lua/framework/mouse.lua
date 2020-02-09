--=========== Copyright © 2020, Planimeter, All rights reserved. ===========--
--
-- Purpose:
--
--==========================================================================--

local ffi = require( "ffi" )
local SDL = require( "sdl" )

local framework = framework

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

function isVisible()
	return SDL.SDL_ShowCursor( -1 ) == 1
end

function setCursor( cursor )
	if ( cursor ) then
		SDL.SDL_SetCursor( cursor )
	else
		SDL.SDL_SetCursor( SDL.SDL_GetDefaultCursor() )
	end
end

function setPosition( x, y )
	SDL.SDL_WarpMouseInWindow( framework.window._window, x, y )
end

function setVisible( visible )
	SDL.SDL_ShowCursor( visible and 1 or 0 )
end
