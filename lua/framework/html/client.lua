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
	return function( handler )
		return self.lifeSpanHandler
	end
end

local function get_render_handler( self )
	return function( handler )
		return self.renderHandler
	end
end

function browser:initializeClient( client )
	local client = ffi.new( "cef_client_t" )
	client.base.size = ffi.sizeof( client )
	client.get_life_span_handler = get_life_span_handler( self )
	client.get_render_handler    = get_render_handler( self )
	self.client = client
end
