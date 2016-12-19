--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( "gl.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "/System/Library/Frameworks/OpenGL.framework/Libraries/libGL.dylib" )
