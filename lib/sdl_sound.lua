--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( framework.execdir .. "include/SDL_sound.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "SDL_sound" )
