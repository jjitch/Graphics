#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace C
{
	constexpr GLclampf bgRed = 0.f;
	constexpr GLclampf bgGreen = 0.f;
	constexpr GLclampf bgBlue = 0.2f;
	constexpr GLclampf bgAlpha = 0.f;
	constexpr GLuint vertexDim = 3;
	constexpr GLuint attrLoc = 0;
	constexpr GLuint fragLoc = 0;
	constexpr int winWidth = 640;
	constexpr int winHeight = 480;
	constexpr char winTitle[] = "OASOBI";
	constexpr GLdouble initialScale = 200.;
	constexpr GLdouble wheelSensitivity = 30.;
	constexpr GLdouble dirKeySensitivity = 25.;
}