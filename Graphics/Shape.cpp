#include "Shape.hpp"

namespace prs
{
	Shape::Shape(const std::vector<glm::dvec3>& vertex, const std::vector<GLuint>& index)
		: object(new Object(vertex, index)) {}

	void Shape::draw() const
	{
		object->bind();
		execute();
	}
	
	void Shape::execute() const
	{
		glDrawElements(GL_LINES, object->index.size(), GL_UNSIGNED_INT, 0);
	}
}