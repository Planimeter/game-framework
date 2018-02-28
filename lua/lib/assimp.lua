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
		        mat.a1, mat.a2, mat.a3, mat.a4 .. "\n",
		"\r" .. mat.b1, mat.b2, mat.b3, mat.b4 .. "\n",
		"\r" .. mat.c1, mat.c2, mat.c3, mat.c4 .. "\n",
		"\r" .. mat.d1, mat.d2, mat.d3, mat.d4
	)
end

return setmetatable( _M, {
	__index = function( table, key )
		return assimp[ key ]
	end
} )
