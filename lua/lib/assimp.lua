--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( framework.path .. "include/assimp.h" )
ffi.cdef( io.read( "*all" ) )

local assimp = ffi.load( "assimp" )
local _M     = {}

function _M.aiPrintMatrix4( mat )
	print(
		        a1, a2, a3, a4 .. "\n",
		"\r" .. b1, b2, b3, b4 .. "\n",
		"\r" .. c1, c2, c3, c4 .. "\n",
		"\r" .. d1, d2, d3, d4
	)
end

return setmetatable( _M, {
	__index = function( table, key )
		return assimp[ key ]
	end
} )
