--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local assimp = require( "assimp" )
local ffi    = require( "ffi" )
local GL     = require( "opengl" )

class( "framework.graphics.model" )

local model = framework.graphics.model

function model:model( filename )
	setproxy( self )
end

function model:draw( x, y, r, sx, sy, ox, oy, kx, ky )
end

function model:__gc()
end
