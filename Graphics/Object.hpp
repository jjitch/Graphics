#pragma once
#include <GL/glew.h>

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
		struct Vertex
		{
			GLdouble position[2];
		};
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="size">頂点の位置の次元</param>
		/// <param name="vertexcount">頂点の数</param>
		/// <param name="vertex">頂点属性を格納した配列</param>
		Object(GLuint size, GLsizei vertexcount, const Vertex* vertex);
		virtual ~Object();

		void bind() const;
	};
}