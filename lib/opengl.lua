--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
local SDL = require( "lib.sdl" )
io.input( "lib/glcorearb.h" )
ffi.cdef( io.read( "*all" ) )

local _M = {}
return setmetatable( _M, {
	__index = function( table, key )
		local ct    = "PFN" .. string.upper( key ) .. "PROC"
		local cdata = ffi.cast( ct, SDL.SDL_GL_GetProcAddress( key ) )
		_M[ key ]   = cdata
		return cdata
	end
} )
