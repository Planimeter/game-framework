--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

function framework.load( arg )
	-- Set glTF 2.0 physically-based rendering shader
	framework.graphics.setGlTFPBRShader()

	-- Light
	local rotation = math.rad( 75 )
	local pitch    = math.rad( 40 )
	framework.graphics.setLightDirection( {
		math.sin( rotation ) * math.cos( pitch ),
		math.sin( pitch ),
		math.cos( rotation ) * math.cos( pitch )
	} )

	-- Camera
	framework.graphics.setCameraPosition( {
		-1 * math.sin(  rotation ) * math.cos( -pitch ),
		-1 * math.sin( -pitch ),
		 1 * math.cos(  rotation ) * math.cos( -pitch )
	} )

	-- Load scene
	helmet = framework.graphics.newModel(
		"models/DamagedHelmet/gltf/DamagedHelmet.gltf"
	)

	-- Set background color
	framework.graphics.setBackgroundColor( { 51, 51, 51, 1 } )
end

function framework.update( dt )
end

function framework.draw()
	local width, height = framework.graphics.getSize()
	framework.graphics.setPerspectiveProjection( 45, width / height, 0.01, 100 )

	framework.graphics.push()
		framework.graphics.lookAt(
			0, 0, 4,
			0, 0, 0,
			0, 1, 0
		)
		framework.graphics.rotateY( math.rad( 180 ) )
		framework.graphics.draw( helmet )
	framework.graphics.pop()
end
