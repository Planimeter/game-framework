--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi  = require( "ffi" )
local name = nil
if ( jit.os == "Windows" ) then
	name = "OpenGL32"
	io.input( "lib/gl3.h" )
elseif ( jit.os == "OSX" ) then
	name = "OpenGL.framework/OpenGL"
	io.input( "lib/gl3.h" )
else
	name = "GL"
end

ffi.cdef( io.read( "*all" ) )
return ffi.load( name )
