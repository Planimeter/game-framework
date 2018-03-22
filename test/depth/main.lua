--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local kazmath = require( "kazmath" )
local ffi     = require( "ffi" )

function framework.load( arg )
	-- Load scene
	helmet = framework.graphics.newModel(
		"models/DamagedHelmet/gltf/DamagedHelmet.gltf"
	)
end

function framework.update( dt )
end

--[[ ***** Mouse Controls ***** ]]
local mouseDown = false
local roll = math.pi
local pitch = 0
local translate = 4

function framework.draw()
	-- Set depth shader
	framework.graphics.setShader( "depth" )

	-- View matrix
	framework.graphics.lookAt(
		0, 0, 4,
		0, 0, 0,
		0, 1, 0
	)

	local width, height = framework.graphics.getSize()
	framework.graphics.setPerspectiveProjection( 45, width / height, 0.01, 100 )

	-- Update view matrix
	-- roll, pitch and translate are all globals.
	local xRotation = ffi.new( "kmMat4" )
	kazmath.kmMat4RotationY( xRotation, roll )
	local yRotation = ffi.new( "kmMat4" )
	kazmath.kmMat4RotationX( yRotation, pitch )
	local mode = framework.graphics.getMatrixMode()
	framework.graphics.setMatrixMode( "view" )
	framework.graphics.push()
		local mat4 = framework.graphics.getTransformation()
		kazmath.kmMat4Multiply( mat4, yRotation, xRotation )
		mat4.mat[14] = -translate
		framework.graphics.draw( helmet )
	framework.graphics.pop()
	framework.graphics.setMatrixMode( mode )
end

function framework.mousepressed( x, y, button, istouch )
	mouseDown = true
end

function framework.mousereleased( x, y, button, istouch )
	mouseDown = false
end

function framework.mousemoved( x, y, dx, dy, istouch )
	if ( not mouseDown ) then
		return
	end
	roll  = roll  + ( dx / 100 )
	pitch = pitch + ( dy / 100 )
end

local wheelSpeed = 1.04
function framework.wheelmoved( x, y )
	if ( y > 0 ) then
		translate = translate * wheelSpeed
	else
		translate = translate / wheelSpeed
	end
end
