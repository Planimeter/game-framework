--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local AL = require( "openal" )

module( "framework.audio" )

function newSource( filename )
	local sound = framework.sound
	return sound( filename )
end
