--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( "include/al.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "OpenAL.framework/OpenAL" )
