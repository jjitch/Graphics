#include "SolidShapeIndex.hpp"

namespace prs
{
	SolidShapeIndex::SolidShapeIndex(const std::vector<glm::dvec3>& _vertex,
									 const std::vector<GLuint>& _index,
									 const std::vector<glm::dvec3>& _color)
		: Shape(_vertex, _index, _color) {}

	void SolidShapeIndex::execute() const
	{
		glDrawElements(GL_TRIANGLES, object->indexCount, GL_UNSIGNED_INT, 0);
	}
}