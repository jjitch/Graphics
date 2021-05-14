#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include "constants.hpp"

namespace prs
{
	/// <summary>
	/// 図形データ
	/// </summary>
	class Object
	{
		// 頂点配列オブジェクト
		GLuint vao;
		// 頂点バッファオブジェクト
		GLuint vbo;

		// インデックスバッファオブジェクト
		GLuint ibo;
		Object(const Object& o);
		Object& operator=(const Object& o) {}

	public:
		std::vector<glm::dvec3> vertex;
		std::vector<GLuint> index;
		
		Object(const std::vector<glm::dvec3>&, const std::vector<GLuint>&);
		virtual ~Object();

		void bind() const;
	};
}