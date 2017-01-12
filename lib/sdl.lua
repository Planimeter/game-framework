--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
local bit = require( "bit" )

local bor  = bit.bor
local band = bit.band

io.input( "include/SDL.h" )
ffi.cdef( io.read( "*all" ) )

local SDL = ffi.load( "SDL2" )

local function SDL_WINDOWPOS_UNDEFINED_DISPLAY(X)
	return (bor(0x1FFF0000,(X)))
end

local function SDL_WINDOWPOS_ISUNDEFINED(X)
	return (band((X),0xFFFF0000) == SDL_WINDOWPOS_UNDEFINED_MASK)
end

local _M = {
	--[[
	 *  \name Audio format flags
	 *
	 *  Defaults to LSB byte order.
	 ]]
	AUDIO_U8        = 0x0008,  --[[< Unsigned 8-bit samples ]]
	AUDIO_S8        = 0x8008,  --[[< Signed 8-bit samples ]]
	AUDIO_U16LSB    = 0x0010,  --[[< Unsigned 16-bit samples ]]
	AUDIO_S16LSB    = 0x8010,  --[[< Signed 16-bit samples ]]
	AUDIO_U16MSB    = 0x1010,  --[[< As above, but big-endian byte order ]]
	AUDIO_S16MSB    = 0x9010,  --[[< As above, but big-endian byte order ]]
	AUDIO_U16       = 0x0010,
	AUDIO_S16       = 0x8010,

	--[[ Used as the device ID for mouse events simulated with touch input ]]
	SDL_TOUCH_MOUSEID = (-1),

	--[[
	 *  \brief Used to indicate that you don't care what the window position is.
	 ]]
	SDL_WINDOWPOS_UNDEFINED_MASK    = 0x1FFF0000,
	SDL_WINDOWPOS_UNDEFINED_DISPLAY = SDL_WINDOWPOS_UNDEFINED_DISPLAY,
	SDL_WINDOWPOS_UNDEFINED         = SDL_WINDOWPOS_UNDEFINED_DISPLAY(0),
	SDL_WINDOWPOS_ISUNDEFINED       = SDL_WINDOWPOS_ISUNDEFINED,

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
	SDL_INIT_NOPARACHUTE    = 0x00100000   --[[< compatibility; this flag is ignored. ]]
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
