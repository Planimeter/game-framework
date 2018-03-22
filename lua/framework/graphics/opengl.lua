--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
local GL  = require( "opengl" )

module( "framework.graphics" )

_drawCalls = _drawCalls or 0

function createDefaultVAO()
	_defaultVAO = ffi.new( "GLuint[1]" )
	GL.glGenVertexArrays( 1, _defaultVAO )
	GL.glBindVertexArray( _defaultVAO[0] )
end

function createDefaultVBO()
	_defaultVBO = ffi.new( "GLuint[1]" )
	GL.glGenBuffers( 1, _defaultVBO )
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, _defaultVBO[0] )
end

function drawArrays( mode, first, count )
	GL.glDrawArrays( mode, first, count )
	_drawCalls = _drawCalls + 1
end

function getDrawCalls()
	return _drawCalls
end

function getOpenGLVersion()
	local version = ffi.new( "GLint[2]" )
	GL.glGetIntegerv( GL.GL_MAJOR_VERSION, version )
	GL.glGetIntegerv( GL.GL_MINOR_VERSION, version + 1 )
	return version[0] + version[1] / 10
end
