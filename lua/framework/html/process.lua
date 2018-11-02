--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )
local cef = require( "cef" )

class( "framework.html.browser" )

local browser = framework.html.browser
local toutf16 = framework.html.toutf16

local function on_context_initialized( self )
	return function( handler )
		cef.cef_register_scheme_handler_factory(
			toutf16( "client" ), toutf16( "lgf" ), self.schemeHandler
		)
	end
end

function browser:initializeProcessHandler()
	local handler = ffi.new( "cef_browser_process_handler_t" )
	handler.base.size = ffi.sizeof( handler )
	handler.on_context_initialized = on_context_initialized( self )
	self.processHandler = handler
end
