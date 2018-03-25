--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "sdl" )

module( "framework.timer" )

_frames        = _frames        or 0
_dt            = _dt            or 0
_lastTime      = _lastTime      or 0
_fps           = _fps           or 0
_averageDelta  = _averageDelta  or 0
_nextFPSUpdate = _nextFPSUpdate or 0
_lastFPSUpdate = _lastFPSUpdate or 0

function getAverageDelta()
	return _averageDelta
end

function getDelta()
	return _dt
end

function getFPS()
	return _fps
end

function getTime()
	return SDL.SDL_GetTicks()
end

function sleep( seconds )
	SDL.SDL_Delay( seconds * 1000 )
end

function step()
	_frames = _frames + 1

	local time = getTime()
	_dt = time - _lastTime
	_lastTime = time

	if ( _nextFPSUpdate <= time ) then
		_fps = _frames
		_averageDelta = ( time - _lastFPSUpdate ) / _frames
		_nextFPSUpdate =  time + ( 1 * 1000 )
		_lastFPSUpdate =  time
		_frames = 0
	end

	return _dt
end
