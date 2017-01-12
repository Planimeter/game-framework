--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local AL = require( "openal" )
local SDL = require( "SDL" )
local SDL_sound = require( "SDL_sound" )
require( "class" )
local ffi = require( "ffi" )

SDL_sound.Sound_Init()

class( "framework.sound" )

local sound = framework.sound

function sound.getFormat( channels, type )
	local format = AL.AL_NONE

	if ( type == SDL.AUDIO_U8 ) then
		if ( channels == 1 ) then
			format = AL.AL_FORMAT_MONO8
		elseif ( channels == 2 ) then
			format = AL.AL_FORMAT_STEREO8
		end
	elseif ( type == SDL.AUDIO_S16LSB or type == SDL.AUDIO_S16MSB ) then
		if ( channels == 1 ) then
			format = AL.AL_FORMAT_MONO16
		elseif ( channels == 2 ) then
			format = AL.AL_FORMAT_STEREO16
		end
	end

	return format
end

function sound:sound( filename )
	self.source = ffi.new( "ALuint[1]" )
	AL.alGenSources( 1, self.source )

	self.buffer = ffi.new( "ALuint[1]" )
	AL.alGenBuffers( 1, self.buffer )

	local sample = SDL_sound.Sound_NewSampleFromFile( filename, nil, 10240 )
	self.sample = sample

	local info   = sample.actual
	local format = sound.format( info.channels, info.format )
	local size   = SDL_sound.Sound_DecodeAll( sample )
	local data   = sample.buffer
	local freq   = info.rate
	AL.alBufferData( self.buffer, format, data, size, freq )

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
