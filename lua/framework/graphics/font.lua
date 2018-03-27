--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
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
	size = size or 16

	self.face = ffi.new( "FT_Face[1]" )
	self.buffer, self.length = framework.filesystem.read( filename )
	if ( self.buffer == nil ) then
		FT.FT_Done_Face( self.face )
		error( self.length, 3 )
	end
	FT.FT_New_Memory_Face( ft[0], self.buffer, self.length, 0, self.face )

	self.size = size
	size = size * framework.window.getPixelScale()
	FT.FT_Set_Pixel_Sizes( self.face[0], 0, size )

	self.texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, self.texture )
	GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )

	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_BASE_LEVEL, 0 )
	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAX_LEVEL, 0 )
	local o    = GL.GL_ONE
	local r    = GL.GL_RED
	local mask = ffi.new( "GLint[4]", o, o, o, r )
	GL.glTexParameteriv( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_SWIZZLE_RGBA, mask )

	local s = self.face[0].size.metrics;
	self.advance = bit.rshift( tonumber( s.max_advance ), 6 )
	self.ascent  = bit.rshift( tonumber( s.ascender ), 6 )
	self.descent = bit.rshift( tonumber( s.descender ), 6 )
	self.height  = bit.rshift( tonumber( s.height ), 6 )

	setproxy( self )
end

function font:getWidth( text )
	local width = 0
	local x     = 0
	local face = self.face[0]
	for i = 1, #text do
		local char = string.sub( text, i, i )
		if ( FT.FT_Load_Char( face, string.byte( char ), 4 ) == 0 ) then
			local g  = face.glyph
			local gx = x + g.bitmap_left
			local bw = g.bitmap.width
			x        = x + ( g.advance.x / 64 )
			width    = width + gx + bw
		else
			error( "Could not load character '" .. char .. "'", 3 )
		end
	end
	return tonumber( width )
end

function font:getHeight()
	return math.floor( self.height / framework.window.getPixelScale() + 0.5 )
end

function font:getWrap()
	-- TODO: Implement me.
	return 0, {}
end

function font:print( text, x, y, r, sx, sy, ox, oy, kx, ky )
	local defaultVBO = framework.graphics._defaultVBO
	local shader     = framework.graphics.getShader()
	local position   = GL.glGetAttribLocation( shader, "position" )
	local stride     = 4 * ffi.sizeof( "GLfloat" )
	local texcoord   = GL.glGetAttribLocation( shader, "texcoord" )
	local pointer    = ffi.cast( "GLvoid *", 2 * ffi.sizeof( "GLfloat" ) )
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, defaultVBO[0] )
	GL.glVertexAttribPointer( position, 2, GL.GL_FLOAT, 0, stride, nil )
	GL.glVertexAttribPointer( texcoord, 2, GL.GL_FLOAT, 0, stride, pointer )
	framework.graphics.updateTransformations()

	GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )
	GL.glPixelStorei( GL.GL_UNPACK_ALIGNMENT, 1 )

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
				-- vertex                -- texcoord
				gx,         gy + height, 0.0, 1.0,
				gx + width, gy + height, 1.0, 1.0,
				gx,         gy,          0.0, 0.0,
				gx + width, gy + height, 1.0, 1.0,
				gx + width, gy,          1.0, 0.0,
				gx,         gy,          0.0, 0.0
			}
			local pVertices = ffi.new( "GLfloat[?]", #vertices, vertices )
			local size = ffi.sizeof( pVertices )
			GL.glBufferData(
				GL.GL_ARRAY_BUFFER,
				size,
				pVertices,
				GL.GL_STREAM_DRAW
			)
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
			framework.graphics.drawArrays( GL.GL_TRIANGLES, 0, #vertices / 4 )
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
	FT.FT_Done_Face( self.face[0] )
end
