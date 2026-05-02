#version 330 core

uniform float scale;

layout (location = 0) in vec2 post;
varying vec2 pos;

void main()
{
	gl_Position = vec4(post.xy * scale, 0.0, 1.0);
	pos = post.xy;
}