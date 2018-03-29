--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

--[[
 * Copyright (c) 2006-2018 LOVE Development Team
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 ]]

local GL        = require( "opengl" )
local ffi       = require( "ffi" )

local jit       = jit
local print     = print
local require   = require
local type      = type

local framework = framework
_G.love         = framework

local function notimplemented( key, level )
	level = level or 2
	local ar = debug.getinfo( level, "Sl" )  --[[ get info about it ]]
	local ret = nil
	if ( ar.currentline > 0 ) then  --[[ is there info? ]]
		ret = string.format( "%s: %s:%d: " ..
		                     "attempt to index nil value '%s' " ..
		                     "(not implemented)", arg[ -1 ],
		                     ar.short_src, ar.currentline, key )
	end
	print( debug.traceback( ret, level ) )
end

local function love_audio()
	module( "love.audio" )

	function setVolume()
		notimplemented( "setVolume", 3 )
	end

	return _M
end

local function love_filesystem()
	module( "love.filesystem" )

	function getRequirePath()
		return "./?.lua;lua/?.lua;lua/?/init.lua;"
	end

	function lines()
		notimplemented( "lines", 3 )
		return function() end, {}, nil
	end

	function setIdentity()
		notimplemented( "setIdentity", 3 )
	end

	return _M
end

local function love_graphics()
	require( "framework.graphics" )

	module( "love.graphics" )

	_blendMode = _blendMode or "alpha"
	_alphaMode = _alphaMode or "alphamultiply"

	function getBlendMode()
		return _blendMode, _alphaMode
	end

	function getCanvas()
		return framework.graphics.getFramebuffer()
	end

	function getWidth()
		local width, height = framework.graphics.getSize()
		return width
	end

	function getHeight()
		local width, height = framework.graphics.getSize()
		return height
	end

	function newCanvas( width, height )
		return framework.graphics.newFramebuffer( "color", width, height )
	end

	function printf( ... )
		framework.graphics.print( ... )
		notimplemented( "printf", 3 )
	end

	_setBackgroundColor = _setBackgroundColor or framework.graphics.setBackgroundColor

	function setBackgroundColor( r, g, b, a )
		if ( type( r ) ~= "table" ) then
			_setBackgroundColor( { r, g, b, a } )
			return
		end
		_setBackgroundColor( r )
	end

	function setBlendMode( mode, alphamode )
		alphamode = alphamode or "alphamultiply"
		local func   = GL.GL_FUNC_ADD
		local srcRGB = GL.GL_ONE
		local srcA   = GL.GL_ONE
		local dstRGB = GL.GL_ZERO
		local dstA   = GL.GL_ZERO

		if ( mode == "alpha" ) then
			srcRGB = GL.GL_ONE
			srcA = GL.GL_ONE
			dstRGB = GL.GL_ONE_MINUS_SRC_ALPHA
			dstA = GL.GL_ONE_MINUS_SRC_ALPHA
		elseif ( mode == "multiply" ) then
			srcRGB = GL.GL_DST_COLOR
			srcA = GL.GL_DST_COLOR
			dstRGB = GL.GL_ZERO
			dstA = GL.GL_ZERO
		elseif ( mode == "subtract" ) then
			func = GL.GL_FUNC_REVERSE_SUBTRACT
		elseif( mode == "add" ) then
			srcRGB = GL.GL_ONE
			srcA = GL.GL_ZERO
			dstRGB = GL.GL_ONE
			dstA = GL.GL_ONE
		elseif ( mode == "lighten" ) then
			func = GL.GL_MAX
		elseif ( mode == "darken" ) then
			func = GL.GL_MIN
		elseif ( mode == "screen" ) then
			srcRGB = GL.GL_ONE
			srcA = GL.GL_ONE
			dstRGB = GL.GL_ONE_MINUS_SRC_COLOR
			dstA = GL.GL_ONE_MINUS_SRC_COLOR
		-- elseif ( mode == "replace" or mode == "none" ) then
		else
			srcRGB = GL.GL_ONE
			srcA = GL.GL_ONE
			dstRGB = GL.GL_ZERO
			dstA = GL.GL_ZERO
		end

		-- We can only do alpha-multiplication when srcRGB would have been unmodified.
		if (srcRGB == GL.GL_ONE and alphamode == "alphamultiply" and mode ~= "none" ) then
			srcRGB = GL.GL_SRC_ALPHA
		end

		GL.glBlendEquation( func )
		GL.glBlendFuncSeparate( srcRGB, dstRGB, srcA, dstA )
		_blendMode = mode
		_alphaMode = alphamode
	end

	_setColor = _setColor or framework.graphics.setColor

	function setColor( r, g, b, a )
		if ( type( r ) ~= "table" ) then
			_setColor( { r, g, b, a } )
			return
		end
		_setColor( r )
	end

	function setDefaultFilter( min, mag, anisotropy )
		notimplemented( "setDefaultFilter", 3 )
	end

	setCanvas = framework.graphics.setFramebuffer

	function setStencilTest()
		notimplemented( "setStencilTest", 3 )
	end

	function stencil()
		notimplemented( "stencil", 3 )
	end

	return _M
