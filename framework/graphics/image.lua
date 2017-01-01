--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi  = require( "ffi" )
local GL   = require( "lib.opengl" )
local stbi = require( "lib.stb_image" )

class( "framework.graphics.image" )

local image = framework.graphics.image

function image:image( filename )
	self.texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, self.texture )
	GL.glBindTexture( 0x0DE1, self.texture[0] )

	local buffer, len = framework.filesystem.read( filename )
	local width    = ffi.new( "int[1]" )
	local height   = ffi.new( "int[1]" )
	local channels = ffi.new( "int[1]" )
	local pixels   = stbi.stbi_load_from_memory( buffer, len, width, height, channels, 4 )
	self.width     = width
	self.height    = height
	self.channels  = channels
	self.pixels    = pixels

	GL.glTexImage2D( 0x0DE1, 0, 0x1908, width[0], height[0], 0, 0x1908, 0x1406, pixels )
	stbi.stbi_image_free( pixels )
end

function image:draw()
end
