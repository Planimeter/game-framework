--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.math" )
local kazmath = require( "lib.kazmath" )

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

function getTransform()
	return state[ #state ]
end

function scale( x, y, z )
	kazmath.kmMat4Scaling( getTransform(), x, y, z )
end

function translate( x, y, z )
	kazmath.kmMat4Translation( getTransform(), x, y, z )
end

function origin()
	kazmath.kmMat4Identity( getTransform() )
end
