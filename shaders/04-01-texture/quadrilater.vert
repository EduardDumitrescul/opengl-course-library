#version 330 core
layout (location = 0) in vec4 _position;
layout (location = 1) in vec4 _color;
layout (location = 2) in vec2 _texCoord;

out vec4 color;
out vec2 texCoord;

void main()
{
    gl_Position = _position;
    texCoord = _texCoord;
    color = _color;
}