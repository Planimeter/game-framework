--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local kazmath = require( "kazmath" )
local ffi     = require( "ffi" )

local faces = {
	"right",
	"left",
	"top",
	"bottom",
	"front",
	"back"
}

local function getCubemap( filename, mipmapLevels )
	local t = {}
	for i = 0, mipmapLevels - 1 do
		for j = 1, #faces do
			local face = faces[ j ]
			local filename = string.format( filename, face, i )
			table.insert( t, { faces[ j ], filename } )
		end
	end
	return t
end

function framework.load( arg )
	-- Set glTF 2.0 physically-based rendering shader
	framework.graphics.setGlTFPBRShader()

	framework.graphics.setActiveTexture( 5 )
	diffuseCubemap = framework.graphics.newCubemap(
		getCubemap( "textures/papermill/diffuse/diffuse_%s_%u.jpg", 1 )
	)

	framework.graphics.setActiveTexture( 6 )
	specularCubemap = framework.graphics.newCubemap(
		getCubemap( "textures/papermill/specular/specular_%s_%u.jpg", 10 )
	)

	framework.graphics.setActiveTexture( 0 )

	-- View matrix
	framework.graphics.lookAt(
		0, 0, 4,
		0, 0, 0,
		0, 1, 0
	)

	-- Load scene
	helmet = framework.graphics.newModel(
		"models/DamagedHelmet/gltf/DamagedHelmet.gltf"
	)

	-- Set background color
	framework.graphics.setBackgroundColor( { 51, 51, 51, 1 } )

	-- Light
	local rotation = math.rad( 75 )
	local pitch    = math.rad( 40 )
	framework.graphics.setLightDirection( {
		math.sin( rotation ) * math.cos( pitch ),
		math.sin( pitch ),
		math.cos( rotation ) * math.cos( pitch )
	} )
end

function framework.update( dt )
end

--[[ ***** Mouse Controls ***** ]]
local mouseDown = false
local roll = math.pi
local pitch = 0
local translate = 4

function framework.draw()
	local width, height = framework.graphics.getSize()
	framework.graphics.setPerspectiveProjection( 45, width / height, 0.01, 100 )

	-- set up the camera position and view matrix
	framework.graphics.setCameraPosition( {
		-translate * math.sin(  roll ) * math.cos( -pitch ),
		-translate * math.sin( -pitch ),
		 translate * math.cos(  roll ) * math.cos( -pitch )
	} )

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
