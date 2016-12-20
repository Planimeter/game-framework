--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.filesystem" )
local SDL = require( "lib.sdl" )

local framework = framework
local require   = require
local pairs     = pairs

module( "framework" )

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

function init()
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
end

function main()
	init()

	while ( true ) do
		local event = SDL.SDL_Event()
		while ( SDL.SDL_PollEvent( event ) ) do
		end

		framework.window.swap()
	end
end

function load()
end

function update( dt )
end

function draw()
end

main()
