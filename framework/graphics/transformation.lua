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

state = state or {}

for _, transformation in ipairs( transformations ) do
	local mat4 = ffi.new( "kmMat4" )
	kazmath.kmMat4Identity( mat4 )
	state[ transformation ] = state[ transformation ] or { mat4 }
end

function getTransformation( mode )
	mode = mode or "model"
	return state[ mode ][ #state[ mode ] ]
end

function push( mode )
	mode = mode or "model"
	local top = ffi.new( "kmMat4" )
	kazmath.kmMat4Assign( top, getTransformation( mode ) )
	table.insert( state[ mode ], top )
end

function pop( mode )
	mode = mode or "model"
	if ( #state[ mode ] == 1 ) then return end
	table.remove( state[ mode ], #state[ mode ] )
end

function setPerspectiveProjection( fov, aspect, near, far )
	local mat4 = getTransformation( "projection" )
	local width, height = framework.graphics.getSize()
	aspect = aspect or width / height
	kazmath.kmMat4PerspectiveProjection( mat4, fov, aspect, near, far )
end

function setOrthographicProjection( width, height )
	if ( not width and not height ) then
		width, height = framework.graphics.getSize()
	end

	local mat4 = getTransformation( "projection" )
	kazmath.kmMat4OrthographicProjection( mat4, 0, width, height, 0, -1.0, 1.0 )
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
	for _, transformation in ipairs( transformations ) do
		local uniform = GL.glGetUniformLocation( shader, transformation )
		local mat4    = getTransformation( transformation )
		GL.glUniformMatrix4fv( uniform, 1, GL.GL_FALSE, mat4.mat )
	end
end
