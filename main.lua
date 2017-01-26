--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

function framework.load( arg )
	framework.graphics.setDefault3DShader()
	teapot = framework.graphics.newModel( "models/teapot.obj" )
end

function framework.update( dt )
end

function framework.draw()
	framework.graphics.draw( teapot )
end
