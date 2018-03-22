--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local GL      = require( "opengl" )
local ffi     = require( "ffi" )
local kazmath = require( "kazmath" )

local error     = error
local type      = type
local dofile    = dofile
local framework = framework

module( "framework.graphics" )

_shaders        = _shaders        or {}
_shaders.loaded = _shaders.loaded or {}

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

function newShader( fragSource, vertSource )
	local fragShader    = createShader( GL.GL_FRAGMENT_SHADER, fragSource )
	local vertShader    = createShader( GL.GL_VERTEX_SHADER, vertSource )
	local shaderProgram = GL.glCreateProgram()
	GL.glAttachShader( shaderProgram, vertShader )
	GL.glAttachShader( shaderProgram, fragShader )
	return shaderProgram
end

function linkShader( shader )
	GL.glLinkProgram( shader )
end

function getShader()
	return _shader
end

function setShader( shader )
	if ( type( shader ) == "string" ) then
		if ( not _shaders.loaded[ shader ] ) then
			local dir      = "lua/framework/graphics/shaders/"
			local filename = dir .. shader .. ".lua"
			_shaders.loaded[ shader ] = dofile( filename )()
		end
		shader = _shaders.loaded[ shader ]
	end

	GL.glUseProgram( shader )
	_shader = shader
end

function getActiveTexture()
	local texture = ffi.new( "GLint[1]" )
	GL.glGetIntegerv( GL.GL_ACTIVE_TEXTURE, texture )
	return texture[0]
end

function setActiveTexture( texture )
	GL.glActiveTexture( GL[ "GL_TEXTURE" .. texture ] )
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
	local index = GL.glGetUniformLocation( getShader(), "color" )
	GL.glUniform4fv( index, 1, pColor )
	_color = color
end

function getLightDirection()
	return _lightDirection
end

function setLightDirection( direction )
	local pDirection = ffi.new( "GLfloat[3]", direction )
	local index = GL.glGetUniformLocation( getShader(), "u_LightDirection" )
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
	local index = GL.glGetUniformLocation( getShader(), "u_LightColor" )
	GL.glUniform3fv( index, 1, pColor )
	_lightColor = color
end

function getBrdfLUT()
	return _brdfLUT
end

function setBrdfLUT( filename )
	_brdfLUT = framework.graphics.newImage( filename, {
		{ GL.GL_TEXTURE_WRAP_S, GL.GL_CLAMP_TO_EDGE },
		{ GL.GL_TEXTURE_WRAP_T, GL.GL_CLAMP_TO_EDGE }
	} )
	setActiveTexture( 6 )
	GL.glBindTexture( GL.GL_TEXTURE_2D, _brdfLUT.texture[0] )
	setActiveTexture( 0 )
end

function getNormalScale()
	return _normalScale
end

function setNormalScale( normalScale )
	local pNormalScale = ffi.new( "GLfloat[1]", normalScale )
	local index = GL.glGetUniformLocation( getShader(), "u_NormalScale" )
	GL.glUniform1fv( index, 1, pNormalScale )
	_normalScale = normalScale
end

function getEmissiveFactor()
	return _emissiveFactor
end

function setEmissiveFactor( emissiveFactor )
	local pEmissiveFactor = ffi.new( "GLfloat[3]", emissiveFactor )
	local index = GL.glGetUniformLocation( getShader(), "u_EmissiveFactor" )
	GL.glUniform3fv( index, 1, pEmissiveFactor )
	_emissiveFactor = emissiveFactor
end

function getOcclusionStrength()
	return _occlusionStrength
end

function setOcclusionStrength( occlusionStrength )
	local pOcclusionStrength = ffi.new( "GLfloat[1]", occlusionStrength )
	local index = GL.glGetUniformLocation( getShader(), "u_OcclusionStrength" )
	GL.glUniform1fv( index, 1, pOcclusionStrength )
	_occlusionStrength = occlusionStrength
end

function getMetallicRoughnessValues()
	return _metallicRoughnessValues
end

function setMetallicRoughnessValues( metallicRoughnessValues )
	local pMetallicRoughnessValues = ffi.new( "GLfloat[2]",
		( metallicRoughnessValues[ 1 ] or 1 ),
		( metallicRoughnessValues[ 2 ] or 1 )
	)
	local index = GL.glGetUniformLocation(
		getShader(), "u_MetallicRoughnessValues"
	)
	GL.glUniform2fv( index, 1, pMetallicRoughnessValues )
	_metallicRoughnessValues = metallicRoughnessValues
end

function getCameraPosition()
	return _cameraPosition
end

function setCameraPosition( cameraPosition )
	local pCamera = ffi.new( "GLfloat[3]", cameraPosition )
	local index = GL.glGetUniformLocation( getShader(), "u_Camera" )
	GL.glUniform3fv( index, 1, pCamera )
	_cameraPosition = cameraPosition
end
