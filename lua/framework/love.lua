--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local jit       = jit

local framework = framework
_G.love         = framework

local function love_filesystem()
	module( "love.filesystem" )

	function getRequirePath()
		return "./?.lua;lua/?.lua;lua/?/init.lua;"
	end

	return _M
end

local function love_system()
	module( "love.system" )

	function getOS()
		if ( jit.os == "OSX" ) then
			return "OS X"
		elseif ( jit.os == "Other" ) then
			return "Unknown"
		else
			return jit.os
		end
	end

	return _M
end

local modules = {
	[ "love.filesystem" ] = love_filesystem,
	[ "love.system" ]     = love_system
}

-- Preload module loaders.
for name, func in pairs( modules ) do
	package.preload[ name ] = func()
end
