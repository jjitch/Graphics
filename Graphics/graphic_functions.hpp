#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "constants.hpp"

namespace prs
{
	/// <summary>
	/// プログラムオブジェクトを作成する
	/// </summary>
	/// <param name="vsrc">バーテックスシェーダーのソース</param>
	/// <param name="fsrc">フラグメントシェーダーのソース</param>
	/// <returns>プログラムオブジェクトの番号
	/// 作成できなかった場合は0を返す</returns>
	GLuint createProgram(const char* vsrc, const char* fsrc);

	/// <summary>
	/// シェーダーオブジェクトのコンパイル結果を表示する
	/// </summary>
	/// <param name="shader">シェーダーオブジェクト</param>
	/// <param name="str">コンパイルエラーが発生した場所を示す文字列
	/// バーテックス or フラグメント</param>
	/// <returns>コンパイルが成功していたらGL_TRUEを、そうでなければGL_FALSEを返す</returns>
	GLboolean printShaderInfoLog(GLuint shader, const char* str);

	/// <summary>
	/// プログラムオブジェクトのリンク結果を表示する
	/// </summary>
	/// <param name="program">プログラムオブジェクト</param>
	/// <returns>リンクが成功していたらGL_TRUEを、そうでなければGL_FALSEを返す</returns>
	GLboolean printProgramInfoLog(GLuint program);

	/// <summary>
	/// シェーダーのソースファイルをバッファに取り込む
	/// </summary>
	/// <param name="name">シェーダーのソースファイル</param>
	/// <param name="buffer">バッファ</param>
	/// <returns></returns>
	bool readShaderSource(const char* name, std::vector<GLchar>& buffer);

	/// <summary>
	/// シェーダーのソースファイルを読み込み、プログラムオブジェクトを作成する
	/// </summary>
	/// <param name="vert">バーテックスシェーダーのソース</param>
	/// <param name="flag">フラグメントシェーダーのソース</param>
	/// <returns></returns>
	GLuint loadProgram(const char* vert, const char* flag);
}
