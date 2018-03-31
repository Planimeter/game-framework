--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local chipmunk = require( "chipmunk" )
local ffi      = require( "ffi" )

class( "framework.physics.body" )

local body = framework.physics.body

function body:body( world, x, y, type )
	self._body  = chipmunk.cpBodyAlloc()
	self._world = world
	self:setPosition( x, y )
	setproxy( self )
end

function body:setFixedRotation()
	chipmunk.cpBodySetMoment( self._body, math.huge )
end

function body:setLinearDamping( n )
end

function body:setPosition( x, y )
	chipmunk.cpBodySetPosition( self._body, ffi.new( "cpVect", x, y ) )
end

function body:setUserData( userdata )
	self._userdata = userdata
end

function body:__gc()
end
