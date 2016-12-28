--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.graphics.shader" )
require( "framework.graphics.transformation" )

local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )

local framework = framework

local print = print
module( "framework.graphics" )

function clear()
	GL.glClear( 0x00004000 )
end

function getOpenGLVersion()
	local majorVersion = ffi.new( "GLint[1]" )
	local minorVersion = ffi.new( "GLint[1]" )
	GL.glGetIntegerv( 0x821B, majorVersion )
	GL.glGetIntegerv( 0x821C, minorVersion )
	return majorVersion[0] .. "." .. minorVersion[0]
end

function polygon( vertices )
	local pVertices = ffi.new( "GLfloat[?]", #vertices, vertices )
	local shader    = framework.graphics.getShader()
	local posAttrib = GL.glGetAttribLocation( shader, "vertex" )
	GL.glEnableVertexAttribArray( posAttrib )
	GL.glVertexAttribPointer( posAttrib, 2, 0x1406, 0, 0, pVertices )
	GL.glDrawArrays( 0x0004, 0, #vertices / 2 )
end
