//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include "graphic_functions.hpp"
#include "Object.hpp"
#include "Shape.hpp"

constexpr prs::Object::Vertex rectangleVetex[] =
{
	{-0.5, -0.5},
	{ 0.5, -0.5},
	{ 0.5,  0.5},
	{-0.5,  0.5}
};

int main()
{
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "Can't initilize GLFW" << std::endl;
		return 1;
	}

	std::atexit(glfwTerminate);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* const window = glfwCreateWindow(640, 480, "SAMPLE", NULL, NULL);
	if (window == nullptr)
	{
		std::cerr << "Can't create GLFW window." << std::endl;
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Can't initialize GLEW." << std::endl;
		return 1;
	}

	glfwSwapInterval(1);

	glClearColor(0.f, 0.f, 0.f, 0.2f);

	const GLuint program(prs::loadProgram("point.vert", "point.frag"));

	std::unique_ptr<const prs::Shape> shape(new prs::Shape(2, 4, rectangleVetex));

	while (glfwWindowShouldClose(window) == GL_FALSE)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(program);

		shape->draw();

		glfwSwapBuffers(window);

		glfwWaitEvents();
	}

}