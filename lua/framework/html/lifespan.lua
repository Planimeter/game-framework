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

local function on_before_close( self, browser )
	cef.cef_quit_message_loop()
end

function browser:initializeLifeSpanHandler()
	local handler = ffi.new( "cef_life_span_handler_t" )
	handler.base.size = ffi.sizeof( handler )
	self:implementRefCounting( handler )
	handler.on_before_close = on_before_close
	self.lifeSpanHandler = handler
end
