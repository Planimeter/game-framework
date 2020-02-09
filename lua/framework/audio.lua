--=========== Copyright © 2020, Planimeter, All rights reserved. ===========--
--
-- Purpose:
--
--==========================================================================--

require( "framework.sound" )
local AL = require( "openal" )

local framework = framework

module( "framework.audio" )

_device  = _device  or AL.alcOpenDevice( nil )
_context = _context or AL.alcCreateContext( _device, nil )
AL.alcMakeContextCurrent( _context )

function newSource( filename )
	local sound = framework.sound
	return sound( filename )
end

function play( source )
	source:play()
end

function setVolume( volume )
	AL.alListenerf( AL.AL_GAIN, volume )
end

function getVolume()
	local volume = ffi.new( "ALfloat[1]" )
	AL.alGetListenerf( AL.AL_GAIN, volume[0] )
	return volume
end

function quit()
	AL.alcCloseDevice( _device )
end
