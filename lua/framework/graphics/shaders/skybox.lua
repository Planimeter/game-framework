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
	local fragSource = framework.filesystem.read( "shaders/skybox.frag" )
	local vertSource = framework.filesystem.read( "shaders/skybox.vert" )
	local shader     = framework.graphics.newShader( fragSource, vertSource )
	GL.glBindFragDataLocation( shader, 0, "FragColor" )
	framework.graphics.linkShader( shader )
	framework.graphics.setShader( shader )

	-- skybox.frag
	-- uniforms
	-- tex
	framework.graphics.setDefaultTexture()

	-- skybox.vert
	-- attribs
	-- position
	local position = GL.glGetAttribLocation( shader, "position" )
	local stride = ( 3 + 3 ) * ffi.sizeof( "GLfloat" )
	GL.glEnableVertexAttribArray( position )
	GL.glVertexAttribPointer( position, 3, GL.GL_FLOAT, 0, stride, nil )

	-- texcoord
	local texcoord = GL.glGetAttribLocation( shader, "texcoord" )
	GL.glEnableVertexAttribArray( texcoord )
	local pointer = ffi.cast( "GLvoid *", ( 3 + 3 ) * ffi.sizeof( "GLfloat" ) )
	GL.glVertexAttribPointer( texcoord, 3, GL.GL_FLOAT, 0, stride, pointer )

	-- uniforms
	-- view
	local view = GL.glGetUniformLocation( shader, "view" )
	local mat4 = ffi.new( "kmMat4" )
	kazmath.kmMat4Identity( mat4 )
	GL.glUniformMatrix4fv( view, 1, GL.GL_FALSE, mat4.mat )

	-- projection
	local width, height = framework.graphics.getSize()
	framework.graphics.setOrthographicProjection( width, height )

	return shader
end
