--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local GL  = require( "lib.opengl" )
local ffi = require( "ffi" )

local error = error

module( "framework.graphics" )

local function getShaderCompileStatus()
	local status = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( shader, 0x8B81, status )
	if ( status[0] ~= 0 ) then
		return
	end

	local length = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( shader, 0x8B84, length )
	local buffer = ffi.new( "char[ " .. length .. "]" )
	GL.glGetShaderInfoLog( shader, length, nil, buffer )
	error( 4, ffi.string( buffer, length ) )
end

local function createShader( type, source )
	local shader = GL.glCreateShader( type )
	source       = ffi.new( "char[?]", #source, source )
	local string = ffi.new( "const char *[1]", source )
	GL.glShaderSource( shader, 1, string, nil )
	GL.glCompileShader( shader )

	getShaderCompileStatus()
end

function newShader( fragmentSource, vertexSource )
	local fragmentShader = createShader( 0x8B30, fragmentSource )
	local vertexShader   = createShader( 0x8B31, vertexSource )
	local shaderProgram  = GL.glCreateProgram()
	GL.glAttachShader( shaderProgram, vertexShader )
	GL.glAttachShader( shaderProgram, fragmentShader )
	return shaderProgram
end

function linkShader( shader )
	GL.glLinkProgram( shader )
end

function setShader( shader )
	GL.glUseProgram( shader )
end
