--=========== Copyright © 2020, Planimeter, All rights reserved. ===========--
--
-- Purpose:
--
--==========================================================================--

require( "class" )
local GL = require( "opengl" )

class( "framework.graphics.text" )

local text = framework.graphics.text

function text:text( font, textstring )
	self.font       = font
	self.textstring = textstring or ""
end

function text:draw( x, y, r, sx, sy, ox, oy, kx, ky )
	local font = self.font
	font:print( self.textstring, x, y, r, sx, sy, ox, oy, kx, ky )
end

function text:getFont()
	return self.font
end

function text:set( textstring )
	self.textstring = textstring
end

function text:setFont( font )
	self.font = font
end
