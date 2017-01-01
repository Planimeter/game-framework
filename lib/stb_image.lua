--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( "lib/stb_image.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "stb_image" )
