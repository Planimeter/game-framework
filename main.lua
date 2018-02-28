--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

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
	framework.graphics.setPerspectiveProjection( 45, width / height, 0.01, 100 )

	helmet = framework.graphics.newModel(
		"models/DamagedHelmet/gltf/DamagedHelmet.gltf"
	)
end

function framework.update( dt )
end

function framework.draw()
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
