--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
local bit = require( "bit" )

local bor = bit.bor

io.input( "lib/SDL.h" )
ffi.cdef( io.read( "*all" ) )

local SDL = ffi.load( "SDL2" )
local _M  = {
	--[[
	 *  \name SDL_INIT_*
	 *
	 *  These are the flags which may be passed to SDL_Init().  You should
	 *  specify the subsystems which you will be using in your application.
	 ]]
	SDL_INIT_TIMER          = 0x00000001,
	SDL_INIT_AUDIO          = 0x00000010,
	SDL_INIT_VIDEO          = 0x00000020,  --[[< SDL_INIT_VIDEO implies SDL_INIT_EVENTS ]]
	SDL_INIT_JOYSTICK       = 0x00000200,  --[[< SDL_INIT_JOYSTICK implies SDL_INIT_EVENTS ]]
	SDL_INIT_HAPTIC         = 0x00001000,
	SDL_INIT_GAMECONTROLLER = 0x00002000,  --[[< SDL_INIT_GAMECONTROLLER implies SDL_INIT_JOYSTICK ]]
	SDL_INIT_EVENTS         = 0x00004000,
	SDL_INIT_NOPARACHUTE    = 0x00100000,  --[[< compatibility; this flag is ignored. ]]
}
_M.SDL_INIT_EVERYTHING = bor(
                _M.SDL_INIT_TIMER, _M.SDL_INIT_AUDIO, _M.SDL_INIT_VIDEO, _M.SDL_INIT_EVENTS,
                _M.SDL_INIT_JOYSTICK, _M.SDL_INIT_HAPTIC, _M.SDL_INIT_GAMECONTROLLER
            )

return setmetatable( _M, {
	__index = function( table, key )
		return SDL[ key ]
	end
} )
