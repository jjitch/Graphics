#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace prs
{
	/// <summary>
	/// �}�`�f�[�^
	/// </summary>
	class Object
	{
		// ���_�z��I�u�W�F�N�g
		GLuint vao;
		// ���_�o�b�t�@�I�u�W�F�N�g
		GLuint vbo;
		Object(const Object& o);
		Object& operator=(const Object& o) {}

	public:
		std::vector<glm::dvec2> Vertex;
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="size">���_�̈ʒu�̎���</param>
		/// <param name="vertexcount">���_�̐�</param>
		/// <param name="vertex">���_�������i�[�����z��</param>
		Object(const std::vector<glm::dvec2>&);
		virtual ~Object();

		void bind() const;
	};
}