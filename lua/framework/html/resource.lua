--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )

class( "framework.html.browser" )

local browser = framework.html.browser

local function process_request( self, request, callback )
	-- TODO: Handle request.
	return 0
end

function browser:initializeResourceHandler()
	local handler = ffi.new( "cef_resource_handler_t" )
	handler.base.size = ffi.sizeof( handler )
	handler.process_request = process_request
	self.resourceHandler = handler
end
