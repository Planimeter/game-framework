--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )

function framework.load()
	local vao = ffi.new( "GLuint[1]" )
	GL.glGenVertexArrays( 1, vao )
	GL.glBindVertexArray( vao[0] )

	local vbo = ffi.new( "GLuint[1]" )
	GL.glGenBuffers( 1, vbo )

	local vertices = ffi.new( "GLfloat[6]", {
	    0.0,  0.5, -- Vertex 1 (X, Y)
	    0.5, -0.5, -- Vertex 2 (X, Y)
	   -0.5, -0.5  -- Vertex 3 (X, Y)
	} )

	GL.glBindBuffer( 0x8892, vbo[0] )
	GL.glBufferData( 0x8892, ffi.sizeof( vertices ), vertices, 0x88E4 )

	local fragmentSource = framework.filesystem.read( "shaders/default.frag" )
	local vertexSource = framework.filesystem.read( "shaders/default.vert" )
	local shader = framework.graphics.newShader( fragmentSource, vertexSource )
	GL.glBindFragDataLocation( shader, 0, "outColor" )
	framework.graphics.linkShader( shader )
	framework.graphics.setShader( shader )

	local posAttrib = GL.glGetAttribLocation( shader, "position" )
	GL.glVertexAttribPointer( posAttrib, 2, 0x1406, 0, 0, nil )
	GL.glEnableVertexAttribArray( posAttrib )

	local projection = GL.glGetUniformLocation( shader, "projection" )
	local mat4 = framework.math.newMat4()
	mat4:OrthographicProjection( 0, 0, 600, 800, 0, 0 )
	GL.glUniformMatrix4fv( projection, 1, 0, mat4:toArray() )
end

function framework.draw()
	GL.glDrawArrays( 0x0004, 0, 3 )
end
