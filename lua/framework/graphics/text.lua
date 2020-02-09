--=========== Copyright © 2020, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local GL = require( "opengl" )

class( "framework.graphics.text" )

local text = framework.graphics.text

function text:text( font, textstring )
	self.font       = font
	self.textstring = textstring
end

function text:set( textstring )
	self.textstring = textstring
end

function text:setFont( font )
	self.font = font
end
