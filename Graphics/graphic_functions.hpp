#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <fstream>

namespace prs
{
	GLuint createProgram(const char* vsrc, const char* fsrc);
	GLboolean printShaderInfoLog(GLuint shader, const char* str);
	GLboolean printProgramInfoLog(GLuint program);
	bool readShaderSource(const char* name, std::vector<GLchar>& buffer);
	GLuint loadProgram(const char* vert, const char* flag);
}