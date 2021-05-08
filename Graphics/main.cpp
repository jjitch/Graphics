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
	{ -1.0, -1.0},
	{ 0.0, 0.5},
	{ 0.4, 0.1}
};

int main()
{
	// GLFWの初期化
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "Can't initilize GLFW" << std::endl;
		return 1;
	}

	// 終了時に呼び出される関数の登録
	std::atexit(glfwTerminate);

	//GLFWによるOpenGLのバージョン指定
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	prs::Window window(WIDTH, HEIGHT, "SMAPLE");

	glClearColor(0.f, 0.f, 0.2f, 0.2f);

	// プログラムオブジェクトを作成する
	const GLuint program(prs::loadProgram("point.vert", "point.frag"));

	// 図形データの作成
	std::unique_ptr<const prs::Shape> shape(new prs::Shape(2, 4, rectangleVetex));

	while ((bool)window)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(program);
		
		shape->draw();
		window.swapBuffers();
	}

}