--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local GL = require( "lib.opengl" )

local error = error

module( "framework.graphics" )

function clear()
	GL.glClear( 0x00004000 )
end

function line()
end

local function shader( source, type )
end

function newShader( fragmentSource, vertexSource )
	local fragmentShader = GL.glCreateShader( 0x8B30 )
	local src = ffi.new( "char[?]", #fragmentSource, fragmentSource )
	local srcs = ffi.new( "const char *[1]", src )
	GL.glShaderSource( fragmentShader, 1, srcs, nil )
	GL.glCompileShader( fragmentShader )

	local status = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( vertexShader, 0x8B81, status )
	print( tonumber( status[0] ) )

	local buffer = ffi.new( "char[512]" )
	GL.glGetShaderInfoLog( vertexShader, 512, nil, buffer )
	print( ffi.string( buffer, 512 ) )

	local vertexShader = GL.glCreateShader( 0x8B31 )
	local src = ffi.new( "char[?]", #vertexSource, vertexSource )
	local srcs = ffi.new( "const char *[1]", src )
	GL.glShaderSource( vertexShader, 1, srcs, nil )
	GL.glCompileShader( vertexShader )

	local status = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( vertexShader, 0x8B81, status )
	print( tonumber( status[0] ) )

	local buffer = ffi.new( "char[512]" )
	GL.glGetShaderInfoLog( vertexShader, 512, nil, buffer );
	print( ffi.string( buffer, 512 ) )

	local shaderProgram = GL.glCreateProgram()
	GL.glAttachShader( shaderProgram, vertexShader )
	GL.glAttachShader( shaderProgram, fragmentShader )
	GL.glLinkProgram( shaderProgram )
	GL.glDetachShader( shaderProgram, fragmentShader )
	GL.glDetachShader( shaderProgram, vertexShader )
end

function rectangle()
end

function setFramebuffer()
end

function setShader( shader )
	GL.glUseProgram( shader )
end
