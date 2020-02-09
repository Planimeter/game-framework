--=========== Copyright © 2020, Planimeter, All rights reserved. ===========--
--
-- Purpose:
--
--==========================================================================--

require( "class" )

class( "framework.graphics.quad" )

local quad = framework.graphics.quad

function quad:quad( x, y, width, height, sw, sh )
	self.x      = x
	self.y      = y
	self.width  = width
	self.height = height
	self.sw     = sw
	self.sh     = sh
end

function quad:setViewport( x, y, width, height )
	self.x      = x
	self.y      = y
	self.width  = width
	self.height = height
end
