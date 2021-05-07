#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <memory>
#include "graphic_functions.hpp"
#include "Object.hpp"
#include "Shape.hpp"
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

	// Window構造体を生成
	GLFWwindow* const window = glfwCreateWindow(WIDTH, HEIGHT, "SAMPLE", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cerr << "Can't create GLFW window." << endl;
		return 1;
	}

	// 作成したWindowをOpenGLの処理対象に指定
	glfwMakeContextCurrent(window);
	cout << glGetString(GL_VERSION) << endl;
	// GLEWの初期化
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Can't initialize GLEW." << std::endl;
		return 1;
	}

	// 垂直同期のタイミングを待つ
	glfwSwapInterval(1);

	glClearColor(0.f, 0.f, 0.2f, 0.2f);

	glViewport(100, 50, 300, 300);
	// プログラムオブジェクトを作成する
	const GLuint program(prs::loadProgram("point.vert", "point.frag"));

	std::unique_ptr<const prs::Shape> shape(new prs::Shape(2, 4, rectangleVetex));

	while (glfwWindowShouldClose(window) == GL_FALSE)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(program);

		shape->draw();

		glfwSwapBuffers(window);

		glfwWaitEvents();
		if (glfwGetKey(window, GLFW_KEY_ENTER)) return 0;
	}

}