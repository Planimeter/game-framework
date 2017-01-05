--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local FT  = require( "lib.freetype" )
local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )

local ft = ffi.new( "FT_Library[1]" )
FT.FT_Init_FreeType( ft )

class( "framework.graphics.font" )

local font = framework.graphics.font

function font:font( filename, size )
	local face = ffi.new( "FT_Face[1]" )
	FT.FT_New_Face( ft[0], filename, 0, face )
	FT.FT_Set_Pixel_Sizes( face[0], 0, size or 12 )

	setproxy( self )
end

function font:print( text, x, y, r, sx, sy, ox, oy, kx, ky )
end

function font:__gc()
end
