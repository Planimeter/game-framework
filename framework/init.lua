--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.filesystem" )
local SDL = require( "lib.sdl" )
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

	local vertices = ffi.new( "float[6]", {
	    400, 150, -- Vertex 1 (X, Y)
	    600, 450, -- Vertex 2 (X, Y)
	    200, 450  -- Vertex 3 (X, Y)
	} )

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

	local vertexShader = GL.glCreateShader( 0x8B31 )
	local src = ffi.new( "char[?]", #vertexSource, vertexSource )
	local srcs = ffi.new( "const char *[1]", src )
	GL.glShaderSource( vertexShader, 1, srcs, nil )
	GL.glCompileShader( vertexShader )

	local status = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( vertexShader, 0x8B81, status )
	print( tonumber( status[0] ) )

	local buffer = ffi.new( "char[512]" )
	GL.glGetShaderInfoLog( vertexShader, 512, nil, buffer );
	print( ffi.string( buffer, 512 ) )

	local fragmentShader = GL.glCreateShader( 0x8B30 )
	local src = ffi.new( "char[?]", #fragmentSource, fragmentSource )
	local srcs = ffi.new( "const char *[1]", src )
	GL.glShaderSource( fragmentShader, 1, srcs, nil )
	GL.glCompileShader( fragmentShader )

	local status = ffi.new( "GLint[1]" )
	GL.glGetShaderiv( vertexShader, 0x8B81, status )
	print( tonumber( status[0] ) )

	local buffer = ffi.new( "char[512]" )
	GL.glGetShaderInfoLog( vertexShader, 512, nil, buffer )
	print( ffi.string( buffer, 512 ) )

	local shaderProgram = GL.glCreateProgram()
	GL.glAttachShader( shaderProgram, vertexShader )
	GL.glAttachShader( shaderProgram, fragmentShader )

	GL.glLinkProgram( shaderProgram )
	framework.graphics.setShader( shaderProgram )

	GL.glEnableVertexAttribArray( 0 )
	GL.glVertexAttribPointer( 0, 2, 0x1406, 0, 0, nil )
end

function update( dt )
end

function draw()
	GL.glDrawArrays( 0x0004, 0, 3 );
end

main()
