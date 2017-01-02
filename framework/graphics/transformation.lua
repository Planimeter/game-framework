--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.math" )
local kazmath = require( "lib.kazmath" )
local GL      = require( "lib.opengl" )

local framework = framework
local table     = table

module( "framework.graphics" )

state = state or {}

function push()
	table.insert( state, framework.math.newMat4( getTransform().mat ) )
end

function pop()
	if ( #state == 1 ) then return end
	table.remove( state, #state )
end

function getTransform()
	return state[ #state ]
end

function scale( x, y, z )
	z = z or 1
	local pM2 = framework.math.newMat4()
	kazmath.kmMat4Scaling( pM2, x, y, z )
	kazmath.kmMat4Multiply( getTransform(), getTransform(), pM2 )
end

function translate( x, y, z )
	z = z or 0
	local pM2 = framework.math.newMat4()
	kazmath.kmMat4Translation( pM2, x, y, z )
	kazmath.kmMat4Multiply( getTransform(), getTransform(), pM2 )
end

function origin()
	kazmath.kmMat4Identity( getTransform() )
end

function updateTransform()
	local projection = GL.glGetUniformLocation( shader, "projection" )
	GL.glUniformMatrix4fv( projection, 1, 0, getTransform().mat )
end
