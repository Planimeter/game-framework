//=========== Copyright © 2018, Planimeter, All rights reserved. =============//
//
// Purpose:
//
//============================================================================//

#version 330

out vec4 FragColor;

void main()
{
	FragColor = gl_FragCoord.z;
}
