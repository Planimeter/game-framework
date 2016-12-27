//=========== Copyright © 2016, Planimeter, All rights reserved. =============//
//
// Purpose:
//
//============================================================================//

#version 330

in vec2 vertex;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	gl_Position = projection * view * model * vec4( vertex, 0.0, 1.0 );
}
