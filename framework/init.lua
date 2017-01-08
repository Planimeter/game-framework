--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

package.path = string.gsub( package.path, "./?.lua;", "./?.lua;./?/init.lua;" )

local framework = {}
_G.framework    = framework

local arg     = arg
local require = require
local pairs   = pairs

module( "framework" )

function main()
	init()
	load( arg )

	require( "framework.event" )
	local ffi = require( "ffi" )

	while ( true ) do
		local e = nil
		repeat
			e = framework.event.poll()
			if ( e ) then
				if ( e.type == ffi.C.SDL_QUIT or
				     e.type == ffi.C.SDL_APP_TERMINATING ) then
					if ( quit() ) then return end
				end

				framework.event.handle( e )
			end
		until ( e == nil )

		local dt = 0
		if ( framework.timer ) then
			dt = framework.timer.step()
		end

		update( dt )

		if ( framework.graphics ) then
			framework.graphics.clear()
			draw()
			framework.window.swap()
		end

		if ( framework.timer ) then
			framework.timer.sleep( 0.001 )
		end
	end
end

function init()
	require( "framework.filesystem" )
	framework.filesystem.init( arg[ 1 ] )
	framework.filesystem.mount( ".", nil, false )

	local c = {
		modules = {
			timer    = true,
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

	if ( framework.filesystem.isFile( "conf.lua" ) ) then
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

	if ( framework.filesystem.isFile( "main.lua" ) ) then
		require( "main" )
	end
end

function load()
end

function lowmemory()
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

function keypressed( key, scancode, isrepeat )
end

function keyreleased( key, scancode )
end

function textedited( text, start, length )
end

function textinput( text )
end

function mousemoved( x, y, dx, dy, istouch )
end

function mousepressed( x, y, button, istouch )
end

function mousereleased( x, y, button, istouch )
end

function wheelmoved( x, y )
end

function update( dt )
end

function draw()
end

function quit()
	return true
end

main()
