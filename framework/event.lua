--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )
local ffi = require( "ffi" )

local framework      = framework
local collectgarbage = collectgarbage
local string         = string

module( "framework.event" )

function poll()
	event = event or SDL.SDL_Event()
	return SDL.SDL_PollEvent( event ) ~= 0 and event or nil
end

local function windowevent( window )
	if ( window.event == ffi.C.SDL_WINDOWEVENT_SHOWN ) then
		framework.visible( true )
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_HIDDEN ) then
		framework.visible( false )
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_MOVED ) then
		framework.move( window.data1, window.data2 )
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_RESIZED ) then
		framework.resize( window.data1, window.data2 )
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_SIZE_CHANGED ) then
		framework.window.resize( window.data1, window.data2 )
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_MINIMIZED ) then
		framework.minimize()
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_MAXIMIZED ) then
		framework.maximize()
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_RESTORED ) then
		framework.restore()
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_ENTER ) then
		framework.mousefocus( true )
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_LEAVE ) then
		framework.mousefocus( false )
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_FOCUS_GAINED ) then
		framework.focus( true )
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_FOCUS_LOST ) then
		framework.focus( false )
	end
end

function handle( e )
	if ( e.type == ffi.C.SDL_APP_LOWMEMORY ) then
		framework.lowmemory()
		collectgarbage()
		collectgarbage()
	elseif ( e.type == ffi.C.SDL_WINDOWEVENT ) then
		windowevent( e.window )
	elseif ( e.type == ffi.C.SDL_KEYDOWN ) then
		local key      = SDL.SDL_GetKeyName( e.key.keysym.sym )
		key            = ffi.string( key )
		key            = string.lower( key )
		local scancode = SDL.SDL_GetScancodeName( e.key.keysym.scancode )
		scancode       = ffi.string( scancode )
		scancode       = string.lower( scancode )
		local isrepeat = e.key[ "repeat" ] == 1 and true or false
		framework.keypressed( key, scancode, isrepeat )
	elseif ( e.type == ffi.C.SDL_KEYUP ) then
		local key      = SDL.SDL_GetKeyName( e.key.keysym.sym )
		key            = ffi.string( key )
		key            = string.lower( key )
		local scancode = SDL.SDL_GetScancodeName( e.key.keysym.scancode )
		scancode       = ffi.string( scancode )
		scancode       = string.lower( scancode )
		framework.keyreleased( key, scancode )
	end
end
