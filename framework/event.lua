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
	elseif ( e.type == ffi.C.SDL_TEXTEDITING ) then
		framework.textedited( e.edit.text, e.edit.start, e.edit.length )
	elseif ( e.type == ffi.C.SDL_TEXTINPUT ) then
		framework.textinput( e.text.text )
	elseif ( e.type == ffi.C.SDL_MOUSEMOTION ) then
		local x       = e.motion.x
		local y       = e.motion.y
		local dx      = e.motion.xrel
		local dy      = e.motion.yrel
		local istouch = e.motion.which == -1
		framework.mousemoved( x, y, dx, dy, istouch )
	elseif ( e.type == ffi.C.SDL_MOUSEBUTTONDOWN ) then
		local x       = e.button.x
		local y       = e.button.y
		local button  = e.button.button
		if ( button == 2 ) then
			button = 3
		elseif ( button == 3 ) then
			button = 2
		end
		local istouch = e.button.which == -1
		framework.mousepressed( x, y, button, istouch )
	elseif ( e.type == ffi.C.SDL_MOUSEBUTTONUP ) then
		local x       = e.button.x
		local y       = e.button.y
		local button  = e.button.button
		if ( button == 2 ) then
			button = 3
		elseif ( button == 3 ) then
			button = 2
		end
		local istouch = e.button.which == -1
		framework.mousereleased( x, y, button, istouch )
	elseif ( e.type == ffi.C.SDL_MOUSEWHEEL ) then
		framework.wheelmoved( e.wheel.x, e.wheel.y )
	elseif ( e.type == ffi.C.SDL_JOYAXISMOTION ) then
	elseif ( e.type == ffi.C.SDL_JOYBALLMOTION ) then
	elseif ( e.type == ffi.C.SDL_JOYHATMOTION ) then
	elseif ( e.type == ffi.C.SDL_JOYBUTTONDOWN ) then
	elseif ( e.type == ffi.C.SDL_JOYBUTTONUP ) then
	elseif ( e.type == ffi.C.SDL_JOYDEVICEADDED ) then
	elseif ( e.type == ffi.C.SDL_JOYDEVICEREMOVED ) then
	elseif ( e.type == ffi.C.SDL_CONTROLLERAXISMOTION ) then
	elseif ( e.type == ffi.C.SDL_CONTROLLERBUTTONDOWN ) then
	elseif ( e.type == ffi.C.SDL_CONTROLLERBUTTONUP ) then
	elseif ( e.type == ffi.C.SDL_CONTROLLERDEVICEADDED ) then
	elseif ( e.type == ffi.C.SDL_CONTROLLERDEVICEREMOVED ) then
	elseif ( e.type == ffi.C.SDL_CONTROLLERDEVICEREMAPPED ) then
	elseif ( e.type == ffi.C.SDL_FINGERDOWN ) then
	elseif ( e.type == ffi.C.SDL_FINGERUP ) then
	elseif ( e.type == ffi.C.SDL_FINGERMOTION ) then
	elseif ( e.type == ffi.C.SDL_DOLLARGESTURE ) then
	elseif ( e.type == ffi.C.SDL_DOLLARRECORD ) then
	elseif ( e.type == ffi.C.SDL_MULTIGESTURE ) then
	elseif ( e.type == ffi.C.SDL_CLIPBOARDUPDATE ) then
	elseif ( e.type == ffi.C.SDL_DROPFILE ) then
	elseif ( e.type == ffi.C.SDL_DROPTEXT ) then
	elseif ( e.type == ffi.C.SDL_DROPBEGIN ) then
	elseif ( e.type == ffi.C.SDL_DROPCOMPLETE ) then
	elseif ( e.type == ffi.C.SDL_AUDIODEVICEADDED ) then
	elseif ( e.type == ffi.C.SDL_AUDIODEVICEREMOVED ) then
	end
end
