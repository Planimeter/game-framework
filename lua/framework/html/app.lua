--=========== Copyright © 2020, Planimeter, All rights reserved. ===========--
--
-- Purpose:
--
--==========================================================================--

require( "class" )
local ffi = require( "ffi" )

class( "framework.html.browser" )

local browser = framework.html.browser
local toutf16 = framework.html.toutf16

local function on_register_custom_schemes( self, registrar )
	registrar.add_custom_scheme(
		registrar,
		toutf16( "client" ),
		1,
		1,
		1,
		1,
		1,
		1
	)
end

jit.off( on_register_custom_schemes, true )

local function get_browser_process_handler( self )
	local func = function( app )
		return self.processHandler
	end
	jit.off( func, true )
	return func
end

function browser:initializeApp()
	local app = ffi.new( "cef_app_t" )
	app.base.size = ffi.sizeof( app )
	app.on_register_custom_schemes  = on_register_custom_schemes
	app.get_browser_process_handler = get_browser_process_handler( self )
	self.app = app
end
