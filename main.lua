--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

function framework.load( arg )
	framework.graphics.setGlTFPBRShader()
	local rotation = 75 * math.pi / 180
	local pitch    = 40 * math.pi / 180
	framework.graphics.setLightDirection( {
		math.sin( rotation ) * math.cos( pitch ),
		math.sin( pitch ),
		math.cos( rotation ) * math.cos( pitch )
	} )
	local width, height = framework.graphics.getSize()
	framework.graphics.setPerspectiveProjection( 45, width / height, 0.1, 1000 )
	teapot = framework.graphics.newModel( "models/teapot.obj" )
end

function framework.update( dt )
end

function framework.draw()
	framework.graphics.push()
		framework.graphics.translate( 0, -1.575, -10 )
		framework.graphics.draw( teapot )
	framework.graphics.pop()
end
