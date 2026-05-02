#version 330 core

uniform vec4 color1;
uniform vec4 color2;

layout (location = 0) out vec4 color;
varying vec2 pos;

void main(){

	if (pos.y < 0)
	{
		color = color1;
	}
	else
	{
		color = color2;
	}

}