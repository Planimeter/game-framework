//=========== Copyright © 2017, Planimeter, All rights reserved. =============//
//
// Purpose:
//
//============================================================================//

#version 330

uniform sampler2D tex;
uniform vec4 color;

in vec2 texCoord;

out vec4 fragColor;

void main()
{
	fragColor = texture( tex, texCoord ) * color;
}
