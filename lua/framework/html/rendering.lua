--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )
local cef = require( "cef" )

class( "framework.html.browser" )

local browser = framework.html.browser

local function get_view_rect( self, browser, rect )
	local _rect = ffi.new( "cef_rect_t", { 0, 0, 800, 600 } )
	ffi.copy( rect, _rect, ffi.sizeof( _rect ) )
	return 1
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
	end
end

function browser:initializeRenderHandler()
	local handler = ffi.new( "cef_render_handler_t" )
	handler.base.size = ffi.sizeof( handler )
	self:implementRefCounting( handler )
	handler.get_view_rect = get_view_rect
	handler.on_paint = on_paint( self )
	self.renderHandler = handler
end
