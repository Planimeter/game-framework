//=========== Copyright © 2020, Planimeter, All rights reserved. =============//
//
// Purpose:
//
//==========================================================================//

#version 330

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

in vec2 position;
in vec2 texcoord;

out vec2 TexCoord;

void main()
{
	gl_Position = projection * view * model * vec4( position, 0.0, 1.0 );
	TexCoord    = texcoord;
}
