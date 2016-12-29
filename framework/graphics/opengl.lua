--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )

module( "framework.graphics" )

function getOpenGLVersion()
	local majorVersion = ffi.new( "GLint[1]" )
	local minorVersion = ffi.new( "GLint[1]" )
	GL.glGetIntegerv( 0x821B, majorVersion )
	GL.glGetIntegerv( 0x821C, minorVersion )
	return majorVersion[0] .. "." .. minorVersion[0]
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

function setVertexArray( vao )
	GL.glBindVertexArray( vao[0] )
end

function setVertexBuffer( vbo )
	GL.glBindBuffer( 0x8892, vbo[0] )
end
