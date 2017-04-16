--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( framework.path .. "include/kazmath.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( ffi.os == "Windows" and "kazmath" or framework.cpath .. "libkazmath.dylib" )
