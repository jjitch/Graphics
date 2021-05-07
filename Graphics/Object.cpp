#include "Object.hpp"

prs::Object::Object(GLuint size, GLsizei vertexcount, const Vertex* vertex)
{
	// ���_�z��I�u�W�F�N�gVAO�����
	glGenVertexArrays(1, &vao);
	// VAO��R�Â���(�ݒ�p)
	glBindVertexArray(vao);
	// ���_�o�b�t�@�I�u�W�F�N�g���쐬����B
	// glGenBuffers(GLsizei n, GLuint *buffers)
	// n -> �쐬���钸�_�o�b�t�@�I�u�W�F�N�g�̐�
	// buffers -> �쐬�������_�o�b�t�@�I�u�W�F�N�g���i�[����z��B
	//            ���Ȃ��Ƃ�n�̗v�f�������Ȃ���΂����Ȃ�
	glGenBuffers(1, &vbo);
	// ���_�o�b�t�@�I�u�W�F�N�g�̌����Ώ�
	// glBindBuffer(GLenum target, GLuint buffer)
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// ���_�o�b�t�@�I�u�W�F�N�g�̃��������m�ۂ��A�����Ƀf�[�^(���_����)��]������B
	glBufferData(GL_ARRAY_BUFFER, vertexcount * sizeof(Vertex), vertex, GL_STATIC_DRAW);

	// glVertexAttribPointer(GLuint index, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
	// index : �V�F�[�_�[�v���O�����̃����N����glBindAttribLocation()�֐��Ŏw�肵���A�f�[�^���󂯎��attribute�ϐ��̏ꏊ�B
	// ���̃V�F�[�_�[�v���O�����ł�vertex�̗B��̃����oposition��index��0���w�肵���̂ŁA�����ł�0���w�肷��B
	glVertexAttribPointer(0, size, GL_DOUBLE, GL_TRUE, 0, 0);
	//glVertexAttribLPointer(0, size, GL_DOUBLE, 0, 0);

	glEnableVertexAttribArray(0);
}

prs::Object::~Object()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

void prs::Object::bind() const
{
	glBindVertexArray(vao);
}