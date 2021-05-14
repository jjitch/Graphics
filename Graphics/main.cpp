#include <iostream>
#include <cstdlib>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "graphic_functions.hpp"
#include "Object.hpp"
#include "Shape.hpp"
#include "Window.hpp"
#include "constants.hpp"

using std::cout;
using std::endl;;

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

	prs::Window window(C::winWidth, C::winHeight, C::winTitle);

	glClearColor(C::bgRed, C::bgGreen, C::bgBlue, C::bgAlpha);

	// �v���O�����I�u�W�F�N�g���쐬����
	const GLuint program(prs::loadProgram("point.vert", "point.frag"));

	const GLint modelLoc(glGetUniformLocation(program, "model"));
	const GLint viewLoc(glGetUniformLocation(program, "view"));
	const GLint projLoc(glGetUniformLocation(program, "projection"));
	const GLint viewModelLoc(glGetUniformLocation(program, "viewModel"));

	// �}�`�f�[�^�̍쐬
	const std::vector<glm::dvec3> RegelarOctohedron{
		{  0.0,  1.0,  0.0 },
		{ -1.0,  0.0,  0.0 },
		{  0.0, -1.0,  0.0 },
		{  1.0,  0.0,  0.0 },
		{  0.0,  1.0,  0.0 },
		{  0.0,  0.0,  1.0 },
		{  0.0, -1.0,  0.0 },
		{  0.0,  0.0, -1.0 },
		{ -1.0,  0.0,  0.0 },
		{  0.0,  0.0,  1.0 },
		{  1.0,  0.0,  0.0 },
		{  0.0,  0.0, -1.0 }
	};
	const std::vector<glm::dvec3> axes{
		{  0.0,  0.0,  0.0 },
		{  1.0,  0.0,  0.0 },
		{  0.0,  0.0,  0.0 },
		{  0.0,  1.0,  0.0 },
		{  0.0,  0.0,  0.0 },
		{  0.0,  0.0,  1.0 },
		{  0.0,  0.0,  0.0 }
	};
	const std::vector<glm::dvec3> Square{
		{ -1.0, -1.0, 0.0 },
		{ -1.0,  1.0, 0.0 },
		{  1.0,  1.0, 0.0 },
		{  1.0, -1.0, 0.0 },
	};
	const std::vector<glm::dvec3> Triangle{
		{ -0.1, -0.1, 0.0 },
		{  0.0,  0.1, 0.0 },
		{  0.1, -0.1, 0.0 },
	};
	std::unique_ptr<const prs::Shape> shape(new prs::Shape(RegelarOctohedron));

	//const double aspect = static_cast<double>(C::winHeight) / static_cast<double>(C::winWidth);
	const double aspect = sqrt(2) / 2.;
	const glm::dvec3 eye=glm::normalize(glm::dvec3(1., 1., sqrt(2)*aspect/sqrt(1-pow(aspect,2))));
	const glm::dvec3 center(0., 0., 0.);
	const glm::dvec3 up(0., 1., 0.);
	const glm::dmat4 view = glm::lookAt(eye, center, up);
	
	// �V�F�[�_�v���O�����̎g�p�J�n
	glUseProgram(program);

	bool pressed(false);

	while ((bool)window)
	{
		//�E�B���h�E���폜
		glClear(GL_COLOR_BUFFER_BIT);

		// model transform matrix
		const glm::dmat4 I(1.);
		const GLdouble* const size(window.getSize());
		const GLdouble scale(window.getScale() * 2.);
		//const GLdouble w(scale / size[0]), h(scale / size[1]);
		const GLdouble w(size[0] / scale), h(size[1] / scale);
		//const GLdouble w(scale), h(scale);
		const GLdouble* const location(window.getLocation());
		const glm::dvec3 translating(location[0], location[1], 0.);
		const glm::dvec3 scaling(scale / size[0], scale / size[1], 1.);
		const glm::dmat4 model = glm::translate(glm::dmat4(1.), translating);
		const glm::dmat4 projection = glm::ortho(-w, w, -h, h, -1., 10.);
		const glm::dmat4 viewModel = view * model;

		if (glfwGetKey(window.window, GLFW_KEY_D) == GLFW_PRESS && !pressed)
		{
			std::cout << "debug!\n";
			cout << "scale\n" << scale << "\n\n";
			std::cout << "translating vector\n" << glm::to_string(translating) << "\n\n";
			std::cout << "model matrix\n" << glm::to_string(model) << "\n\n";
			std::cout << "view matrix\n" << glm::to_string(view) << "\n\n";
			std::cout << "projection matrix\n" << glm::to_string(projection) << std::endl;

			pressed = true;
		}
		if (glfwGetKey(window.window, GLFW_KEY_D) != GLFW_PRESS && pressed)
		{
			pressed = false;
		}

		// uniform�ϐ��ɒl��ݒ肷��
		glUniformMatrix4dv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4dv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4dv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4dv(viewModelLoc, 1, GL_TRUE, glm::value_ptr(viewModel));

		// �}�`�̕`��
		shape->draw();

		// �J���[�o�b�t�@�̓���ւ�
		window.swapBuffers();
	}

}