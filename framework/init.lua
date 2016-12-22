--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.filesystem" )
require( "framework.event" )
local ffi = require( "ffi" )
local GL  = require( "lib.opengl" )

local framework = framework
local require   = require
local pairs     = pairs

local tonumber  = tonumber
local tostring  = tostring
local print     = print

module( "framework" )

function init()
	local c = {
		modules = {
			window   = true,
			graphics = true
		},
		window = {
			title  = "",
			x      = nil,
			y      = nil,
			width  = 800,
			height = 600
		}
	}

	if ( framework.filesystem.exists( "conf.lua" ) ) then
		require( "conf" )
	end

	if ( framework.conf ) then
		framework.conf( c )
	end

	for k in pairs( c.modules ) do
		require( "framework." .. k )
	end

	if ( c.modules.window ) then
		local title  = c.window.title
		local x      = c.window.x
		local y      = c.window.y
		local width  = c.window.width
		local height = c.window.height
		framework.window.createWindow( title, x, y, width, height )
	end

	if ( framework.filesystem.exists( "main.lua" ) ) then
		require( "main" )
	end
end

function main()
	init()
	load()

	while ( true ) do
		local event = nil
		repeat
			event = framework.event.poll()
			if ( event ) then
				if ( event.type == ffi.C.SDL_QUIT ) then
					quit()
					return
				end
			end
		until ( event == nil )

		if ( update ) then
			update()
		end

		if ( draw ) then
			framework.graphics.clear()
			draw()
		end

		framework.window.swap()
	end
end

function load()
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

	local vertexSource = [[#version 150 core

in vec2 position;

void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
}
]]

	local fragmentSource = [[#version 150 core

out vec4 outColor;

void main()
{
    outColor = vec4(1.0, 1.0, 1.0, 1.0);
}
]]

	local shader = framework.graphics.newShader( fragmentSource, vertexSource )
	GL.glBindFragDataLocation( shader, 0, "outColor" )
	GL.glLinkProgram( shader )
	framework.graphics.setShader( shader )

	local posAttrib = GL.glGetAttribLocation( shader, "position" )
	GL.glVertexAttribPointer( posAttrib, 2, 0x1406, 0, 0, nil )
	GL.glEnableVertexAttribArray( posAttrib )
end

function update( dt )
end

function draw()
	GL.glDrawArrays( 0x0004, 0, 3 )
end

function quit()
end

main()
