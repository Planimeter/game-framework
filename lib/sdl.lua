--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( "SDL.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "SDL2" )
