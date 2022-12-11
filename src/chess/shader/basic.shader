$$type vertex
#version 410 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec4 aColor;

out vec4 color;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, 1.0, 1.0);
	color = aColor;
}

$$type fragment
#version 410 core

in vec4 color;
out vec4 fragColor;

void main()
{
	fragColor = color;
}