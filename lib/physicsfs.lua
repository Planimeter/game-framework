--=========== Copyright © 2020, Planimeter, All rights reserved. ===========--
--
-- Purpose:
--
--==========================================================================--

local ffi = require( "ffi" )
io.input( framework.execdir .. "include/physfs.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "physfs" )
