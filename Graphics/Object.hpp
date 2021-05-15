#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include "constants.hpp"

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

		// �C���f�b�N�X�o�b�t�@�I�u�W�F�N�g
		GLuint ibo;

		// �R�s�[�R���X�g���N�^�̋֎~
		Object(const Object&);
		Object& operator=(const Object&) {}

	public:
		const GLuint vertexCount;
		const GLuint indexCount;
		void bind() const;
		
		Object(const std::vector<glm::dvec3>&, const std::vector<GLuint>&);
		virtual ~Object();
	};
}