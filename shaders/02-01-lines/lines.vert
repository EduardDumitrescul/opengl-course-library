#version 330 core

layout (location = 0) in vec4 in_Position;
layout (location = 1) in vec4 in_Color;

// Pentru unele procesoare linia urmatoare trebuie decomentata
// out vec4 gl_Position; 
out vec4 ex_Color;

void main ()
{
   gl_Position = in_Position;
   ex_Color = in_Color;
}