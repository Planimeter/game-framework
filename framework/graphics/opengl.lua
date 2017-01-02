--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )

module( "framework.graphics" )

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
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, vbo[0] )
end
