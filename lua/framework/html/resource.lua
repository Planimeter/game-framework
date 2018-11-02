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
local toutf8  = framework.html.toutf8

local function process_request( self, request, callback )
	local tmp = request.get_url( request )
	local url = toutf8( tmp )
	url = string.gsub( url, "client://lgf/", "" )
	ffi.C.printf( "%s\n", url )
	cef.cef_string_userfree_utf16_free( tmp )
	return 0
end

function browser:initializeResourceHandler()
	local handler = ffi.new( "cef_resource_handler_t" )
	handler.base.size = ffi.sizeof( handler )
	handler.process_request = process_request
	self.resourceHandler = handler
end
