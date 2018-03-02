--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

jit.off()

require( "framework.html.browser" )
local cef = require( "cef" )
local jit = require( "jit" )

local framework = framework

module( "framework.html" )

function newBrowser( url )
	local browser = framework.html.browser
	return browser( url )
end

function update( dt )
	cef.cef_do_message_loop_work()
end

jit.off( update )

function quit()
	cef.cef_shutdown()
end
