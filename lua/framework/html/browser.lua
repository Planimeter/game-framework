--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
require( "framework.graphics.image" )
local ffi = require( "ffi" )
local cef = require( "cef" )
local GL  = require( "opengl" )

local image = framework.graphics.image

class( "framework.html.browser" )

local browser = framework.html.browser

local function toutf16( s )
	local value = ffi.new( "cef_string_t" )
	cef.cef_string_utf8_to_utf16( s, string.len( s ), value )
	return value
end

framework.html.toutf16 = toutf16

function browser:browser( url, width, height )
	if ( not width and not height ) then
		width, height = framework.graphics.getSize()
	end

	require( "framework.html.app" )
	require( "framework.html.process" )
	require( "framework.html.scheme" )
	require( "framework.html.resource" )
	require( "framework.html.client" )
	require( "framework.html.lifespan" )
	require( "framework.html.rendering" )

	self.mainArgs = ffi.new( "cef_main_args_t" )

	self:initializeApp()
	self:initializeProcessHandler()
	self:initializeSchemeHandler()
	self:initializeResourceHandler()

	local settings        = ffi.new( "cef_settings_t" )
	settings.size         = ffi.sizeof( settings )
	settings.log_severity = ffi.C.LOGSEVERITY_WARNING
	settings.no_sandbox   = 1
	self.settings         = settings

	local browser_subprocess_path    = "bin\\cef.exe"
	settings.browser_subprocess_path = toutf16( browser_subprocess_path )

	local cwd                   = framework.filesystem.getWorkingDirectory()
	local resources_dir_path    = cwd .. "resources"
	settings.resources_dir_path = toutf16( resources_dir_path )

	local locales_dir_path    = cwd .. "resources\\locales"
	settings.locales_dir_path = toutf16( locales_dir_path )

	cef.cef_initialize( self.mainArgs, self.settings, self.app, nil )

	local windowInfo  = ffi.new( "cef_window_info_t" )
	windowInfo.width  = 0x80000000
	windowInfo.height = 0x80000000
	windowInfo.windowless_rendering_enabled = 1
	self.windowInfo   = windowInfo

	local browserSettings = ffi.new( "cef_browser_settings_t" )
	browserSettings.size  = ffi.sizeof( browserSettings )
	browserSettings.windowless_frame_rate = 60
	self.browserSettings  = browserSettings

	self:initializeClient()
	self:initializeLifeSpanHandler()

	self.texture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, self.texture )
	GL.glBindTexture( GL.GL_TEXTURE_2D, self.texture[0] )
	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_BASE_LEVEL, 0 )
	GL.glTexParameteri( GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAX_LEVEL, 0 )

	self.width  = width
	self.height = height
	self:initializeRenderHandler()

	self.browser = cef.cef_browser_host_create_browser_sync(
		self.windowInfo, self.client, toutf16( url ), self.browserSettings, nil
	)

	setproxy( self )
end

browser.draw = image.draw

function browser:resize( width, height )
	self.width  = width
	self.height = height

	local host  = self:getHost()
	host.was_resized( host )
end

function browser:keypressed( key, scancode, isrepeat )
	local host  = self:getHost()
	local event = ffi.new( "cef_key_event_t", {
		type = ffi.C.KEYEVENT_KEYDOWN
	} )
	host.send_key_event( host, event )
end

function browser:keyreleased( key, scancode )
	local host  = self:getHost()
	local event = ffi.new( "cef_key_event_t", {
		type = ffi.C.KEYEVENT_KEYUP
	} )
	host.send_key_event( host, event )
end

function browser:mousemoved( x, y, dx, dy, istouch )
	local host  = self:getHost()
	local event = ffi.new( "cef_mouse_event_t", {
		x = x,
		y = y
	} )
	host.send_mouse_move_event( host, event, 0 )
end

function browser:mousepressed( x, y, button, istouch )
	if ( button == 1 ) then
		button = ffi.C.MBT_LEFT
	elseif ( button == 2 ) then
		button = ffi.C.MBT_RIGHT
	elseif ( button == 3 ) then
		button = ffi.C.MBT_MIDDLE
	end

	local host  = self:getHost()
	local event = ffi.new( "cef_mouse_event_t", {
		x = x,
		y = y
	} )
	host.send_mouse_click_event( host, event, button, 0, 1 )
end

function browser:mousereleased( x, y, button, istouch )
	if ( button == 1 ) then
		button = ffi.C.MBT_LEFT
	elseif ( button == 2 ) then
		button = ffi.C.MBT_RIGHT
	elseif ( button == 3 ) then
		button = ffi.C.MBT_MIDDLE
	end

	local host  = self:getHost()
	local event = ffi.new( "cef_mouse_event_t", {
		x = x,
		y = y
	} )
	host.send_mouse_click_event( host, event, button, 1, 0 )
end

function browser:wheelmoved( x, y )
	local host  = self:getHost()
	local event = ffi.new( "cef_mouse_event_t", {
		x = x,
		y = y
	} )
	host.send_mouse_wheel_event( host, event, x, y )
end

function browser:getHost()
	local browser = self.browser
	local host    = browser.get_host( browser )
	return host
end

function browser:__gc()
	GL.glDeleteTextures( 1, self.texture )
end
