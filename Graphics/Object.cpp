#include "Object.hpp"

prs::Object::Object(const std::vector<glm::dvec3>& _vertex,
					const std::vector<GLuint>& _index,
					const std::vector<glm::dvec3>& _color)
	:vertexCount(static_cast<GLuint>(_vertex.size())),
	indexCount(static_cast<GLuint>(_index.size()))
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
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, _vertex.size() * sizeof(glm::dvec3), _vertex.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(C::attrLocVertex, C::vertexDim, GL_DOUBLE, GL_TRUE, 0, 0);
	glEnableVertexAttribArray(C::attrLocVertex);

	glGenBuffers(1, &cbo);
	glBindBuffer(GL_ARRAY_BUFFER, cbo);
	glBufferData(GL_ARRAY_BUFFER, _color.size() * sizeof(glm::dvec3), _color.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(C::attrLocColor, C::vertexDim, GL_DOUBLE, GL_TRUE, 0, 0);
	glEnableVertexAttribArray(C::attrLocColor);

	/*glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);*/

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _index.size() * sizeof(GLuint), _index.data(), GL_STATIC_DRAW);

	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);*/
}

prs::Object::~Object()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
}

void prs::Object::bind() const
{
	glBindVertexArray(vao);
}