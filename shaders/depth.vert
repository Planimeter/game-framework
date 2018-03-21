//=========== Copyright © 2018, Planimeter, All rights reserved. =============//
//
// Purpose:
//
//============================================================================//

#version 330

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

in vec3 position;

void main()
{
	gl_Position = projection * view * model * vec4( position, 1.0 );
}
