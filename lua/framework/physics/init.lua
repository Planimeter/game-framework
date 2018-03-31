--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local chipmunk  = require( "chipmunk" )

local framework = framework
local require   = require

module( "framework.physics" )

function newSpace()
	return chipmunk.cpSpaceNew()
end

function newBody( world, x, y, type )
	require( "framework.physics.body" )
	local body = framework.physics.body
	return body( world, x, y, type )
end
