#pragma once
#include <memory>
#include <GL/glew.h>
#include "Object.hpp"

namespace prs
{
	/// <summary>
	/// 図形データを保持し、管理するクラス
	/// 図形データ(オブジェクト)のポインタを保持する
	/// </summary>
	class Shape
	{
	protected:
		/// <summary>
		/// the data of figure
		/// </summary>
		std::shared_ptr<const Object> object;
	public:
		/// <summary>
		/// 頂点の次元、数、構造体を受け取り、オブジェクトを初期化する
		/// </summary>
		/// <param name="size">頂点の次元</param>
		/// <param name="vertexcount">頂点の数</param>
		/// <param name="vertex">頂点の構造体</param>
		Shape(const std::vector<glm::dvec3>&,
			  const std::vector<GLuint>&,
			  const std::vector<glm::dvec3>&);
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