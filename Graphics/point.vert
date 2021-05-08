#version 450 core
uniform dvec2 size;
uniform double scale;
in vec4 position;
void main(void)
{
	gl_Position = vec4(2. * scale / size.x, 2. * scale / size.y, 1., 1.) * position;
	//gl_Position = vec4(2. *640/ size.x, 2. *480/ size.y, 1., 1.) * position;
	//gl_Position = vec4(2. * scale / size, 1., 1.) * position;
	//gl_Position = vec4(2. * scale, 2. * scale, 1., 1.) * position;
}