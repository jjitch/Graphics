#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <memory>
#include "graphic_functions.hpp"
#include "Object.hpp"
#include "Shape.hpp"
#include "Window.hpp"
using std::cout;
using std::endl;;

constexpr size_t WIDTH = 640;
constexpr size_t HEIGHT = 480;


constexpr prs::Object::Vertex rectangleVetex[] =
{
	{ -0.3, -0.2},
	{ 0.0, 0.0},
	{ -0.1, 0.25}
};

int main()
{
	// GLFW�̏�����
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "Can't initilize GLFW" << std::endl;
		return 1;
	}

	// �I�����ɌĂяo�����֐��̓o�^
	std::atexit(glfwTerminate);

	//GLFW�ɂ��OpenGL�̃o�[�W�����w��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	prs::Window window(WIDTH, HEIGHT, "SMAPLE");

	glClearColor(0.f, 0.f, 0.2f, 0.2f);

	// �v���O�����I�u�W�F�N�g���쐬����
	const GLuint program(prs::loadProgram("point.vert", "point.frag"));

	const GLint sizeLoc(glGetUniformLocation(program, "size"));
	const GLint scaleLoc(glGetUniformLocation(program, "scale"));
	const GLint locationLoc(glGetUniformLocation(program, "location"));

	// �}�`�f�[�^�̍쐬
	std::unique_ptr<const prs::Shape> shape(new prs::Shape(2, 4, rectangleVetex));

	while ((bool)window)
	{
		//�E�B���h�E���폜
		glClear(GL_COLOR_BUFFER_BIT);

		// �V�F�[�_�v���O�����̎g�p�J�n
		glUseProgram(program);
		
		// uniform�ϐ��ɒl��ݒ肷��
		glUniform2dv(sizeLoc, 1, window.getSize());
		glUniform1d(scaleLoc, window.getScale());
		glUniform2dv(locationLoc, 1, window.getLocation());
		
		// �}�`�̕`��
		shape->draw();

		// �J���[�o�b�t�@�̓���ւ�
		window.swapBuffers();
	}

}