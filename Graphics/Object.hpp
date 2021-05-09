#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

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
		Object(const Object& o);
		Object& operator=(const Object& o) {}

	public:
		std::vector<glm::dvec2> Vertex;
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="size">頂点の位置の次元</param>
		/// <param name="vertexcount">頂点の数</param>
		/// <param name="vertex">頂点属性を格納した配列</param>
		Object(const std::vector<glm::dvec2>&);
		virtual ~Object();

		void bind() const;
	};
}