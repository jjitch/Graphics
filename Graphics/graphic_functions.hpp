#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "constants.hpp"

namespace prs
{
	/// <summary>
	/// �v���O�����I�u�W�F�N�g���쐬����
	/// </summary>
	/// <param name="vsrc">�o�[�e�b�N�X�V�F�[�_�[�̃\�[�X</param>
	/// <param name="fsrc">�t���O�����g�V�F�[�_�[�̃\�[�X</param>
	/// <returns>�v���O�����I�u�W�F�N�g�̔ԍ�
	/// �쐬�ł��Ȃ������ꍇ��0��Ԃ�</returns>
	GLuint createProgram(const char* vsrc, const char* fsrc);

	/// <summary>
	/// �V�F�[�_�[�I�u�W�F�N�g�̃R���p�C�����ʂ�\������
	/// </summary>
	/// <param name="shader">�V�F�[�_�[�I�u�W�F�N�g</param>
	/// <param name="str">�R���p�C���G���[�����������ꏊ������������
	/// �o�[�e�b�N�X or �t���O�����g</param>
	/// <returns>�R���p�C�����������Ă�����GL_TRUE���A�����łȂ����GL_FALSE��Ԃ�</returns>
	GLboolean printShaderInfoLog(GLuint shader, const char* str);

	/// <summary>
	/// �v���O�����I�u�W�F�N�g�̃����N���ʂ�\������
	/// </summary>
	/// <param name="program">�v���O�����I�u�W�F�N�g</param>
	/// <returns>�����N���������Ă�����GL_TRUE���A�����łȂ����GL_FALSE��Ԃ�</returns>
	GLboolean printProgramInfoLog(GLuint program);

	/// <summary>
	/// �V�F�[�_�[�̃\�[�X�t�@�C�����o�b�t�@�Ɏ�荞��
	/// </summary>
	/// <param name="name">�V�F�[�_�[�̃\�[�X�t�@�C��</param>
	/// <param name="buffer">�o�b�t�@</param>
	/// <returns></returns>
	bool readShaderSource(const char* name, std::vector<GLchar>& buffer);

	/// <summary>
	/// �V�F�[�_�[�̃\�[�X�t�@�C����ǂݍ��݁A�v���O�����I�u�W�F�N�g���쐬����
	/// </summary>
	/// <param name="vert">�o�[�e�b�N�X�V�F�[�_�[�̃\�[�X</param>
	/// <param name="flag">�t���O�����g�V�F�[�_�[�̃\�[�X</param>
	/// <returns></returns>
	GLuint loadProgram(const char* vert, const char* flag);
}
