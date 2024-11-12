#version 330 core
layout (location = 0) in vec4 _position;
layout (location = 1) in vec4 _color;

uniform mat4 viewMatrix;

out vec4 ex_Color;

void main()
{
    gl_Position = viewMatrix * _position;
    ex_Color = _color;
}