//=========== Copyright © 2018, Planimeter, All rights reserved. =============//
//
// Purpose:
//
//============================================================================//

#version 330

uniform samplerCube cubemap;
uniform vec4 color;

in vec2 TexCoord;

out vec4 FragColor;

void main()
{
	FragColor = texture( cubemap, TexCoord ) * color;
}
