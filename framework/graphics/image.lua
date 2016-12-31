--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )
local IL  = require( "lib.devil" )

class( "framework.graphics.image" )

local image = framework.graphics.image

function image:image( filename )
	IL.ilInit()
	self.texture = IL.ilLoadImage( filename )
end

function image:draw()
end
