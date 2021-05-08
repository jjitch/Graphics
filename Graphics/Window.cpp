#include "Window.hpp"


prs::Window::Window(int width, int height, const char* title = "Title") :
	window(glfwCreateWindow(width, height, title, nullptr, nullptr)), scale(100.)
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

	glfwSetWindowUserPointer(window, this);

	glfwSetWindowSizeCallback(window, resize);
	resize(window, width, height);
}

prs::Window::~Window()
{
	glfwDestroyWindow(window);
}

prs::Window::operator bool()
{
	glfwWaitEvents();
	if (glfwGetKey(window, GLFW_KEY_UP)) scale+=1.;
	if (glfwGetKey(window, GLFW_KEY_ENTER)) return false;
	std::cout << scale << std::endl;
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