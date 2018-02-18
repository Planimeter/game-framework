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
	require( "framework.html.client" )
	require( "framework.html.lifespan" )
	require( "framework.html.rendering" )

	self.mainArgs         = ffi.new( "cef_main_args_t" )
	self.app              = ffi.new( "cef_app_t" )
	local settings        = ffi.new( "cef_settings_t" )
	settings.size         = ffi.sizeof( settings )
	settings.log_severity = ffi.C.LOGSEVERITY_WARNING
	settings.no_sandbox   = 1
	self.settings         = settings

	local browser_subprocess_path    = "cef.exe"
	settings.browser_subprocess_path = toutf16( browser_subprocess_path )

	cef.cef_initialize( self.mainArgs, self.settings, self.app, nil )

	local windowInfo  = ffi.new( "cef_window_info_t" )
	windowInfo.width  = 0x80000000
	windowInfo.height = 0x80000000
	windowInfo.windowless_rendering_enabled = 1
	self.windowInfo   = windowInfo

	local browserSettings = ffi.new( "cef_browser_settings_t" )
	browserSettings.size  = ffi.sizeof( browserSettings )
	self.browserSettings  = browserSettings

	self:initializeClient()
	self:initializeLifeSpanHandler()
	self:initializeRenderHandler()

	cef.cef_browser_host_create_browser( self.windowInfo, self.client,
	                                     toutf16( url ),
	                                     self.browserSettings, nil )

	setproxy( self )
end

function browser:draw( x, y, r, sx, sy, ox, oy, kx, ky )
end

function browser:__gc()
end
