--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )

module( "framework.timer" )

frames        = frames        or 0
lastTime      = lastTime      or 0
fps           = fps           or 0
nextFPSUpdate = nextFPSUpdate or 0
lastFPSUpdate = lastFPSUpdate or 0

function sleep( seconds )
	SDL.SDL_Delay( seconds * 1000 )
end

function getFPS()
	return fps
end

function getTime()
	return SDL.SDL_GetTicks()
end

function update()
	frames = frames + 1

	local time = getTime()
	local dt = time - lastTime
	lastTime = time

	if ( nextFPSUpdate <= time ) then
		fps = frames
		nextFPSUpdate = time + ( 1 * 1000 )
		lastFPSUpdate = time
		frames = 0
	end

	return dt
end
