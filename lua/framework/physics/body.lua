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

function body:applyLinearImpulse()
end

function body:getFixtureList()
	local t = {}
	return t
end

function body:getLinearVelocity()
	local linearVelocity = chipmunk.cpBodyGetVelocity( self._body )
	return linearVelocity.x, linearVelocity.y
end

function body:getMass()
	return 0
end

function body:getPosition()
	local position = chipmunk.cpBodyGetPosition( self._body )
	return position.x, position.y
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
