//
// ================================================
// | Grafica pe calculator                        |
// ================================================
// | Laboratorul II - 02_01_Shader.frag |
// ======================================
// 
//  Shaderul de fragment / Fragment shader - afecteaza culoarea pixelilor;

#version 330 core

in vec4 ex_Color;
out vec4 out_Color;

uniform int colorCode;

void main(void)
{
	if ( colorCode == 0 )
		out_Color = ex_Color;
	else
		out_Color=vec4 (1.0, 0.0, 1.0, 0.0);
}
 