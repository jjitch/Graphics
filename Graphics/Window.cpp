#include "Window.hpp"


prs::Window::Window(int width, int height, const char* title = "Title") :
	window(glfwCreateWindow(width, height, title, nullptr, nullptr)),
	scale(C::initialScale), location{0.,0.}, keyStatus(GLFW_RELEASE)
{
	if (window == nullptr)
	{
		std::cerr << "Can't create GLFW window." << std::endl;
		exit(1);
	}
	// 作成したWindowをOpenGLの処理対象に指定
	glfwMakeContextCurrent(window);
	std::cout << glGetString(GL_VERSION) << std::endl;
	// GLEWの初期化
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Can't initialize GLEW." << std::endl;
		exit(1);
	}

	// 垂直同期のタイミングを待つ
	glfwSwapInterval(1);

	// サイズ変更時のコールバック関数
	glfwSetWindowSizeCallback(window, resize);

	// マウスホイール操作時のコールバック関数
	glfwSetScrollCallback(window, wheel);

	glfwSetKeyCallback(window, keyboard);

	//このインスタンスのthisポインタを紐づけておく
	glfwSetWindowUserPointer(window, this);

	//開いたウィンドウの初期設定
	resize(window, width, height);
}

prs::Window::~Window()
{
	glfwDestroyWindow(window);
}

prs::Window::operator bool()
{
	/*if (keyStatus==GLFW_RELEASE)
	{
		glfwWaitEvents();
	}
	else
	{
		glfwPollEvents();
	}*/

	glfwPollEvents();

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		location[0] -= C::dirKeySensitivity / size[0];
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		location[0] += C::dirKeySensitivity / size[0];
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		location[1] -= C::dirKeySensitivity / size[1];
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		location[1] += C::dirKeySensitivity / size[1];
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1)!=GLFW_RELEASE)
	{

		double x, y;
		glfwGetCursorPos(window, &x, &y);

		location[0] = static_cast<GLdouble>(x) * 2. / size[0] - 1.;
		location[1] = static_cast<GLdouble>(-y) * 2. / size[1] + 1.;

	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE)||glfwGetKey(window, GLFW_KEY_ENTER)) return false;
	return !glfwWindowShouldClose(window);
}

void prs::Window::swapBuffers() const
{
	glfwSwapBuffers(window);
}

void prs::Window::resize(GLFWwindow* const window, int width, int height)
{
	int fbWidth, fbHeight;
	glfwGetFramebufferSize(window, &fbWidth, &fbHeight);

	glViewport(0, 0, fbWidth, fbHeight);

	Window* const instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));

	if (instance != nullptr)
	{
		instance->size[0] = static_cast<GLdouble>(width);
		instance->size[1] = static_cast<GLdouble>(height);
	}

}

void prs::Window::wheel(GLFWwindow* window, double x, double y){
	Window* const instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));

	if (instance!=nullptr)
	{
		instance->scale += static_cast<GLdouble>(y)*C::wheelSensitivity;
	}
}

void prs::Window::keyboard(GLFWwindow* window, int key, int scancode, int action, int mods){
	Window* const instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));
	if (instance != nullptr) instance->keyStatus = action;
}