--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( framework.execdir .. "include/kazmath.h" )
ffi.cdef( io.read( "*all" ) )

local kazmath = ffi.load(
	ffi.os == "Windows" and "kazmath" or framework.execdir .. "bin/libkazmath.dylib"
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

function _M.kmMat4ReversedZPerspectiveProjection(pOut, fovY,
                                                 aspect, zNear)
	local r = kazmath.kmDegreesToRadians(fovY / 2)
	local c = math.cos(r)
	local tangent = 0

	if (c == 0 or aspect == 0) then
		return nil
	end

	--[[sin(r) / cos(r) = tan(r)]]
	tangent = math.sin(r) / c

	kazmath.kmMat4Identity(pOut)
	pOut.mat[0] = 1 / tangent / aspect
	pOut.mat[5] = 0
	pOut.mat[10] = 0
	pOut.mat[11] = -1
	pOut.mat[14] = zNear
	pOut.mat[15] = 0

	return pOut
end

function _M.kmMat4Transform( pOut, x, y, angle, sx, sy, ox, oy, kx, ky )
	local c, s = math.cos(angle), math.sin(angle)
	-- matrix multiplication carried out on paper:
	-- |1     x| |c -s    | |sx       | | 1 ky    | |1     -ox|
	-- |  1   y| |s  c    | |   sy    | |kx  1    | |  1   -oy|
	-- |    1  | |     1  | |      1  | |      1  | |    1    |
	-- |      1| |       1| |        1| |        1| |       1 |
	--   move      rotate      scale       skew       origin	pOut.mat[10] = pOut.mat[15] = 1.0
	pOut.mat[0]  = c * sx - ky * s * sy -- = a
	pOut.mat[1]  = s * sx + ky * c * sy -- = b
	pOut.mat[4]  = kx * c * sx - s * sy -- = c
	pOut.mat[5]  = kx * s * sx + c * sy -- = d
	pOut.mat[12] = x - ox * pOut.mat[0] - oy * pOut.mat[4]
	pOut.mat[13] = y - ox * pOut.mat[1] - oy * pOut.mat[5]
end

return setmetatable( _M, {
	__index = function( table, key )
		return kazmath[ key ]
	end
} )
