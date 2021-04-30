#pragma once
#include <memory>

#include "Object.hpp"

namespace prs
{
	class Shape
	{
		/// <summary>
		/// the data of figure
		/// </summary>
		std::shared_ptr <const Object> object;
	protected:
		/// <summary>
		/// the number of vertexes used in drawing
		/// </summary>
		const GLsizei vertexcount;
	public:
		/// <summary>
		/// constructor
		/// </summary>
		/// <param name="size">: the dimension of vertex</param>
		/// <param name="vertexcount">: the number of vertexes</param>
		/// <param name="vertex">: the array includiong vertex sttribute</param>
		Shape(GLuint size, GLsizei vertexcount, const Object::Vertex* vertex);
		/// <summary>
		/// drawing
		/// </summary>
		void draw() const;
		/// <summary>
		/// execute drawing
		/// </summary>
		virtual void execute() const;
	};
}