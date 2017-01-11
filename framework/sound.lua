--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "class" )
local sndfile = require( "sndfile" )
local ffi     = require( "ffi" )

class( "framework.graphics.sound" )

local sound = framework.graphics.sound

function sound:sound( filename )
	self.info = ffi.new( "SF_INFO[1]" )
	self.file = sndfile.sf_open( filename, ffi.C.SFM_READ, self.info )
	setproxy( self )
end

function sound:__gc()
	sndfile.sf_close( self.file )
end
