#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <fstream>

namespace prs
{
	/// <summary>
	/// asdad
	/// </summary>
	/// <param name="vsrc">Vertex fource program/param>
	/// <param name="fsrc">Fragment source program</param>
	/// <returns></returns>
	GLuint createProgram(const char* vsrc, const char* fsrc);

	
	GLboolean printShaderInfoLog(GLuint shader, const char* str);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="program"></param>
	/// <returns></returns>
	GLboolean printProgramInfoLog(GLuint program);
	bool readShaderSource(const char* name, std::vector<GLchar>& buffer);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="vert"></param>
	/// <param name="flag"></param>
	/// <returns></returns>
	GLuint loadProgram(const char* vert, const char* flag);
}
