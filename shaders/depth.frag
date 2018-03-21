//=========== Copyright © 2018, Planimeter, All rights reserved. =============//
//
// Purpose:
//
//============================================================================//

#version 330

out vec4 FragDepth;

void main()
{
	FragDepth = gl_FragCoord.z;
}
