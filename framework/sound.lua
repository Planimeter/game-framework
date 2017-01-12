--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL_sound = require( "SDL_sound" )
require( "class" )
local ffi = require( "ffi" )

SDL_sound.Sound_Init()

class( "framework.sound" )

local sound = framework.sound

function sound:sound( filename )
	self.info   = ffi.new( "Sound_AudioInfo[1]" )
	self.sample = SDL_sound.Sound_NewSampleFromFile( filename, self.info, 10240 )
	setproxy( self )
end

function sound:__gc()
	SDL_sound.Sound_FreeSample( self.sample )
end
