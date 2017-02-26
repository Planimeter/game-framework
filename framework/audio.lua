--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.sound" )
local AL = require( "openal" )

local framework = framework

module( "framework.audio" )

_device = _device or AL.alcOpenDevice( nil )
_context = _context or AL.alcCreateContext( _device, nil )
AL.alcMakeContextCurrent( _context )

function newSource( filename )
	local sound = framework.sound
	return sound( filename )
end

function play( source )
	source:play()
end
