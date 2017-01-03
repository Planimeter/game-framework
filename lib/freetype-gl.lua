--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( "lib/freetype-gl.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "freetype-gl" )
