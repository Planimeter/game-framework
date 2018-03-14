--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local jit       = jit

local framework = framework
_G.love         = framework

local function filesystem()
	module( "love.filesystem" )
end

local function system()
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
end

filesystem()
system()
