--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( "include/cef_app_capi.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( ffi.os == "Windows" and "libcef" or "cef" )
