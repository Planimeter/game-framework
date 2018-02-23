--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( framework.path .. "include/assimp.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "assimp" )
