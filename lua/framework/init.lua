--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi       = require( "ffi" )

local execdir   = "./"
local gsub      = string.gsub
local gamedir   = arg[ 2 ]

local framework = {}
_G.framework    = framework

if ( jit.os == "Windows" ) then
	execdir = ".\\"

	-- Declare `SetDllDirectoryA`
	ffi.cdef[[
		int __stdcall SetDllDirectoryA(const char* lpPathName);
	]]

	-- Get working directory
	execdir           = gsub( arg[ 0 ], "\\lua\\framework\\init%.lua$", "\\" )
	framework.execdir = execdir

	-- Set DLL directory
	ffi.C.SetDllDirectoryA( execdir .. "bin" )

	-- Add `lib'
	package.path      = package.path  .. execdir .. "lib\\?.lua;"
	package.cpath     = package.cpath .. ";".. execdir .. "lib\\?.dll;"
	package.cpath     = package.cpath .. execdir .. "lib\\loadall.dll"

	-- Add `./?/init.lua'
	if ( gamedir ) then
		package.path = gsub(
			package.path,
			"^%.\\%?%.lua;",
			gamedir .. "\\?.lua;" .. gamedir .. "\\?\\init.lua;"
		)
	else
		package.path = gsub(
			package.path,
			"^%.\\%?%.lua;",
			execdir .. "?.lua;"
		)
	end
else
	-- Get working directory
	execdir           = gsub( arg[ 0 ], "/lua/framework/init%.lua$", "/" )
	framework.execdir = execdir

	-- Add Windows LUA_LDIR paths
	local ldir        = "./?.lua;!lua/?.lua;!lua/?/init.lua;"
	package.path      = gsub( package.path, "^%./%?%.lua;", ldir )
	package.path      = gsub( package.path, "!", execdir )

	-- Add `lib'
	package.path      = package.path  .. ";" .. execdir .. "lib/?.lua"
	package.cpath     = package.cpath .. ";" .. execdir .. "lib/?.so;"
	package.cpath     = package.cpath .. execdir .. "lib/loadall.so"

	-- Add `./?/init.lua'
	if ( gamedir ) then
		package.path = gsub(
			package.path,
			"^%./%?%.lua;",
			gamedir .. "/?.lua;" .. gamedir .. "/?/init.lua;"
		)
	else
		package.path = gsub(
			package.path,
			"^%./%?%.lua;",
			execdir .. "?.lua;"
		)
	end
end

local arg     = arg
local require = require
local pairs   = pairs

module( "framework" )

function main()
	init()
	load( arg )

	require( "framework.event" )

	while ( true ) do
		local e = nil
		repeat
			e = framework.event.poll()
			if ( e ) then
				if ( e.type == ffi.C.SDL_QUIT or
				     e.type == ffi.C.SDL_APP_TERMINATING ) then
					if ( quit() ) then
						if ( framework.audio ) then
							framework.audio.quit()
						end

						return
					end
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
	framework.filesystem.init( arg[ -1 ] )
	framework.filesystem.mount( gamedir, nil, false )
	framework.filesystem.mount( execdir, nil, false )

	local c = {
		modules = {
			event    = true,
			keyboard = true,
			mouse    = true,
			timer    = true,
			graphics = true,
			audio    = true,
			physics  = true,
			sound    = true,
			window   = true
		},
		window = {
			title     = "",
			x         = nil,
			y         = nil,
			width     = 800,
			height    = 600,
			resizable = false,
			msaa      = 0
		}
	}

	-- LÖVE compatibility
	require( "framework.love" )

	if ( framework.filesystem.isFile( "conf.lua" ) ) then
		require( "conf" )
	end

	if ( framework.conf ) then
		framework.conf( c )
	end

	for k, v in pairs( c.modules ) do
		if ( v ) then require( "framework." .. k ) end
	end

	if ( c.modules.window ) then
		local title   = c.window.title
		local x       = c.window.x
		local y       = c.window.y
		local width   = c.window.width
		local height  = c.window.height
		local flags   = 0
		local glattrs = nil
		if ( c.window.resizable ) then
			local bit = require( "bit" )
			flags = bit.bor( flags, ffi.C.SDL_WINDOW_RESIZABLE )
		end
		if ( c.window.msaa > 0 ) then
			glattrs = {
				SDL_GL_MULTISAMPLEBUFFERS = 1,
				SDL_GL_MULTISAMPLESAMPLES = c.window.msaa
			}
		end
		framework.window.createWindow(
			title, x, y, width, height, flags, glattrs
		)
	end

	if ( framework.filesystem.isFile( "main.lua" ) ) then
		require( "main" )
	end
end

function load()
end

function quit()
	return true
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

main()
