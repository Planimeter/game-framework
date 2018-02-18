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

local function toutf16( s )
	local value = ffi.new( "cef_string_t" )
	cef.cef_string_utf8_to_utf16( s, string.len( s ), value )
	return value
end

function browser:browser( url )
	require( "framework.html.referencecounting" )
	require( "test.cef_client" )
	require( "test.cef_life_span_handler" )
	require( "test.cef_render_handler" )

	g_life_span_handler = ffi.new( "cef_life_span_handler_t" )
	g_render_handler    = ffi.new( "cef_render_handler_t" )

	local main_args = ffi.new( "cef_main_args_t" )
	local app       = ffi.new( "cef_app_t" )

	local settings        = ffi.new( "cef_settings_t" )
	settings.size         = ffi.sizeof( settings )
	settings.log_severity = ffi.C.LOGSEVERITY_WARNING
	settings.no_sandbox   = 1

	local browser_subprocess_path    = "cef.exe"
	settings.browser_subprocess_path = toutf16( browser_subprocess_path )

	cef.cef_initialize( main_args, settings, app, nil )

	local window_info = ffi.new( "cef_window_info_t" )
	window_info.width = 0x80000000
	window_info.height = 0x80000000
	window_info.windowless_rendering_enabled = 1

	local browser_settings = ffi.new( "cef_browser_settings_t" )
	browser_settings.size  = ffi.sizeof( browser_settings )

	local client = ffi.new( "cef_client_t" )
	initialize_cef_client( client )
	initialize_cef_life_span_handler( g_life_span_handler )
	initialize_cef_render_handler( g_render_handler )

	cef.cef_browser_host_create_browser( window_info, client, toutf16( url ),
	                                     browser_settings, nil )

	setproxy( self )
end

function browser:draw( x, y, r, sx, sy, ox, oy, kx, ky )
end

function browser:__gc()
end
