--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.filesystem" )
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
	GL.glGenVertexArraysAPPLE( 1, vao )
	GL.glBindVertexArrayAPPLE( vao[0] )

	local vbo = ffi.new( "GLuint[1]" )
	GL.glGenBuffers( 1, vbo )

	local vertices = ffi.new( "float[6]",
	    400, 150, -- Vertex 1 (X, Y)
	    600, 450, -- Vertex 2 (X, Y)
	    200, 450  -- Vertex 3 (X, Y)
	 )

	GL.glBindBuffer( 0x8892, vbo[0] )
	GL.glBufferData( 0x8892, ffi.sizeof( vertices ), vertices, 0x88E4 )

	local vertexSource = [[#version 120

void main()
{
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
}
]]

	local fragmentSource = [[#version 120

void main()
{
    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}
]]

	local shader = framework.graphics.newShader( fragmentSource, vertexSource )
	framework.graphics.setShader( shader )

	GL.glEnableVertexAttribArray( 0 )
	GL.glVertexAttribPointer( 0, 2, 0x1406, 0, 0, nil )
end

function update( dt )
end

function draw()
	GL.glDrawArrays( 0x0004, 0, 3 );
end

main()
