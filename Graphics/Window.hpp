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
		GLdouble location[2];
		int keyStatus;
	public:
		Window(int, int, const char*);
		virtual ~Window();
		explicit operator bool();
		void swapBuffers() const;
		static void resize(GLFWwindow* const, int, int);
		static void wheel(GLFWwindow*, double, double);
		static void keyboard(GLFWwindow*, int, int, int, int);
		const GLdouble* getSize() const { return size; }
		GLdouble getScale() const { return scale; }
		const GLdouble* getLocation() const { return location; }
	};
}
