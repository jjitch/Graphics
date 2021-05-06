#pragma once
#include <GL/glew.h>

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
		struct Vertex
		{
			GLdouble position[2];
		};
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="size">���_�̈ʒu�̎���</param>
		/// <param name="vertexcount">���_�̐�</param>
		/// <param name="vertex">���_�������i�[�����z��</param>
		Object(GLuint size, GLsizei vertexcount, const Vertex* vertex);
		virtual ~Object();

		void bind() const;
	};
}