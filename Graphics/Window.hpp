#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace prs
{
	class Window
	{
		GLFWwindow* const window;
		GLdouble aspect;
	public:
		Window(size_t width, size_t height, const char* title);
		virtual ~Window();
		explicit operator bool();
		void swapBuffers() const;
		static void resize(GLFWwindow* const window, int width, int height);
		GLdouble getAspect() const { return aspect; }
	};
}
