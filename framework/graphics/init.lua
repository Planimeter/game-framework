--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.graphics.shader" )
require( "framework.graphics.transformation" )

local GL = require( "lib.opengl" )

module( "framework.graphics" )

function clear()
	GL.glClear( 0x00004000 )
end
