//=========== Copyright © 2018, Planimeter, All rights reserved. =============//
//
// Purpose:
//
//============================================================================//

#version 330

uniform samplerCube cubemap;

in vec3 TexCoord;

out vec4 FragColor;

void main()
{
	FragColor = texture( cubemap, TexCoord );
}
