#version 460 core
uniform dmat4 model;
uniform dmat4 view;
uniform dmat4 projection;
in vec4 position;
in vec4 color;
out vec4 vertex_color;
void main(void)
{
	gl_Position = vec4(projection * view * model * position);
	vertex_color=color;
}