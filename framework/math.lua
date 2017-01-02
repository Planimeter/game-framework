--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local kazmath = require( "lib.kazmath" )
local ffi     = require( "ffi" )

module( "framework.math" )

function newMat4( mat )
	local mat4 = ffi.new( "kmMat4" )
	if ( mat ) then
		kazmath.kmMat4Fill( mat4, mat )
	end
	return mat4
end
