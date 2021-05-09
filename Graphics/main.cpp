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

	const GLint sizeLoc(glGetUniformLocation(program, "size"));
	const GLint scaleLoc(glGetUniformLocation(program, "scale"));
	const GLint locationLoc(glGetUniformLocation(program, "location"));

	// 図形データの作成
	std::unique_ptr<const prs::Shape> shape(new prs::Shape(2, 4, rectangleVetex));

	while ((bool)window)
	{
		//ウィンドウを削除
		glClear(GL_COLOR_BUFFER_BIT);

		// シェーダプログラムの使用開始
		glUseProgram(program);
		
		// uniform変数に値を設定する
		glUniform2dv(sizeLoc, 1, window.getSize());
		glUniform1d(scaleLoc, window.getScale());
		glUniform2dv(locationLoc, 1, window.getLocation());
		
		// 図形の描画
		shape->draw();

		// カラーバッファの入れ替え
		window.swapBuffers();
	}

}