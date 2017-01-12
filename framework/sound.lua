--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local AL = require( "openal" )
local SDL_sound = require( "SDL_sound" )
require( "class" )
local ffi = require( "ffi" )

SDL_sound.Sound_Init()

class( "framework.sound" )

local sound = framework.sound

function sound:sound( filename )
	self.source = ffi.new( "ALuint[1]" )
	AL.alGenSources( 1, self.source )

	self.buffer = ffi.new( "ALuint[1]" )
	AL.alGenBuffers( 1, self.buffer )

	self.sample = SDL_sound.Sound_NewSampleFromFile( filename, nil, 10240 )

	setproxy( self )
end

function sound:play()
	AL.alSourcePlay( self.source )
end

function sound:__gc()
	SDL_sound.Sound_FreeSample( self.sample )
	AL.alDeleteBuffers( 1, self.buffer )
	AL.alDeleteSources( 1, self.source )
end
