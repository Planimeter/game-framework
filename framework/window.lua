--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local SDL = require( "lib.sdl" )
local ffi = require( "ffi" )
local bit = require( "bit" )
local GL  = require( "lib.opengl" )

local framework = framework

module( "framework.window" )

function createWindow( title, x, y, width, height, flags )
	x = x or SDL.SDL_WINDOWPOS_UNDEFINED
	y = y or SDL.SDL_WINDOWPOS_UNDEFINED

	local defaultFlags = bit.bor(
		ffi.C.SDL_WINDOW_OPENGL,
		ffi.C.SDL_WINDOW_ALLOW_HIGHDPI
	)
	flags = bit.bor( defaultFlags, flags or 0 )

	SDL.SDL_InitSubSystem( SDL.SDL_INIT_VIDEO )
	SDL.SDL_GL_SetAttribute(
		ffi.C.SDL_GL_CONTEXT_PROFILE_MASK,
		ffi.C.SDL_GL_CONTEXT_PROFILE_CORE
	)

	window  = SDL.SDL_CreateWindow( title, x, y, width, height, flags )
	context = SDL.SDL_GL_CreateContext( window )

	GL.glViewport( 0, 0, width, height )

	framework.graphics.createDefaultVAO()
	framework.graphics.createDefaultVBO()
	framework.graphics.setDefaultShader()
	framework.graphics.set2DVertexAttributes()
	framework.graphics.setOrthographicProjection( width, height )
	framework.graphics.createDefaultTexture()

	GL.glEnable( GL.GL_BLEND )
	GL.glBlendFunc( GL.GL_SRC_ALPHA, GL.GL_ONE_MINUS_SRC_ALPHA )

	local font = framework.graphics.newFont( "fonts/Vera.ttf" )
	framework.graphics.setFont( font )
end

function resize( width, height )
	GL.glViewport( 0, 0, width, height )
	framework.graphics.setOrthographicProjection( width, height )
end

function setTitle( title )
	SDL.SDL_SetWindowTitle( window, title )
end

function swap()
	SDL.SDL_GL_SwapWindow( window )
	framework.graphics.drawCalls = 0
end
