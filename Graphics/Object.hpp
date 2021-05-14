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
		Object(const Object& o);
		Object& operator=(const Object& o) {}

	public:
		std::vector<glm::dvec3> vertex;
		std::vector<GLuint> index;
		
		Object(const std::vector<glm::dvec3>&, const std::vector<GLuint>&);
		virtual ~Object();

		void bind() const;
	};
}