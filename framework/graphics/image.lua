--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi   = require( "ffi" )
local GL    = require( "lib.opengl" )
local devil = require( "lib.devil" )

class( "framework.graphics.image" )

local image = framework.graphics.image

function image:image( filename )
	devil.ilInit()
	self.texture = devil.ilLoadImage( filename )
end

function image:draw()
end
