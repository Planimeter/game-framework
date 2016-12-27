--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local kazmath = require( "lib.kazmath" )
local ffi     = require( "ffi" )

module( "framework.math" )

function newMat4()
	return ffi.new( "kmMat4" )
end
