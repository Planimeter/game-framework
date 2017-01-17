--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local FT  = require( "freetype" )
local ffi = require( "ffi" )
local GL  = require( "opengl" )

local ft = ffi.new( "FT_Library[1]" )
FT.FT_Init_FreeType( ft )

class( "framework.graphics.font" )

local font = framework.graphics.font

function font:font( filename, size )
	self.face = ffi.new( "FT_Face[1]" )
	self.buffer, self.length = framework.filesystem.read( filename )
	FT.FT_New_Memory_Face( ft[0], self.buffer, self.length, 0, self.face )

	self.size = ( size or 16 ) * framework.window.getPixelScale()
	FT.FT_Set_Pixel_Sizes( self.face[0], 0, self.size )

	self.texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, self.texture )

	setproxy( self )
end

function font:print( text, x, y, r, sx, sy, ox, oy, kx, ky )
	local shader   = framework.graphics.getShader()
	local vertex   = GL.glGetAttribLocation( shader, "vertex" )
	local stride   = 4 * ffi.sizeof( "GLfloat" )
	local texcoord = GL.glGetAttribLocation( shader, "texcoord" )
	local pointer  = ffi.cast( "GLvoid *", 2 * ffi.sizeof( "GLfloat" ) )
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, framework.graphics.defaultVBO[0] )
	GL.glVertexAttribPointer( vertex, 2, GL.GL_FLOAT, 0, stride, nil )
	GL.glEnableVertexAttribArray( texcoord )
	GL.glVertexAttribPointer( texcoord, 2, GL.GL_FLOAT, 0, stride, pointer )
	framework.graphics.updateTransform()

	GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )
	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_BASE_LEVEL, 0 )
	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAX_LEVEL, 0 )
	GL.glPixelStorei( GL.GL_UNPACK_ALIGNMENT, 1 )
	local swizzleMask = ffi.new( "GLint[4]", { GL.GL_RED, GL.GL_RED, GL.GL_RED, GL.GL_RED } )
	GL.glTexParameteriv( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_SWIZZLE_RGBA, swizzleMask )

	local face = self.face[0]
	for i = 1, #text do
		local char = string.sub( text, i, i )
		if ( FT.FT_Load_Char( face, string.byte( char ), 4 ) == 0 ) then
			local g        = face.glyph
			local gx       = x + g.bitmap_left
			local gy       = y + face.size.metrics.ascender / 64 - g.bitmap_top
			local width    = g.bitmap.width
			local height   = g.bitmap.rows
			local vertices = {
				-- vertex              -- texcoord
				gx,         gy + height, 0.0, 1.0,
				gx + width, gy + height, 1.0, 1.0,
				gx,         gy,          0.0, 0.0,
				gx + width, gy + height, 1.0, 1.0,
				gx + width, gy,          1.0, 0.0,
				gx,         gy,          0.0, 0.0
			}
			local pVertices = ffi.new( "GLfloat[?]", #vertices, vertices )
			local size = ffi.sizeof( pVertices )
			GL.glBufferData( GL.GL_ARRAY_BUFFER, size, pVertices, GL.GL_STREAM_DRAW )
			GL.glTexImage2D(
				GL.GL_TEXTURE_2D,
				0,
				GL.GL_RED,
				g.bitmap.width,
				g.bitmap.rows,
				0,
				GL.GL_RED,
				GL.GL_UNSIGNED_BYTE,
				g.bitmap.buffer
			)
			framework.graphics.drawArrays( GL.GL_TRIANGLES, 0, #vertices / 2 )
			x = x + ( g.advance.x / 64 )
			y = y + ( g.advance.y / 64 )
		else
			error( "Could not load character '" .. char .. "'", 3 )
		end
	end

	GL.glPixelStorei( GL.GL_UNPACK_ALIGNMENT, 4 )
end

function font:__gc()
	GL.glDeleteTextures( 1, self.texture )
	FT.FT_Done_Face( self.face )
end
