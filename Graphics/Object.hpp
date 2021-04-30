#pragma once
#include <GL/glew.h>

namespace prs
{
	class Object
	{
		/// <summary>
		/// aaa
		/// </summary>
		GLuint vao;
		GLuint vbo;
		Object(const Object& o);
		Object& operator=(const Object& o) {}

	public:
		struct Vertex
		{
			GLdouble position[2];
		};
		Object(GLuint size, GLsizei vertexcount, const Vertex* vertex);
		virtual ~Object();

		void bind() const;
	};
}