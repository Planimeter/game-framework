--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local AL = require( "openal" )
require( "framework.sound" )

local framework = framework

module( "framework.audio" )

device = device or AL.alcOpenDevice( nil )
context = context or AL.alcCreateContext( device, nil )
AL.alcMakeContextCurrent( context )

function newSource( filename )
	local sound = framework.sound
	return sound( filename )
end

function play( source )
	source:play()
end
