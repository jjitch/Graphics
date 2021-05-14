#pragma once
#include <GL/glew.h>
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
		std::vector<glm::dvec3> Vertex;
		
		Object(const std::vector<glm::dvec3>&, const std::vector<GLuint>&);
		virtual ~Object();

		void bind() const;
	};
}