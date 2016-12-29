--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.graphics.shader" )
require( "framework.graphics.transformation" )

local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )
local SDL = require( "lib.sdl" )

local framework = framework

local print = print
module( "framework.graphics" )

function clear()
	GL.glClear( 0x00004000 )
end

function getOpenGLVersion()
	local majorVersion = ffi.new( "GLint[1]" )
	local minorVersion = ffi.new( "GLint[1]" )
	GL.glGetIntegerv( 0x821B, majorVersion )
	GL.glGetIntegerv( 0x821C, minorVersion )
	return majorVersion[0] .. "." .. minorVersion[0]
end

function getSize()
	local width  = ffi.new( "int[1]" )
	local height = ffi.new( "int[1]" )
	SDL.SDL_GL_GetDrawableSize( framework.window.window, width, height )
	return width[0], height[0]
end

function newVertexArray()
	local vao = ffi.new( "GLuint[1]" )
	GL.glGenVertexArrays( 1, vao )
	return vao
end

function newVertexBuffer()
	local vbo = ffi.new( "GLuint[1]" )
	GL.glGenBuffers( 1, vbo )
	return vbo
end

function polygon( vertices )
	local pVertices = ffi.new( "GLfloat[?]", #vertices, vertices )
	local shader    = framework.graphics.getShader()
	local posAttrib = GL.glGetAttribLocation( shader, "vertex" )
	GL.glEnableVertexAttribArray( posAttrib )
	GL.glVertexAttribPointer( posAttrib, 2, 0x1406, 0, 0, pVertices )
	GL.glDrawArrays( 0x0004, 0, #vertices / 2 )
end

function rectangle( x, y, width, height )
	local vertices = {
		x,         y,
		x,         y + height,
		x + width, y + height,
		x + width, y + height,
		x + width, y,
		x,         y
	}
	polygon( vertices )
end

function setVertexArray( vao )
	GL.glBindVertexArray( vao[0] )
end

function setVertexBuffer( vbo )
	GL.glBindBuffer( 0x8892, vbo[0] )
end
