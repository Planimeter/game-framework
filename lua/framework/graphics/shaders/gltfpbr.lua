--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local GL      = require( "opengl" )
local ffi     = require( "ffi" )
local kazmath = require( "kazmath" )

return function()
	-- shader
	local fragmentSource = framework.filesystem.read( "shaders/pbr-frag.glsl" )
	local vertexSource   = framework.filesystem.read( "shaders/pbr-vert.glsl" )
	local shader         = framework.graphics.newShader( fragmentSource, vertexSource )
	GL.glBindFragDataLocation( shader, 0, "FragColor" )
	framework.graphics.linkShader( shader )
	framework.graphics.setShader( shader )

	-- pbr-frag.glsl
	-- uniforms
	-- u_LightDirection
	framework.graphics.setLightDirection( { 0, 0, 0 } )
	-- u_LightColor
	framework.graphics.setLightColor( { 255, 255, 255 } )

	-- u_DiffuseEnvSampler
	local u_DiffuseEnvSampler = GL.glGetUniformLocation(
		shader, "u_DiffuseEnvSampler"
	)
	GL.glUniform1i( u_DiffuseEnvSampler, 1 )
	-- u_SpecularEnvSampler
	local u_SpecularEnvSampler = GL.glGetUniformLocation(
		shader, "u_SpecularEnvSampler"
	)
	GL.glUniform1i( u_SpecularEnvSampler, 2 )

	-- tex
	local tex = GL.glGetUniformLocation(
		shader, "tex"
	)
	GL.glUniform1i( tex, 3 )
	framework.graphics.setActiveTexture( 3 )
		framework.graphics.setDefaultTexture()
	framework.graphics.setActiveTexture( 0 )

	-- u_MetallicRoughnessSampler
	local u_MetallicRoughnessSampler = GL.glGetUniformLocation(
		shader, "u_MetallicRoughnessSampler"
	)
	GL.glUniform1i( u_MetallicRoughnessSampler, 4 )

	-- u_NormalSampler
	local u_NormalSampler = GL.glGetUniformLocation(
		shader, "u_NormalSampler"
	)
	GL.glUniform1i( u_NormalSampler, 5 )
	-- u_NormalScale
	framework.graphics.setNormalScale( 1 )

	-- u_brdfLUT
	local u_brdfLUT = GL.glGetUniformLocation(
		shader, "u_brdfLUT"
	)
	GL.glUniform1i( u_brdfLUT, 6 )
	-- u_brdfLUT
	framework.graphics.setBrdfLUT( "textures/brdfLUT.png" )

	-- u_EmissiveSampler
	local u_EmissiveSampler = GL.glGetUniformLocation(
		shader, "u_EmissiveSampler"
	)
	GL.glUniform1i( u_EmissiveSampler, 7 )
	-- u_EmissiveFactor
	framework.graphics.setEmissiveFactor( { 1, 1, 1 } )

	-- u_OcclusionSampler
	local u_OcclusionSampler = GL.glGetUniformLocation(
		shader, "u_OcclusionSampler"
	)
	GL.glUniform1i( u_OcclusionSampler, 8 )
	-- u_OcclusionStrength
	framework.graphics.setOcclusionStrength( 1 )

	-- u_MetallicRoughnessValues
	framework.graphics.setMetallicRoughnessValues( { 1, 1 } )
	-- color
	framework.graphics.setColor( { 255, 255, 255, 1 } )

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

	return shader
end
