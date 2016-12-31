--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi   = require( "ffi" )
local GL    = require( "lib.opengl" )
local DevIL = require( "DevIL" )

-- Needed to initialize DevIL.
DevIL.ilInit ()
DevIL.iluInit()

-- GL cannot use palettes anyway, so convert early.
DevIL.ilEnable (DevIL.IL_CONV_PAL)

-- Gets rid of dithering on some nVidia-based cards.
DevIL.ilutEnable (DevIL.ILUT_OPENGL_CONV)

class( "framework.graphics.image" )

local image = framework.graphics.image

function image:image( filename )
end

function image:draw()
end
