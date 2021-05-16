#pragma once

#include "Shape.hpp"

namespace prs
{
	class SolidShapeIndex :
		public Shape
	{
	public:
		SolidShapeIndex(const std::vector<glm::dvec3>&,
						const std::vector<GLuint>&,
						const std::vector<glm::dvec3>&);
		void execute() const;
	};
}

