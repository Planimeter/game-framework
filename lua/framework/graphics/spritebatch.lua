--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local GL  = require( "opengl" )
local ffi = require( "ffi" )

class( "framework.graphics.spritebatch" )

local spritebatch = framework.graphics.spritebatch

function spritebatch:spritebatch( image, maxsprites )
	self.image = image

	setproxy( self )
end

function spritebatch:add( quad )
end

function spritebatch:draw( x, y, r, sx, sy, ox, oy, kx, ky )
	image.draw( self, x, y, r, sx, sy, ox, oy, kx, ky )
end

function spritebatch:__gc()
end
