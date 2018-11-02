--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )

class( "framework.html.browser" )

local browser = framework.html.browser

local function get_life_span_handler( self )
	local func = function( client )
		return self.lifeSpanHandler
	end
	jit.off( func, true )
	return func
end

local function get_render_handler( self )
	local func = function( client )
		return self.renderHandler
	end
	jit.off( func, true )
	return func
end

function browser:initializeClient()
	local client = ffi.new( "cef_client_t" )
	client.base.size = ffi.sizeof( client )
	client.get_life_span_handler = get_life_span_handler( self )
	client.get_render_handler    = get_render_handler( self )
	self.client = client
end
