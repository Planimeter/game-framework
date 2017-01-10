--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

module( "framework.audio" )

function newSource( filename )
	local sound = framework.sound
	return sound( filename )
end
