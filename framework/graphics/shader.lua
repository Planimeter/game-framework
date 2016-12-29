--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi     = require( "ffi" )
local GL      = require( "lib.opengl" )
local kazmath = require( "lib.kazmath" )

local error     = error
local framework = framework

module( "framework.graphics" )

local function getShaderCompileStatus( shader )
	local status = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( shader, 0x8B81, status )
	if ( status[0] ~= 0 ) then
		return
	end

	local length = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( shader, 0x8B84, length )
	local buffer = ffi.new( "char[ " .. length[0] .. "]" )
	GL.glGetShaderInfoLog( shader, length[0], nil, buffer )
	error( ffi.string( buffer, length[0] ), 4 )
end

local function createShader( type, source )
	local shader = GL.glCreateShader( type )
	source       = ffi.new( "char[?]", #source, source )
	local string = ffi.new( "const char *[1]", source )
	GL.glShaderSource( shader, 1, string, nil )
	GL.glCompileShader( shader )

	getShaderCompileStatus( shader )
	return shader
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

function getShader()
	return shader
end

function setShader( shader )
	GL.glUseProgram( shader )
	_M.shader = shader
end

function setDefaultShader()
	local fragmentSource = framework.filesystem.read( "shaders/default.frag" )
	local vertexSource = framework.filesystem.read( "shaders/default.vert" )
	local shader = newShader( fragmentSource, vertexSource )
	GL.glBindFragDataLocation( shader, 0, "fragColor" )
	linkShader( shader )
	setShader( shader )
end

function set2DVertexAttributes()
	local shader = getShader()
	local posAttrib = GL.glGetAttribLocation( shader, "vertex" )
	GL.glEnableVertexAttribArray( posAttrib )
	GL.glVertexAttribPointer( posAttrib, 2, 0x1406, 0, 0, nil )

	local projection = GL.glGetUniformLocation( shader, "projection" )
	local mat4 = framework.math.newMat4()
	local width, height = framework.graphics.getSize()
	kazmath.kmMat4OrthographicProjection( mat4, 0, width, height, 0, 0, 1.0 )
	GL.glUniformMatrix4fv( projection, 1, 0, mat4.mat )

	local model = GL.glGetUniformLocation( shader, "model" )
	local mat4 = framework.math.newMat4()
	kazmath.kmMat4Identity( mat4 )
	GL.glUniformMatrix4fv( model, 1, 0, mat4.mat )

	local view = GL.glGetUniformLocation( shader, "view" )
	GL.glUniformMatrix4fv( view, 1, 0, mat4.mat )
end
