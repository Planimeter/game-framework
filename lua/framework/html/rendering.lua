--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )
local cef = require( "cef" )
local GL  = require( "opengl" )

class( "framework.html.browser" )

local browser = framework.html.browser

local function get_view_rect( self )
	local func = function( handler, browser, rect )
		rect[0] = ffi.new( "cef_rect_t", 0, 0, self.width, self.height )
		return 1
	end
	jit.off( func, true )
	return func
end

local function on_paint( self )
	local func = function(
		handler,
		browser,
		type,
		dirtyRectsCount,
		dirtyRects,
		buffer,
		width,
		height
	)
		assert( cef.cef_currently_on( ffi.C.TID_UI ) )

		GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )
		GL.glTexImage2D(
			GL.GL_TEXTURE_2D,
			0,
			GL.GL_RGBA,
			width,
			height,
			0,
			GL.GL_BGRA,
			GL.GL_UNSIGNED_INT_8_8_8_8_REV,
			buffer
		)
	end
	jit.off( func, true )
	return func
end

function browser:initializeRenderHandler()
	local handler = ffi.new( "cef_render_handler_t" )
	handler.base.size = ffi.sizeof( handler )
	handler.get_view_rect = get_view_rect( self )
	handler.on_paint = on_paint( self )
	self.renderHandler = handler
end
