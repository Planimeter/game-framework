--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi     = require( "ffi" )
local GL      = require( "lib.opengl" )
local kazmath = require( "lib.kazmath" )

function framework.load()
	local vao = ffi.new( "GLuint[1]" )
	GL.glGenVertexArrays( 1, vao )
	GL.glBindVertexArray( vao[0] )

	local vbo = ffi.new( "GLuint[1]" )
	GL.glGenBuffers( 1, vbo )
	GL.glBindBuffer( 0x8892, vbo[0] )

	local fragmentSource = framework.filesystem.read( "shaders/default.frag" )
	local vertexSource = framework.filesystem.read( "shaders/default.vert" )
	local shader = framework.graphics.newShader( fragmentSource, vertexSource )
	GL.glBindFragDataLocation( shader, 0, "fragColor" )
	framework.graphics.linkShader( shader )
	framework.graphics.setShader( shader )

	local posAttrib = GL.glGetAttribLocation( shader, "vertex" )
	GL.glEnableVertexAttribArray( posAttrib )
	GL.glVertexAttribPointer( posAttrib, 2, 0x1406, 0, 0, nil )

	local projection = GL.glGetUniformLocation( shader, "projection" )
	local mat4 = framework.math.newMat4()
	kazmath.kmMat4OrthographicProjection( mat4, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0 )
	GL.glUniformMatrix4fv( projection, 1, 0, mat4.mat )

	local model = GL.glGetUniformLocation( shader, "model" )
	local mat4 = framework.math.newMat4()
	kazmath.kmMat4Identity( mat4 )
	GL.glUniformMatrix4fv( model, 1, 0, mat4.mat )

	local view = GL.glGetUniformLocation( shader, "view" )
	local mat4 = framework.math.newMat4()
	kazmath.kmMat4Identity( mat4 )
	GL.glUniformMatrix4fv( view, 1, 0, mat4.mat )
end

function framework.draw()
	framework.graphics.polygon( {
	    0.0,  0.5, -- Vertex 1 (X, Y)
	    0.5, -0.5, -- Vertex 2 (X, Y)
	   -0.5, -0.5  -- Vertex 3 (X, Y)
	} )
end
