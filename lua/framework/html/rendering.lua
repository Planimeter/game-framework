--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )
local GL  = require( "opengl" )

class( "framework.html.browser" )

local browser = framework.html.browser

local function get_view_rect( self )
	return function( handler, browser, rect )
		rect[0] = ffi.new( "cef_rect_t", 0, 0, self.width, self.height )
		return 1
	end
end

local function on_paint( self )
	return function(
		handler,
		browser,
		type,
		dirtyRectsCount,
		dirtyRects,
		buffer,
		width,
		height
	)
		GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )
		GL.glTexImage2D(
			GL.GL_TEXTURE_2D,
			0,
			GL.GL_RGBA,
			width,
			height,
			0,
			GL.GL_BGRA_EXT or 0x80E1,
			GL.GL_UNSIGNED_BYTE,
			buffer
		)
	end
end

function browser:initializeRenderHandler()
	local handler = ffi.new( "cef_render_handler_t" )
	handler.base.size = ffi.sizeof( handler )
	self:implementRefCounting( handler )
	handler.get_view_rect = get_view_rect( self )
	handler.on_paint = on_paint( self )
	self.renderHandler = handler
end
