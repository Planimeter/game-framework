--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local FT  = require( "lib.freetype" )
local ffi = require( "ffi" )
require( "class" )
local GL  = require( "lib.opengl" )

local ft = ffi.new( "FT_Library[1]" )
FT.FT_Init_FreeType( ft )

class( "framework.graphics.font" )

local font = framework.graphics.font

function font:font( filename, size )
	self.face = ffi.new( "FT_Face[1]" )
	FT.FT_New_Face( ft[0], filename, 0, self.face )
	FT.FT_Set_Pixel_Sizes( self.face[0], 0, size or 48 )

	self.texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, self.texture )

	setproxy( self )
end

function font:print( text, x, y, r, sx, sy, ox, oy, kx, ky )
	local width, height = framework.graphics.getSize()
	sx = sx or 1 / width
	sy = sy or 1 / height

	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, framework.graphics.defaultVBO[0] )
	GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )
	local shader   = framework.graphics.getShader()
	local vertex   = GL.glGetAttribLocation( shader, "vertex" )
	local stride   = 4 * ffi.sizeof( "GLfloat" )
	local texcoord = GL.glGetAttribLocation( shader, "texcoord" )
	local pointer  = ffi.cast( "GLvoid *", 2 * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( vertex, 2, GL.GL_FLOAT, 0, stride, nil )
	GL.glEnableVertexAttribArray( texcoord )
	GL.glVertexAttribPointer( texcoord, 2, GL.GL_FLOAT, 0, stride, pointer )

	local g = self.face[0].glyph
	for i = 1, #text do
		local char = string.sub( text, i, i )
		if ( FT.FT_Load_Char( self.face[0], string.byte( char ), 4 ) ~= 0 ) then
			GL.glTexImage2D(
				GL.GL_TEXTURE_2D,
				0,
				GL.GL_RGBA,
				g.bitmap.width,
				g.bitmap.rows,
				0,
				GL.GL_RGBA,
				GL.GL_UNSIGNED_BYTE,
				ffi.new( "GLubyte[4]", { 255, 255, 255, g.bitmap.buffer[0] } )
			)

			local x2 =  x + g.bitmap_left  * sx
			local y2 =  y + g.bitmap_top   * sy
			local w  =      g.bitmap.width * sx
			local h  =      g.bitmap.rows  * sy

			local box = {
				x2,     y2,     0.0, 0.0,
				x2 + w, y2,     1.0, 0.0,
				x2,     y2 - h, 0.0, 1.0,
				x2 + w, y2 - h, 1.0, 1.0,
			}

			local pBox = ffi.new( "GLfloat[?]", #box, box )
			local size = ffi.sizeof( pBox )
			GL.glBufferData( GL.GL_ARRAY_BUFFER, size, pBox, GL.GL_DYNAMIC_DRAW )
			framework.graphics.updateTransform()
			GL.glDrawArrays( GL.GL_TRIANGLE_STRIP, 0, 4 )

			x = x + ( g.advance.x / 64 ) * sx
			y = y + ( g.advance.y / 64 ) * sy
		else
			error( "Could not load character '" .. char .. "'", 3 )
		end
	end
end

function font:__gc()
	FT.FT_Done_Face( self.face )
end
