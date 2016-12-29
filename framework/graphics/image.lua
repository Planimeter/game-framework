--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )

class( "framework.graphics.image" )

local image = framework.graphics.image

function image:image( filename )
	local texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, texture )
end
