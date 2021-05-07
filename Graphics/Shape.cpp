#include "Shape.hpp"

namespace prs
{
	
	Shape::Shape(GLuint size, GLsizei vertexcount, const Object::Vertex *vertex)
		:object(new Object(size, vertexcount, vertex)), vertexcount(vertexcount){}
	
	void Shape::draw() const
	{
		object->bind();
		execute();
	}
	
	void Shape::execute() const
	{
		glDrawArrays(GL_TRIANGLES, 0, vertexcount);
	}
}