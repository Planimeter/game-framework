--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( framework.path .. "include/kazmath.h" )
ffi.cdef( io.read( "*all" ) )

local kazmath = ffi.load(
	ffi.os == "Windows" and "kazmath" or framework.cpath .. "libkazmath.dylib"
)
local _M = {}

function _M.kmMat4Print( pOut )
	local mat = pOut.mat
	print(
		        mat[0],  mat[1],  mat[2],  mat[3]  .. "\n",
		"\r" .. mat[4],  mat[5],  mat[6],  mat[7]  .. "\n",
		"\r" .. mat[8],  mat[9],  mat[10], mat[11] .. "\n",
		"\r" .. mat[12], mat[13], mat[14], mat[15]
	)
end

return setmetatable( _M, {
	__index = function( table, key )
		return kazmath[ key ]
	end
} )
