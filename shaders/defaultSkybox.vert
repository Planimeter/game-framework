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
in vec3 texcoord;

out vec3 TexCoord;

void main()
{
	TexCoord    = texcoord;
	vec4 pos    = projection * view * model * vec4( position 1.0 );
	gl_Position = pos.xyww;
}
