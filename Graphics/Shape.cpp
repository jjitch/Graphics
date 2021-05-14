#include "Shape.hpp"

namespace prs
{
	Shape::Shape(const std::vector<glm::dvec3>& vertex) : object(new Object(vertex)) {}


	void Shape::draw() const
	{
		object->bind();
		execute();
	}
	
	void Shape::execute() const
	{
		glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(object->Vertex.size()));
	}
}