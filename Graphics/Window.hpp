#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace prs
{
	class Window
	{
		GLFWwindow* const window;
		GLdouble size[2];
		GLdouble scale;
	public:
		Window(int, int, const char*);
		virtual ~Window();
		explicit operator bool();
		void swapBuffers() const;
		static void resize(GLFWwindow* const, int, int);
		const GLdouble* getSize() const { return size; }
		GLdouble getScale() const { return scale; }
	};
}
