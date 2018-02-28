--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local assimp = require( "assimp" )
local ffi    = require( "ffi" )
local min    = ffi.new( "struct aiVector3D" )
local max    = ffi.new( "struct aiVector3D" )
local center = ffi.new( "struct aiVector3D" )

function framework.load( arg )
	framework.graphics.setGlTFPBRShader()

	local rotation = math.rad( 75 )
	local pitch    = math.rad( 40 )
	framework.graphics.setLightDirection( {
		math.sin( rotation ) * math.cos( pitch ),
		math.sin( pitch ),
		math.cos( rotation ) * math.cos( pitch )
	} )

	local width, height = framework.graphics.getSize()
	framework.graphics.setPerspectiveProjection( 45, width / height, 0.1, 1000 )

	teapot = framework.graphics.newModel( "models/teapot.obj" )

	teapot:getBoundingBox( min, max )
	center.x = ( min.x + max.x ) / 2
	center.y = ( min.y + max.y ) / 2
	center.z = ( min.z + max.z ) / 2
end

function framework.update( dt )
end

function framework.draw()
	framework.graphics.push()
		framework.graphics.lookAt(
			0,  0,  3,
			0,  0, -5,
			0,  1,  0
		)
		framework.graphics.rotateY( math.rad( 180 ) )
		scale = max.x - min.x
		scale = math.max( max.y - min.y, scale )
		scale = math.max( max.z - min.z, scale )
		scale = 1 / scale
		framework.graphics.scale( scale, scale, scale )
		framework.graphics.translate( -center.x, -center.y, -center.z )
		framework.graphics.draw( teapot )
	framework.graphics.pop()
end
