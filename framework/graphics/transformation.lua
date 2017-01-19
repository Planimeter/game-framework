--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local kazmath = require( "kazmath" )
local ffi     = require( "ffi" )
local GL      = require( "opengl" )

local ipairs    = ipairs
local framework = framework
local table     = table

module( "framework.graphics" )

local transformations = {
	"model",
	"view",
	"projection"
}

_mode  = _mode  or "model"
_state = _state or {}

for _, transformation in ipairs( transformations ) do
	local mat4 = ffi.new( "kmMat4" )
	kazmath.kmMat4Identity( mat4 )
	_state[ transformation ] = _state[ transformation ] or { mat4 }
end

function getMatrixMode()
	return _mode
end

function setMatrixMode( mode )
	_mode = mode
end

function getTransformation()
	local mode  = getMatrixMode()
	local state = _state[ mode ]
	return state[ #state ]
end

function push()
	local mode = getMatrixMode()
	local top  = ffi.new( "kmMat4" )
	kazmath.kmMat4Assign( top, getTransformation() )
	table.insert( _state[ mode ], top )
end

function pop()
	local mode  = getMatrixMode()
	local state = _state[ mode ]
	if ( #state == 1 ) then return end
	table.remove( state, #state )
end

function setPerspectiveProjection( fov, aspect, near, far )
	local mode = getMatrixMode()
	setMatrixMode( "projection" )
		local mat4 = getTransformation()
		kazmath.kmMat4PerspectiveProjection( mat4, fov, aspect, near, far )
	setMatrixMode( mode )
end

function setOrthographicProjection( width, height )
	if ( not width and not height ) then
		width, height = framework.graphics.getSize()
	end

	local mode = getMatrixMode()
	setMatrixMode( "projection" )
		local mat4 = getTransformation()
		kazmath.kmMat4OrthographicProjection( mat4, 0, width, height, 0, -1.0, 1.0 )
	setMatrixMode( mode )
end

function origin()
	kazmath.kmMat4Identity( getTransformation() )
end

function rotate( angle )
	local rotation = ffi.new( "kmMat4" )
	kazmath.kmMat4RotationZ( rotation, angle )
	local mat4 = getTransformation()
	kazmath.kmMat4Multiply( mat4, mat4, rotation )
end

function scale( x, y, z )
	z = z or 1
	local scaling = ffi.new( "kmMat4" )
	kazmath.kmMat4Scaling( scaling, x, y, z )
	local mat4 = getTransformation()
	kazmath.kmMat4Multiply( mat4, mat4, scaling )
end

function translate( x, y, z )
	z = z or 0
	local translation = ffi.new( "kmMat4" )
	kazmath.kmMat4Translation( translation, x, y, z )
	local mat4 = getTransformation()
	kazmath.kmMat4Multiply( mat4, mat4, translation )
end

function updateTransformations()
	local mode   = getMatrixMode()
	local shader = framework.graphics.getShader()
	for _, transformation in ipairs( transformations ) do
		local uniform = GL.glGetUniformLocation( shader, transformation )
		setMatrixMode( transformation )
		local mat4 = getTransformation()
		GL.glUniformMatrix4fv( uniform, 1, GL.GL_FALSE, mat4.mat )
	end
	setMatrixMode( mode )
end
