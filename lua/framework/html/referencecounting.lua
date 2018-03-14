--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local ffi = require( "ffi" )

class( "framework.html.browser" )

local browser = framework.html.browser

local function add_ref( self )
end

local function release( self )
	return 1
end

local function has_one_ref( self )
	return 1
end

function browser:implementRefCounting( base )
	base = ffi.cast( "cef_base_ref_counted_t*", base )
	local size = base.size
	if ( size <= 0 ) then
		error( "initialize_cef_base failed, size member not set" )
	end
	base.add_ref     = add_ref
	base.release     = release
	base.has_one_ref = has_one_ref
end
