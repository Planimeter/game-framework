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

	GL.glTexParameteri( 0x0DE1, 0x813C, 0 )
	GL.glTexParameteri( 0x0DE1, 0x813D, 0 )

	GL.glTexImage2D( 0x0DE1, 0, 0x1908, width[0], height[0], 0, 0x1908, 0x1401, pixels )
	stbi.stbi_image_free( pixels )
end

function image:draw( x, y, r, sx, sy, ox, oy, kx, ky )
	local width    = self.width[0]
	local height   = self.height[0]
	local vertices = {
		x,         y + height,
		x + width, y + height,
		x,         y,
		x + width, y + height,
		x + width, y,
		x,         y
	}
	local texCoords = {
		0.0, 1.0,
		1.0, 1.0,
		0.0, 0.0,
		1.0, 1.0,
		1.0, 0.0,
		0.0, 0.0
	}
	local pVertices  = ffi.new( "GLfloat[?]", #vertices, vertices )
	local pTexCoords = ffi.new( "GLfloat[?]", #texCoords, texCoords )
	local shader     = framework.graphics.getShader()
	local vertex     = GL.glGetAttribLocation( shader, "vertex" )
	GL.glVertexAttribPointer( vertex, 2, 0x1406, 0, 0, pVertices )
	local texcoord   = GL.glGetAttribLocation( shader, "texcoord" )
	GL.glVertexAttribPointer( texcoord, 2, 0x1406, 0, 0, pTexCoords )
	GL.glBindTexture( 0x0DE1, self.texture[0] )
	GL.glDrawArrays( 0x0004, 0, #vertices / 2 )
end
