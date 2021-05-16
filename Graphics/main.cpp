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
#include "SolidShapeIndex.hpp"
#include "Window.hpp"
#include "constants.hpp"
#include "Primitives.hpp"

using std::cout;
using std::endl;;

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

	prs::Window window(C::winWidth, C::winHeight, C::winTitle);

	glClearColor(C::bgRed, C::bgGreen, C::bgBlue, C::bgAlpha);

	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glClearDepth(1.);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	// プログラムオブジェクトを作成する
	const GLuint program(prs::loadProgram("point.vert", "point.frag"));

	const GLint modelLoc(glGetUniformLocation(program, "model"));
	const GLint viewLoc(glGetUniformLocation(program, "view"));
	const GLint projLoc(glGetUniformLocation(program, "projection"));

	
	std::unique_ptr<const prs::Shape> shape(new prs::SolidShapeIndex(primitive::cubeVertex,
											primitive::solidCubeIndex,
											primitive::cubeVertexColor));

	const double aspect = sqrt(2) / 2.;
	glm::dvec3 eye=glm::normalize(glm::dvec3(0.6, -0.8, sqrt(2)*aspect/sqrt(1-pow(aspect,2))));
	const glm::dvec3 center(0., 0., 0.);
	const glm::dvec3 up(0., 0., 1.);
	const glm::dmat4 view = glm::lookAt(eye, center, up);
	
	// シェーダプログラムの使用開始
	glUseProgram(program);

	bool pressed(false);
	glfwSetTime(0.);
	while ((bool)window)
	{
		//ウィンドウを削除
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// model transform matrix
		const glm::dmat4 view = glm::lookAt(eye, center, up);
		const GLdouble* const size(window.getSize());
		const GLdouble scale(window.getScale());
		const GLdouble w(size[0] / scale), h(size[1] / scale);
		const GLdouble* const location(window.getLocation());
		const glm::dvec3 translating(location[0], location[1], 0.);
		const glm::dmat4 model = glm::rotate(glm::translate(glm::dmat4(1.), translating), glfwGetTime(), glm::dvec3(0.,0.,1.));
		const glm::dmat4 projection = glm::ortho(-w, w, -h, h, -10., 10.);

		if (glfwGetKey(window.window, GLFW_KEY_D) == GLFW_PRESS && !pressed)
		{
			cout << "debug!\n";
			cout << "scale\n" << scale << "\n\n";
			cout << "translating vector\n" << glm::to_string(translating) << "\n\n";
			cout << "model matrix\n" << glm::to_string(model) << "\n\n";
			cout << "view matrix\n" << glm::to_string(view) << "\n\n";
			cout << glm::length(view[0]) << endl;
			cout << "projection matrix\n" << glm::to_string(projection) << endl;

			pressed = true;
		}
		if (glfwGetKey(window.window, GLFW_KEY_D) != GLFW_PRESS && pressed)
		{
			pressed = false;
		}

		// uniform変数に値を設定する
		glUniformMatrix4dv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4dv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4dv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		// 図形の描画
		shape->draw();

		// カラーバッファの入れ替え
		window.swapBuffers();
	}

}