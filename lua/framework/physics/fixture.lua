--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local chipmunk = require( "chipmunk" )
local ffi      = require( "ffi" )

class( "framework.physics.fixture" )

local fixture = framework.physics.fixture

function fixture:fixture( body, shape, density )
	self.body    = body
	self.shape   = shape
	self.density = density or 1
	setproxy( self )
end

function fixture:setFilterData( categories, mask, group )
end

function fixture:setUserData( userdata )
	self.userdata = userdata
end

function fixture:__gc()
end
