--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )
local ffi = require( "ffi" )

local framework      = framework
local collectgarbage = collectgarbage

module( "framework.event" )

function poll()
	event = event or SDL.SDL_Event()
	return SDL.SDL_PollEvent( event ) ~= 0 and event or nil
end

function handle( e )
	if ( e.type == ffi.C.SDL_APP_LOWMEMORY ) then
		framework.lowmemory()
		collectgarbage()
	elseif ( e.type == ffi.C.SDL_WINDOWEVENT ) then
		windowevent( e.window )
	end
end

function windowevent( window )
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
