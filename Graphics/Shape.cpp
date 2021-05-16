#include "Shape.hpp"

namespace prs
{
	Shape::Shape(const std::vector<glm::dvec3>& _vertex,
				 const std::vector<GLuint>& _index,
				 const std::vector<glm::dvec3>& _color)
		: object(new Object(_vertex, _index, _color)) {}

	void Shape::draw() const
	{
		object->bind();
		execute();
	}
	
	void Shape::execute() const
	{
		glDrawElements(GL_LINES, object->indexCount, GL_UNSIGNED_INT, 0);
	}
}