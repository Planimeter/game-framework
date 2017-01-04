--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )

class( "framework.graphics.font" )

local font = framework.graphics.font

function font:font( filename, size )
	setproxy( self )
end

function font:print( text, x, y, r, sx, sy, ox, oy, kx, ky )
end

function font:__gc()
end
