#include "Object.hpp"

prs::Object::Object(const std::vector<glm::dvec2>& vertex):Vertex(vertex)
{
	// 頂点配列オブジェクトVAOを作る
	glGenVertexArrays(1, &vao);

	// VAOを紐づける(設定用)
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
	glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(glm::dvec2), &vertex[0], GL_DYNAMIC_DRAW);


	// glVertexAttribPointer(GLuint index, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
	// index : シェーダープログラムのリンク時にglBindAttribLocation()関数で指定した、データを受け取るattribute変数の場所。
	// このシェーダープログラムではvertexの唯一のメンバpositionのindexに0を指定したので、ここでは0を指定する。
	glVertexAttribPointer(C::attrLoc, C::vertexDim, GL_DOUBLE, GL_TRUE, 0, 0);

	glEnableVertexAttribArray(C::attrLoc);
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