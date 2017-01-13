--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL_sound = require( "sdl_sound" )
require( "class" )
local AL  = require( "openal" )
local SDL = require( "sdl" )
local ffi = require( "ffi" )

SDL_sound.Sound_Init()

class( "framework.sound" )

local sound = framework.sound

function sound.getAvailableDecoders()
	local i = 0
	local v = nil
	local decoders = SDL_sound.Sound_AvailableDecoders()
	local t = {}
	repeat
		v = decoders[ i ]
		if ( v ~= nil ) then
			table.insert( t, v )
		end
		i = i + 1
	until ( v == nil )
	return t
end

local function getFormat( channels, type )
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

	local buffer, length = framework.filesystem.read( filename )
	local rw = SDL.SDL_RWFromMem( buffer, length )
	local sample = SDL_sound.Sound_NewSample( rw, nil, nil, 10240 )
	if ( sample == nil ) then
		error( "Could not load sound '" .. filename .. "'", 3 )
	end
	self.sample = sample

	local info   = sample.actual
	local format = getFormat( info.channels, info.format )
	local size   = SDL_sound.Sound_DecodeAll( sample )
	local data   = sample.buffer
	local freq   = info.rate
	AL.alBufferData( self.buffer[0], format, data, size, freq )

	setproxy( self )
end

function sound:play()
	AL.alSourcei( self.source[0], AL.AL_BUFFER, self.buffer[0] )
	AL.alSourcePlay( self.source[0] )
end

function sound:stop()
	AL.alSourceStop( self.source[0] )
end

function sound:__gc()
	SDL_sound.Sound_FreeSample( self.sample )
	AL.alDeleteBuffers( 1, self.buffer )
	AL.alDeleteSources( 1, self.source )
end
