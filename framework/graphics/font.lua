--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local freetypegl = require( "lib.freetype-gl" )

class( "framework.graphics.font" )

local font = framework.graphics.font

function font:font( filename, size )
	local fontManager = freetypegl.font_manager_new( 512, 512, 3 )
	self.fontManager  = fontManager
	self.buffer       = freetypegl.text_buffer_new()

	local markup  = ffi.new( "markup_t" )
	markup.family = filename
	markup.size   = size or 12
	markup.font   = freetypegl.font_manager_get_from_markup( fontManager, markup )
	self.markup   = markup

	GL.glGenTextures( 1, fontManager.atlas.id )
	GL.glBindTexture( GL.GL_TEXTURE_2D, fontManager.atlas.id )

	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_BASE_LEVEL, 0 )
	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAX_LEVEL, 0 )

	GL.glTexImage2D( GL.GL_TEXTURE_2D, 0, GL.GL_RED, fontManager.atlas.width,
		fontManager.atlas.height, 0, GL.GL_RED, GL.GL_UNSIGNED_BYTE,
		fontManager.atlas.data )

	setproxy( self )
end

function font:print( text, x, y, r, sx, sy, ox, oy, kx, ky )
	framework.graphics.updateTransform()
	freetypegl.text_buffer_add_text( self.buffer, pen, self.markup, text_start, text_size )
	GL.glBindTexture( GL.GL_TEXTURE_2D, self.fontManager.atlas.id )
	freetypegl.vertex_buffer_render( self.buffer.buffer, GL.GL_TRIANGLES )
end

function font:__gc()
	GL.glDeleteTextures( 1, self.fontManager.atlas.id )
	self.fontManager.atlas.id = 0
	freetypegl.text_buffer_delete( self.buffer )
	freetypegl.font_manager_delete( self.fontManager )
end
