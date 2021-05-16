#pragma once
#include <memory>
#include <GL/glew.h>
#include "Object.hpp"

namespace prs
{
	/// <summary>
	/// �}�`�f�[�^��ێ����A�Ǘ�����N���X
	/// �}�`�f�[�^(�I�u�W�F�N�g)�̃|�C���^��ێ�����
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
		/// ���_�̎����A���A�\���̂��󂯎��A�I�u�W�F�N�g������������
		/// </summary>
		/// <param name="size">���_�̎���</param>
		/// <param name="vertexcount">���_�̐�</param>
		/// <param name="vertex">���_�̍\����</param>
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