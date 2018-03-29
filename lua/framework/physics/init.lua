--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local chipmunk = require( "chipmunk" )

module( "framework.physics" )

function newSpace()
	return chipmunk.cpSpaceNew()
end