end

local function love_image()
	require( "framework.graphics.image" )

	module( "love.image" )

	local image = framework.graphics.image

	return _M
end

local function love_keyboard()
	require( "framework.keyboard" )

	module( "love.keyboard" )

	_M.isDown = framework.keyboard.isPressed

	return _M
end

local function love_mouse()
	module( "love.mouse" )
	return _M
end

local function love_system()
	module( "love.system" )

	function getOS()
		if ( jit.os == "OSX" ) then
			return "OS X"
		elseif ( jit.os == "Other" ) then
			return "Unknown"
		else
			return jit.os
		end
	end

	return _M
end

local function love_window()
	module( "love.window" )

	function getFullscreenModes()
		notimplemented( "getFullscreenModes", 3 )
		return {
			{ width = 800, height = 600 }
		}
	end

	function setMode()
		notimplemented( "setMode", 3 )
	end

	return _M
end

local modules = {
	[ "love.audio" ]      = love_audio,
	[ "love.filesystem" ] = love_filesystem,
	[ "love.graphics" ]   = love_graphics,
	[ "love.image" ]      = love_image,
	[ "love.keyboard" ]   = love_keyboard,
	[ "love.mouse" ]      = love_mouse,
	[ "love.system" ]     = love_system,
	[ "love.window" ]     = love_window
}

-- Preload module loaders.
for name, func in pairs( modules ) do
	package.preload[ name ] = func()
end

function love.createhandlers()

	-- Standard callback handlers.
	love.handlers = setmetatable({
		keypressed = function (b,s,r)
			if love.keypressed then return love.keypressed(b,s,r) end
		end,
		keyreleased = function (b,s)
			if love.keyreleased then return love.keyreleased(b,s) end
		end,
		textinput = function (t)
			if love.textinput then return love.textinput(t) end
		end,
		textedited = function (t,s,l)
			if love.textedited then return love.textedited(t,s,l) end
		end,
		mousemoved = function (x,y,dx,dy,t)
			if love.mousemoved then return love.mousemoved(x,y,dx,dy,t) end
		end,
		mousepressed = function (x,y,b,t,c)
			if love.mousepressed then return love.mousepressed(x,y,b,t,c) end
		end,
		mousereleased = function (x,y,b,t,c)
			if love.mousereleased then return love.mousereleased(x,y,b,t,c) end
		end,
		wheelmoved = function (x,y)
			if love.wheelmoved then return love.wheelmoved(x,y) end
		end,
		touchpressed = function (id,x,y,dx,dy,p)
			if love.touchpressed then return love.touchpressed(id,x,y,dx,dy,p) end
		end,
		touchreleased = function (id,x,y,dx,dy,p)
			if love.touchreleased then return love.touchreleased(id,x,y,dx,dy,p) end
		end,
		touchmoved = function (id,x,y,dx,dy,p)
			if love.touchmoved then return love.touchmoved(id,x,y,dx,dy,p) end
		end,
		joystickpressed = function (j,b)
			if love.joystickpressed then return love.joystickpressed(j,b) end
		end,
		joystickreleased = function (j,b)
			if love.joystickreleased then return love.joystickreleased(j,b) end
		end,
		joystickaxis = function (j,a,v)
			if love.joystickaxis then return love.joystickaxis(j,a,v) end
		end,
		joystickhat = function (j,h,v)
			if love.joystickhat then return love.joystickhat(j,h,v) end
		end,
		gamepadpressed = function (j,b)
			if love.gamepadpressed then return love.gamepadpressed(j,b) end
		end,
		gamepadreleased = function (j,b)
			if love.gamepadreleased then return love.gamepadreleased(j,b) end
		end,
		gamepadaxis = function (j,a,v)
			if love.gamepadaxis then return love.gamepadaxis(j,a,v) end
		end,
		joystickadded = function (j)
			if love.joystickadded then return love.joystickadded(j) end
		end,
		joystickremoved = function (j)
			if love.joystickremoved then return love.joystickremoved(j) end
		end,
		focus = function (f)
			if love.focus then return love.focus(f) end
		end,
		mousefocus = function (f)
			if love.mousefocus then return love.mousefocus(f) end
		end,
		visible = function (v)
			if love.visible then return love.visible(v) end
		end,
		quit = function ()
			return
		end,
		threaderror = function (t, err)
			if love.threaderror then return love.threaderror(t, err) end
		end,
		resize = function (w, h)
			if love.resize then return love.resize(w, h) end
		end,
		filedropped = function (f)
			if love.filedropped then return love.filedropped(f) end
		end,
		directorydropped = function (dir)
			if love.directorydropped then return love.directorydropped(dir) end
		end,
		lowmemory = function ()
			if love.lowmemory then love.lowmemory() end
			collectgarbage()
			collectgarbage()
		end,
	}, {
		__index = function(self, name)
			error("Unknown event: " .. name)
		end,
	})

end

love.createhandlers()
