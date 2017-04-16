--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( package.cwd .. "/include/kazmath.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "kazmath" )
