--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )

class( "framework.html.browser" )

local browser = framework.html.browser

local function get_context_menu_handler( self )
    return nil
end

local function get_dialog_handler( self )
    return nil
end

local function get_display_handler( self )
    return nil
end

local function get_download_handler( self )
    return nil
end

local function get_drag_handler( self )
    return nil
end

local function get_focus_handler( self )
    return nil
end

local function get_geolocation_handler( self )
    return nil
end

local function get_jsdialog_handler( self )
    return nil
end

local function get_keyboard_handler( self )
    return nil
end

local function get_life_span_handler( self )
    local function getLifeSpanHandler( handler )
        return self.lifeSpanHandler
    end
    jit.off( getLifeSpanHandler )
    return getLifeSpanHandler
end

local function get_load_handler( self )
    return nil
end

local function get_render_handler( self )
    local function getRenderHandler( handler )
        return self.renderHandler
    end
    jit.off( getRenderHandler )
    return getRenderHandler
end

local function get_request_handler( self )
    return nil
end

local function on_process_message_received( self, browser, source_process, message )
    return 0
end

function browser:initializeClient( client )
    local client = ffi.new( "cef_client_t" )
    client.base.size = ffi.sizeof( client )
    self:implementRefCounting( client )
    client.get_context_menu_handler    = get_context_menu_handler
    client.get_dialog_handler          = get_dialog_handler
    client.get_display_handler         = get_display_handler
    client.get_download_handler        = get_download_handler
    client.get_drag_handler            = get_drag_handler
    client.get_focus_handler           = get_focus_handler
    client.get_geolocation_handler     = get_geolocation_handler
    client.get_jsdialog_handler        = get_jsdialog_handler
    client.get_keyboard_handler        = get_keyboard_handler
    client.get_life_span_handler       = get_life_span_handler( self )
    client.get_load_handler            = get_load_handler
    client.get_render_handler          = get_render_handler( self )
    client.get_request_handler         = get_request_handler
    client.on_process_message_received = on_process_message_received
    self.client = client
end
