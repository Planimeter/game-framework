--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local GL = require( "lib.opengl" )

module( "framework.graphics" )

function clear()
	GL.glClear( 0x00004000 )
end

function line()
end

function rectangle()
end

function setFramebuffer()
end

function setShader( shader )
	GL.glUseProgram( shader )
end
