--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local GL  = require( "lib.opengl" )
local ffi = require( "ffi" )

local tonumber = tonumber
local print    = print
local error    = error

module( "framework.graphics" )

function clear()
	GL.glClear( 0x00004000 )
end

function line()
end

function newShader( fragmentSource, vertexSource )
	local fragmentShader = GL.glCreateShader( 0x8B30 )
	local source         = ffi.new( "char[?]", #fragmentSource, fragmentSource )
	local pSource        = ffi.new( "const char *[1]", source )
	GL.glShaderSource( fragmentShader, 1, pSource, nil )
	GL.glCompileShader( fragmentShader )

	local status = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( fragmentShader, 0x8B81, status )
	if ( status[0] == 0 ) then
		local buffer = ffi.new( "char[512]" )
		GL.glGetShaderInfoLog( fragmentShader, 512, nil, buffer )
		print( ffi.string( buffer, 512 ) )
	end

	local vertexShader = GL.glCreateShader( 0x8B31 )
	source             = ffi.new( "char[?]", #vertexSource, vertexSource )
	pSource            = ffi.new( "const char *[1]", source )
	GL.glShaderSource( vertexShader, 1, pSource, nil )
	GL.glCompileShader( vertexShader )

	local status = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( vertexShader, 0x8B81, status )
	if ( status[0] == 0 ) then
		local buffer = ffi.new( "char[512]" )
		GL.glGetShaderInfoLog( vertexShader, 512, nil, buffer );
		print( ffi.string( buffer, 512 ) )
	end

	local shaderProgram = GL.glCreateProgram()
	GL.glAttachShader( shaderProgram, vertexShader )
	GL.glAttachShader( shaderProgram, fragmentShader )
	return shaderProgram
end

function rectangle()
end

function setFramebuffer()
end

function setShader( shader )
	GL.glUseProgram( shader )
end
