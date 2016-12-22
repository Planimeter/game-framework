--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( "lib/glcorearb.h" )
ffi.cdef( io.read( "*all" ) )

local _M = {}
return setmetatable( _M, {
	__index = function( table, key )
		local proc = "gl" .. key
		local ct   = "PFNGL" .. string.upper( key ) .. "PROC"
		local cdata = ffi.cast( ct, SDL.SDL_GL_GetProcAddress( proc ) )
		_M[ key ] = cdata
		return cdata
	end
} )
