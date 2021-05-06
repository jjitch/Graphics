#include "Object.hpp"

prs::Object::Object(GLuint size, GLsizei vertexcount, const Vertex* vertex)
{
	// 頂点配列オブジェクト
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// 頂点バッファオブジェクトを作成する。
	// glGenBuffers(GLsizei n, GLuint *buffers)
	// n -> 作成する頂点バッファオブジェクトの数
	// buffers -> 作成した頂点バッファオブジェクトを格納する配列。
	//            少なくともnの要素を持たなければいけない
	glGenBuffers(1, &vbo);
	// 頂点バッファオブジェクトの結合対象
	// glBindBuffer(GLenum target, GLuint buffer)
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// 頂点バッファオブジェクトのメモリを確保し、そこにデータ(頂点属性)を転送する。
	glBufferData(GL_ARRAY_BUFFER, vertexcount * sizeof(Vertex), vertex, GL_STATIC_DRAW);

	// glVertexAttribPointer(GLuint index, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
	glVertexAttribPointer(0, size, GL_DOUBLE, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
}

prs::Object::~Object()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

void prs::Object::bind() const
{
	glBindVertexArray(vao);
}