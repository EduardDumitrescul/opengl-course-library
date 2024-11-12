#version 330 core
layout (location = 0) in vec4 _position;
layout (location = 1) in vec4 _color;

uniform mat4 viewMatrix;
uniform float c4;

out vec4 ex_Color;

void main()
{
    if(_position[0] < -50 || _position[0] > 50 || _position[1] < -50 || _position[1] > 50)
        gl_Position = viewMatrix * vec4(_position[0], _position[1], _position[2], c4);
    else
        gl_Position = viewMatrix * vec4(_position[0], _position[1], _position[2], 1.0);
    ex_Color = _color;
}