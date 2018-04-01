--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local chipmunk = require( "chipmunk" )
local ffi      = require( "ffi" )

class( "framework.physics.space" )

local space = framework.physics.space

function space:space()
	self._space = chipmunk.cpSpaceNew()
	setproxy( self )
end

function space:update( dt )
	chipmunk.cpSpaceStep( self._space, dt )
end

function space:__gc()
end
