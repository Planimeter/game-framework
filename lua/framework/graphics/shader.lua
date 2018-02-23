--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local GL      = require( "opengl" )
local ffi     = require( "ffi" )
local kazmath = require( "kazmath" )

local error     = error
local framework = framework

module( "framework.graphics" )

local function getShaderCompileStatus( shader )
	local status = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( shader, GL.GL_COMPILE_STATUS, status )
	if ( status[0] ~= GL.GL_FALSE ) then
		return
	end

	local length = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( shader, GL.GL_INFO_LOG_LENGTH, length )
	local buffer = ffi.new( "char[?]", length[0] )
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
	return _shader
end

function setShader( shader )
	GL.glUseProgram( shader )
	_shader = shader
end

function setDefaultShader()
	-- shader
	local fragmentSource = framework.filesystem.read( "shaders/default.frag" )
	local vertexSource   = framework.filesystem.read( "shaders/default2d.vert" )
	local shader         = newShader( fragmentSource, vertexSource )
	GL.glBindFragDataLocation( shader, 0, "FragColor" )
	linkShader( shader )
	setShader( shader )

	-- default.frag
	-- uniforms
	-- tex
	setDefaultTexture()

	-- color
	setColor( { 255, 255, 255, 1 } )

	-- default2d.vert
	-- attribs
	-- position
	local position = GL.glGetAttribLocation( shader, "position" )
	local stride = ( 2 + 2 ) * ffi.sizeof( "GLfloat" )
	GL.glEnableVertexAttribArray( position )
	GL.glVertexAttribPointer( position, 2, GL.GL_FLOAT, 0, stride, nil )

	-- texcoord
	local texcoord = GL.glGetAttribLocation( shader, "texcoord" )
	GL.glEnableVertexAttribArray( texcoord )
	local pointer = ffi.cast( "GLvoid *", 2 * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( texcoord, 2, GL.GL_FLOAT, 0, stride, pointer )

	-- uniforms
	-- model
	local model = GL.glGetUniformLocation( shader, "model" )
	local mat4 = ffi.new( "kmMat4" )
	kazmath.kmMat4Identity( mat4 )
	GL.glUniformMatrix4fv( model, 1, GL.GL_FALSE, mat4.mat )

	-- view
	local view = GL.glGetUniformLocation( shader, "view" )
	GL.glUniformMatrix4fv( view, 1, GL.GL_FALSE, mat4.mat )

	-- projection
	local width, height = framework.graphics.getSize()
	framework.graphics.setOrthographicProjection( width, height )
end

function setDefault3DShader()
	-- shader
	local fragmentSource = framework.filesystem.read( "shaders/default.frag" )
	local vertexSource   = framework.filesystem.read( "shaders/default3d.vert" )
	local shader         = newShader( fragmentSource, vertexSource )
	GL.glBindFragDataLocation( shader, 0, "FragColor" )
	linkShader( shader )
	setShader( shader )

	-- default.frag
	-- uniforms
	-- tex
	setDefaultTexture()

	-- color
	setColor( { 255, 255, 255, 1 } )

	-- default3d.vert
	-- attribs
	-- position
	local position = GL.glGetAttribLocation( shader, "position" )
	local stride = ( 3 + 3 + 3 + 2 ) * ffi.sizeof( "GLfloat" )
	GL.glEnableVertexAttribArray( position )
	GL.glVertexAttribPointer( position, 3, GL.GL_FLOAT, 0, stride, nil )

	-- normal
	local normal = GL.glGetAttribLocation( shader, "normal" )
	GL.glEnableVertexAttribArray( normal )
	local pointer = ffi.cast( "GLvoid *", 3 * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( normal, 3, GL.GL_FLOAT, 0, stride, pointer )

	-- tangent
	local tangent = GL.glGetAttribLocation( shader, "tangent" )
	GL.glEnableVertexAttribArray( tangent )
	pointer = ffi.cast( "GLvoid *", ( 3 + 3 ) * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( tangent, 3, GL.GL_FLOAT, 0, stride, pointer )

	-- texcoord
	local texcoord = GL.glGetAttribLocation( shader, "texcoord" )
	GL.glEnableVertexAttribArray( texcoord )
	pointer = ffi.cast( "GLvoid *", ( 3 + 3 + 3 ) * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( texcoord, 2, GL.GL_FLOAT, 0, stride, pointer )

	-- uniforms
	-- model
	local model = GL.glGetUniformLocation( shader, "model" )
	local mat4 = ffi.new( "kmMat4" )
	kazmath.kmMat4Identity( mat4 )
	GL.glUniformMatrix4fv( model, 1, GL.GL_FALSE, mat4.mat )

	-- view
	local view = GL.glGetUniformLocation( shader, "view" )
	GL.glUniformMatrix4fv( view, 1, GL.GL_FALSE, mat4.mat )

	-- projection
	local width, height = framework.graphics.getSize()
	framework.graphics.setOrthographicProjection( width, height )
end

function setGlTFPBRShader()
	-- shader
	local fragmentSource = framework.filesystem.read( "shaders/pbr-frag.glsl" )
	local vertexSource   = framework.filesystem.read( "shaders/pbr-vert.glsl" )
	local shader         = newShader( fragmentSource, vertexSource )
	GL.glBindFragDataLocation( shader, 0, "FragColor" )
	linkShader( shader )
	setShader( shader )

	-- pbr-frag.glsl
	-- uniforms
	-- u_LightDirection
	setLightDirection( { 0, 0, 0 } )

	-- u_LightColor
	setLightColor( { 255, 255, 255 } )

	-- tex
	setDefaultTexture()

	-- u_MetallicRoughnessValues
	setMetallicRoughnessValues( { 1, 1 } )

	-- color
	setColor( { 255, 255, 255, 1 } )

	-- pbr-vert.glsl
	-- attribs
	-- position
	local position = GL.glGetAttribLocation( shader, "position" )
	local stride = ( 3 + 3 + 3 + 2 ) * ffi.sizeof( "GLfloat" )
	GL.glEnableVertexAttribArray( position )
	GL.glVertexAttribPointer( position, 3, GL.GL_FLOAT, 0, stride, nil )

	-- normal
	local normal = GL.glGetAttribLocation( shader, "normal" )
	GL.glEnableVertexAttribArray( normal )
	local pointer = ffi.cast( "GLvoid *", 3 * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( normal, 3, GL.GL_FLOAT, 0, stride, pointer )

	-- tangent
	local tangent = GL.glGetAttribLocation( shader, "tangent" )
	GL.glEnableVertexAttribArray( tangent )
	pointer = ffi.cast( "GLvoid *", ( 3 + 3 ) * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( tangent, 3, GL.GL_FLOAT, 0, stride, pointer )

	-- texcoord
	local texcoord = GL.glGetAttribLocation( shader, "texcoord" )
	GL.glEnableVertexAttribArray( texcoord )
	pointer = ffi.cast( "GLvoid *", ( 3 + 3 + 3 ) * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( texcoord, 2, GL.GL_FLOAT, 0, stride, pointer )

	-- uniforms
	-- model
	local model = GL.glGetUniformLocation( shader, "model" )
	local mat4 = ffi.new( "kmMat4" )
	kazmath.kmMat4Identity( mat4 )
	GL.glUniformMatrix4fv( model, 1, GL.GL_FALSE, mat4.mat )

	-- view
	local view = GL.glGetUniformLocation( shader, "view" )
	GL.glUniformMatrix4fv( view, 1, GL.GL_FALSE, mat4.mat )

	-- projection
	local width, height = framework.graphics.getSize()
	framework.graphics.setOrthographicProjection( width, height )
end

function getDefaultTexture()
	return _defaultTexture
end

function setDefaultTexture()
	_defaultTexture = ffi.new( "GLuint[1]" )
	GL.glGenTextures( 1, _defaultTexture )
	GL.glBindTexture( GL.GL_TEXTURE_2D, _defaultTexture[0] )

	local pixels = ffi.new( "GLfloat[4]", 1.0, 1.0, 1.0, 1.0 )
	GL.glTexImage2D(
		GL.GL_TEXTURE_2D,
		0,
		GL.GL_RGBA,
		1,
		1,
		0,
		GL.GL_RGBA,
		GL.GL_FLOAT,
		pixels
	)
end

function getColor()
	return _color
end

function setColor( color )
	local pColor = ffi.new( "GLfloat[4]",
		( color[ 1 ] or 0 ) / 255,
		( color[ 2 ] or 0 ) / 255,
		( color[ 3 ] or 0 ) / 255,
		( color[ 4 ] or 0 )
	)
	local index  = GL.glGetUniformLocation( getShader(), "color" )
	GL.glUniform4fv( index, 1, pColor )
	_color = color
end

function getLightDirection()
	return _lightDirection
end

function setLightDirection( direction )
	local pDirection = ffi.new( "GLfloat[3]",
		( direction[ 1 ] or 0 ),
		( direction[ 2 ] or 0 ),
		( direction[ 3 ] or 0 )
	)
	local index  = GL.glGetUniformLocation( getShader(), "u_LightDirection" )
	GL.glUniform3fv( index, 1, pDirection )
	_lightDirection = direction
end

function getLightColor()
	return _lightColor
end

function setLightColor( color )
	local pColor = ffi.new( "GLfloat[3]",
		( color[ 1 ] or 0 ) / 255,
		( color[ 2 ] or 0 ) / 255,
		( color[ 3 ] or 0 ) / 255
	)
	local index  = GL.glGetUniformLocation( getShader(), "u_LightColor" )
	GL.glUniform3fv( index, 1, pColor )
	_lightColor = color
end

function getMetallicRoughnessValues()
	return _metallicRoughnessValues
end

function setMetallicRoughnessValues( metallicRoughnessValues )
	local pMetallicRoughnessValues = ffi.new( "GLfloat[2]",
		( metallicRoughnessValues[ 1 ] or 1 ),
		( metallicRoughnessValues[ 2 ] or 1 )
	)
	local index  = GL.glGetUniformLocation(
		getShader(),
		"u_MetallicRoughnessValues"
	)
	GL.glUniform2fv( index, 1, pMetallicRoughnessValues )
	_metallicRoughnessValues = metallicRoughnessValues
end
