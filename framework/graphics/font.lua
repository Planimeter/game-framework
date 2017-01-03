--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local freetypegl = require( "lib.freetype-gl" )
local ffi        = require( "ffi" )
local GL         = require( "lib.opengl" )

class( "framework.graphics.font" )

local font = framework.graphics.font

function font:font( filename, size )
	local fontManager  = freetypegl.font_manager_new( 512, 512, 3 )
	self.fontManager   = fontManager
	self.buffer        = freetypegl.text_buffer_new()
	self.buffer.buffer = freetypegl.vertex_buffer_new( "vertex:2f,tex_coord:2f" )

	local white = ffi.new( "vec4", { { 1.0, 1.0, 1.0, 1.0 } } )
	local none  = ffi.new( "vec4", { { 0.0, 0.0, 0.0, 0.0 } } )

	local markup               = ffi.new( "markup_t" )
	markup.family              = ffi.cast( "char *", filename )
	markup.size                = size or 12
	markup.bold                = 0
	markup.italic              = 0
	markup.spacing             = 0.0
	markup.gamma               = 1.0
	markup.foreground_color    = white
	markup.background_color    = none
	markup.underline           = 0
	markup.underline_color     = white
	markup.overline            = 0
	markup.overline_color      = white
	markup.strikethrough       = 0
	markup.strikethrough_color = white
	markup.font                = freetypegl.font_manager_get_from_markup( fontManager, markup )
	self.markup                = markup

	local texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, texture )
	fontManager.atlas.id = texture[0]
	GL.glBindTexture( GL.GL_TEXTURE_2D, fontManager.atlas.id )

	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_BASE_LEVEL, 0 )
	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAX_LEVEL, 0 )

	GL.glTexImage2D( GL.GL_TEXTURE_2D, 0, GL.GL_RED, fontManager.atlas.width,
		fontManager.atlas.height, 0, GL.GL_RED, GL.GL_UNSIGNED_BYTE,
		fontManager.atlas.data )

	setproxy( self )
end

function font:print( text, x, y, r, sx, sy, ox, oy, kx, ky )
	freetypegl.text_buffer_clear( self.buffer )
	framework.graphics.updateTransform()
	local pen = ffi.new( "vec2", { { x, y } } )
	freetypegl.text_buffer_add_text( self.buffer, pen, self.markup, text, #text )
	GL.glBindTexture( GL.GL_TEXTURE_2D, self.fontManager.atlas.id )
	-- freetypegl.vertex_buffer_render( self.buffer.buffer, GL.GL_TRIANGLES )
	local vertices  = self.buffer.buffer.vertices
	local shader    = framework.graphics.getShader()
	local vertex    = GL.glGetAttribLocation( shader, "vertex" )
	GL.glVertexAttribPointer( vertex, 2, GL.GL_FLOAT, 0, 0, vertices.items )
	GL.glDrawArrays( GL.GL_TRIANGLES, 0, vertices.size )
end

function font:__gc()
	GL.glDeleteTextures( 1, self.fontManager.atlas.id )
	self.fontManager.atlas.id = 0
	freetypegl.text_buffer_delete( self.buffer )
	freetypegl.font_manager_delete( self.fontManager )
end
