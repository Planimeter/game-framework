--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( framework.path .. "include/cimport.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "assimp" )
