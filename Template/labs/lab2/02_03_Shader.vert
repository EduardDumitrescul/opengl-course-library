//
// ================================================
// | Grafica pe calculator                        |
// ================================================
// | Laboratorul II - 02_03_Shader.vert |
// ======================================
// 
//  Shaderul de varfuri / Vertex shader - afecteaza geometria scenei; 
//

#version 330    

layout (location = 0) in vec4 in_Position;     
layout (location = 1) in vec4 in_Color;        

// out vec4 gl_Position; 
out vec4 ex_Color;      

void main(void)
  {
    gl_Position = in_Position;
    ex_Color = in_Color;
   } 
 