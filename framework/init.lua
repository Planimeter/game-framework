--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.filesystem" )
local ffi = require( "ffi" )

local framework = framework
local require   = require
local pairs     = pairs

module( "framework" )

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
		framework.window.createWindow(
			c.window.title,
			c.window.x,
			c.window.y,
			c.window.width,
			c.window.height
		)
	end
end

function load()
end

function update( dt )
end

function draw()
end

init()
