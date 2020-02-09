--=========== Copyright © 2020, Planimeter, All rights reserved. ===========--
--
-- Purpose:
--
--==========================================================================--

local ffi = require( "ffi" )
io.input( framework.execdir .. "include/chipmunk.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "chipmunk" )
