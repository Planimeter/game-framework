--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local kazmath = require( "lib.kazmath" )
local GL      = require( "lib.opengl" )

local framework = framework
local table     = table

module( "framework.graphics" )

state = state or {}

function getTransform()
	return state[ #state ]
end

function push()
	local top = ffi.new( "kmMat4" )
	kazmath.kmMat4Assign( top, getTransform() )
	table.insert( state, top )
end

function pop()
	if ( #state == 1 ) then return end
	table.remove( state, #state )
end

function origin()
	kazmath.kmMat4Identity( getTransform() )
end

function scale( x, y, z )
	z = z or 1
	local scaling = ffi.new( "kmMat4" )
	kazmath.kmMat4Scaling( scaling, x, y, z )
	kazmath.kmMat4Multiply( getTransform(), getTransform(), scaling )
end

function translate( x, y, z )
	z = z or 0
	local translation = ffi.new( "kmMat4" )
	kazmath.kmMat4Translation( translation, x, y, z )
	kazmath.kmMat4Multiply( getTransform(), getTransform(), translation )
end

function updateTransform()
	local projection = GL.glGetUniformLocation( shader, "model" )
	GL.glUniformMatrix4fv( projection, 1, 0, getTransform().mat )
end
