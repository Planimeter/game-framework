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
	local fragmentSource = framework.filesystem.read( "shaders/depth.frag" )
	local vertexSource   = framework.filesystem.read( "shaders/depth.vert" )
	local shader         = framework.graphics.newShader( fragmentSource, vertexSource )
	GL.glBindFragDataLocation( shader, 0, "FragDepth" )
	framework.graphics.linkShader( shader )
	framework.graphics.setShader( shader )

	-- depth.vert
	-- attribs
	-- position
	local position = GL.glGetAttribLocation( shader, "position" )
	local stride = 3 * ffi.sizeof( "GLfloat" )
	GL.glEnableVertexAttribArray( position )
	GL.glVertexAttribPointer( position, 3, GL.GL_FLOAT, 0, stride, nil )

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
