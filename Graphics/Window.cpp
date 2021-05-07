#include "Window.hpp"


prs::Window::Window(size_t width, size_t height, const char* title = "Title") :
	window(glfwCreateWindow(width, height, title, nullptr, nullptr))
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
}

prs::Window::~Window()
{
	glfwDestroyWindow(window);
}

prs::Window::operator bool()
{
	glfwWaitEvents();
	return !glfwWindowShouldClose(window);
}

void prs::Window::swapBuffers() const
{
	glfwSwapBuffers(window);
}