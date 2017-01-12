--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.sound" )
local AL = require( "openal" )

local framework = framework

module( "framework.audio" )

function newSource( filename )
	local sound = framework.sound
	return sound( filename )
end
