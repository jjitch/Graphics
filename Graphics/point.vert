#version 460 core
uniform dmat4 model;
uniform dmat4 view;
uniform dmat4 projection;
in vec4 position;
void main(void)
{
	//mat4 m=mat4(vec4(1.,0.,0.,0.),vec4(0.,1.,0.,0.),vec4(0.,0.,1.,0.),vec4(0.,0.,0.,1.));
	gl_Position = vec4(projection * view * model * position);
	//gl_Position = vec4(projection*model * position);
	//gl_Position = vec4(position);
	//gl_Position = vec4(viewModel * position);
}