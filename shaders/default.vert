//=========== Copyright © 2016, Planimeter, All rights reserved. =============//
//
// Purpose:
//
//============================================================================//

#version 330

in vec4 vert;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	gl_Position = projection * view * model * vert;
}
