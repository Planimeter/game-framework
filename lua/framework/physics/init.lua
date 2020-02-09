--=========== Copyright © 2020, Planimeter, All rights reserved. ===========--
--
-- Purpose:
--
--==========================================================================--

local chipmunk  = require( "chipmunk" )

local framework = framework
local require   = require

module( "framework.physics" )

function newSpace()
	require( "framework.physics.space" )
	local space = framework.physics.space
	return space()
end

function newBody( world, x, y, type )
	require( "framework.physics.body" )
	local body = framework.physics.body
	return body( world, x, y, type )
end

function newRectangleShape( width, height )
end

function newFixture( body, shape, density )
	require( "framework.physics.fixture" )
	local fixture = framework.physics.fixture
	return fixture( body, shape, density )
end
