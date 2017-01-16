--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi     = require( "ffi" )
local GL      = require( "opengl" )
local kazmath = require( "kazmath" )

local error     = error
local framework = framework

module( "framework.graphics" )

local function getShaderCompileStatus( shader )
	local status = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( shader, GL.GL_COMPILE_STATUS, status )
	if ( status[0] ~= 0 ) then
		return
	end

	local length = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( shader, GL.GL_INFO_LOG_LENGTH, length )
	local buffer = ffi.new( "char[ " .. length[0] .. "]" )
	GL.glGetShaderInfoLog( shader, length[0], nil, buffer )
	GL.glDeleteShader( shader )
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
	local fragmentShader = createShader( GL.GL_FRAGMENT_SHADER, fragmentSource )
	local vertexShader   = createShader( GL.GL_VERTEX_SHADER, vertexSource )
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

function setDefaultShader( space )
	-- shader
	local fragmentSource = framework.filesystem.read( "shaders/default.frag" )
	local vertexShader = space == "3d" and "shaders/default3d.vert"
	                                    or "shaders/default2d.vert"
	local vertexSource = framework.filesystem.read( vertexShader )
	local shader = newShader( fragmentSource, vertexSource )
	GL.glBindFragDataLocation( shader, 0, "fragColor" )
	linkShader( shader )
	setShader( shader )

	-- default.frag
	-- uniforms
	-- tex
	framework.graphics.setDefaultTexture()

	-- color
	framework.graphics.setColor( { 255, 255, 255, 1 } )

	-- default2d.vert
	-- attribs
	-- vertex
	local vertex = GL.glGetAttribLocation( shader, "vertex" )
	local stride = 4 * ffi.sizeof( "GLfloat" )
	GL.glEnableVertexAttribArray( vertex )
	GL.glVertexAttribPointer( vertex, 2, GL.GL_FLOAT, 0, stride, nil )

	-- texcoord
	local texcoord = GL.glGetAttribLocation( shader, "texcoord" )
	GL.glEnableVertexAttribArray( texcoord )
	local pointer = ffi.cast( "GLvoid *", 2 * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( texcoord, 2, GL.GL_FLOAT, 0, stride, pointer )

	-- uniforms
	-- projection
	local projection = GL.glGetUniformLocation( shader, "projection" )
	local mat4 = ffi.new( "kmMat4" )
	local width, height = framework.graphics.getSize()
	kazmath.kmMat4OrthographicProjection( mat4, 0, width, height, 0, -1.0, 1.0 )
	GL.glUniformMatrix4fv( projection, 1, GL.GL_FALSE, mat4.mat )

	-- model
	local model = GL.glGetUniformLocation( shader, "model" )
	local mat4 = ffi.new( "kmMat4" )
	kazmath.kmMat4Identity( mat4 )
	GL.glUniformMatrix4fv( model, 1, GL.GL_FALSE, mat4.mat )

	-- view
	local view = GL.glGetUniformLocation( shader, "view" )
	GL.glUniformMatrix4fv( view, 1, GL.GL_FALSE, mat4.mat )
end

function setPerspectiveProjection( fov, near, far )
	local projection = GL.glGetUniformLocation( shader, "projection" )
	local mat4 = ffi.new( "kmMat4" )
	local width, height = framework.graphics.getSize()
	local aspect = width / height
	kazmath.kmMat4PerspectiveProjection( mat4, fov, aspect, near, far )
	GL.glUniformMatrix4fv( projection, 1, GL.GL_FALSE, mat4.mat )
end

function setOrthographicProjection( width, height )
	width, height = width, height or framework.graphics.getSize()
	local projection = GL.glGetUniformLocation( shader, "projection" )
	local mat4 = ffi.new( "kmMat4" )
	kazmath.kmMat4OrthographicProjection( mat4, 0, width, height, 0, -1.0, 1.0 )
	GL.glUniformMatrix4fv( projection, 1, GL.GL_FALSE, mat4.mat )
end

function getDefaultTexture()
	return defaultTexture
end

function setDefaultTexture()
	defaultTexture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, defaultTexture )
	GL.glBindTexture( GL.GL_TEXTURE_2D, defaultTexture[0] )

	local pixels = ffi.new( "GLfloat[4]", { 1.0, 1.0, 1.0, 1.0 } )
	GL.glTexImage2D( GL.GL_TEXTURE_2D, 0, GL.GL_RGBA, 1, 1, 0, GL.GL_RGBA, GL.GL_FLOAT, pixels )
end
