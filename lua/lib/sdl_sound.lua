--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( package.cwd .. "/include/SDL_sound.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "SDL_sound" )
