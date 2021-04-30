#include "Object.hpp"

prs::Object::Object(GLuint size, GLsizei vertexcount, const Vertex* vertex)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexcount * sizeof(Vertex), vertex, GL_STATIC_DRAW);

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