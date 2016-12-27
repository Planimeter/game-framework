--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.math" )

local framework = framework
local table     = table

module( "framework.graphics" )

state = state or {}

function push()
	table.insert( state, framework.math.newMat4() )
end

function pop()
	table.remove( state, #state )
end
