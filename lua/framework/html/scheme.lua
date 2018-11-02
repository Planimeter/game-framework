--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )

class( "framework.html.browser" )

local browser = framework.html.browser
local toutf16 = framework.html.toutf16

local function create( self )
	return function( handler, browser, frame, scheme_name, request )
		return self.resourceHandler
	end
end

function browser:initializeSchemeHandler()
	local handler = ffi.new( "cef_scheme_handler_factory_t" )
	handler.base.size = ffi.sizeof( handler )
	handler.create = create( self )
	self.schemeHandler = handler
end
