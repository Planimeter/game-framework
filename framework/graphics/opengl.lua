--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )

module( "framework.graphics" )

function createDefaultVAO()
	defaultVAO = ffi.new( "GLuint[1]" )
	GL.glGenVertexArrays( 1, defaultVAO )
	GL.glBindVertexArray( defaultVAO[0] )
end

function createDefaultVBO()
	defaultVBO = ffi.new( "GLuint[1]" )
	GL.glGenBuffers( 1, defaultVBO )
	GL.glBindBuffer( GL.GL_ARRAY_BUFFER, defaultVBO[0] )
end
