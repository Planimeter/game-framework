--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( framework.execdir .. "include/freetype.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "freetype" )
