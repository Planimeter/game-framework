--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.filesystem" )
require( "framework.event" )
local ffi = require( "ffi" )

local framework      = framework
local require        = require
local pairs          = pairs
local collectgarbage = collectgarbage

module( "framework" )

function main()
	init()
	load()

	while ( true ) do
		local e = nil
		repeat
			e = framework.event.poll()
			if ( e ) then
				if ( e.type == ffi.C.SDL_QUIT or
				     e.type == ffi.C.SDL_APP_TERMINATING ) then
					if ( quit() ) then return end
				end

				event( e )
			end
		until ( e == nil )

		update()

		if ( draw ) then
			framework.graphics.clear()
			draw()
			framework.window.swap()
		end
	end
end

function init()
	local c = {
		modules = {
			window   = true,
			graphics = true
		},
		window = {
			title  = "",
			x      = nil,
			y      = nil,
			width  = 800,
			height = 600
		}
	}

	if ( framework.filesystem.exists( "conf.lua" ) ) then
		require( "conf" )
	end

	if ( framework.conf ) then
		framework.conf( c )
	end

	for k in pairs( c.modules ) do
		require( "framework." .. k )
	end

	if ( c.modules.window ) then
		local title  = c.window.title
		local x      = c.window.x
		local y      = c.window.y
		local width  = c.window.width
		local height = c.window.height
		framework.window.createWindow( title, x, y, width, height )
	end

	if ( framework.filesystem.exists( "main.lua" ) ) then
		require( "main" )
	end
end

function load()
end

function event( e )
	if ( e.type == ffi.C.SDL_APP_LOWMEMORY ) then
		lowmemory()
		collectgarbage()
	elseif ( e.type == ffi.C.SDL_WINDOWEVENT ) then
		windowevent( e.window )
	end
end

function lowmemory()
end

function windowevent( window )
	if ( window.event == ffi.C.SDL_WINDOWEVENT_SHOWN ) then
		visible( true )
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_HIDDEN ) then
		visible( false )
	elseif ( window.event == ffi.C.SDL_WINDOWEVENT_MOVED ) then
		move( window.data1, window.data2 )
	elseif ( e.event == ffi.C.SDL_WINDOWEVENT_RESIZED ) then
		resize( window.data1, window.data2 )
	elseif ( e.event == ffi.C.SDL_WINDOWEVENT_SIZE_CHANGED ) then
		framework.window.resize( window.data1, window.data2 )
	elseif ( e.event == ffi.C.SDL_WINDOWEVENT_MINIMIZED ) then
		minimize()
	elseif ( e.event == ffi.C.SDL_WINDOWEVENT_MAXIMIZED ) then
		maximize()
	elseif ( e.event == ffi.C.SDL_WINDOWEVENT_RESTORED ) then
		restore()
	elseif ( e.event == ffi.C.SDL_WINDOWEVENT_ENTER ) then
		mousefocus( true )
	elseif ( e.event == ffi.C.SDL_WINDOWEVENT_LEAVE ) then
		mousefocus( false )
	elseif ( e.event == ffi.C.SDL_WINDOWEVENT_FOCUS_GAINED ) then
		focus( true )
	elseif ( e.event == ffi.C.SDL_WINDOWEVENT_FOCUS_LOST ) then
		focus( false )
	end
end

function visible( visible )
end

function move( x, y )
end

function resize( width, height )
end

function minimize()
end

function maximize()
end

function restore()
end

function mousefocus( focus )
end

function focus( focus )
end

function update( dt )
end

function draw()
end

function quit()
end

main()
