#version 450 core
uniform dvec2 size;
uniform double scale;
uniform dvec2 location;
in vec4 position;
void main(void)
{
	gl_Position = vec4(2. * scale / size, 1., 1.) * position + vec4(location,0.,0.);
}