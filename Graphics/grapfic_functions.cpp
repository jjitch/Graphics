#include "graphic_functions.hpp"

namespace prs
{
	GLuint createProgram(const char* vsrc, const char* fsrc)
	{
		const GLuint program(glCreateProgram());

		if (vsrc != NULL)
		{
			const GLuint vobj(glCreateShader(GL_VERTEX_SHADER));
			glShaderSource(vobj, 1, &vsrc, NULL);
			glCompileShader(vobj);
			if (printShaderInfoLog(vobj, "vertex shader")) glAttachShader(program, vobj);
			glDeleteShader(vobj);
		}

		if (fsrc != NULL)
		{
			const GLuint fobj(glCreateShader(GL_FRAGMENT_SHADER));
			glShaderSource(fobj, 1, &fsrc, NULL);
			glCompileShader(fobj);
			if (printShaderInfoLog(fobj, "fragment shader")) glAttachShader(program, fobj);
			glDeleteShader(fobj);
		}
		glBindAttribLocation(program, C::attrLoc, "position");
		glBindFragDataLocation(program, C::fragLoc, "fragment");
		glLinkProgram(program);
		if (printProgramInfoLog(program)) return program;
		glDeleteProgram(program);
		return 0;
	}

	GLboolean printShaderInfoLog(GLuint shader, const char* str)
	{
		GLint status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE) std::cerr << "Compile Error in " << str << std::endl;

		GLsizei bufSize;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &bufSize);
		if (bufSize > 1)
		{
			std::vector<GLchar> infoLog(bufSize);
			std::string log;
			GLsizei length;
			glGetShaderInfoLog(shader, bufSize, &length, infoLog.data());
			std::cerr << infoLog.data() << std::endl;
		}
		return static_cast<GLboolean>(status);
	}

	GLboolean printProgramInfoLog(GLuint program)
	{
		GLint status;
		glGetShaderiv(program, GL_LINK_STATUS, &status);
		if (status == GL_FALSE) std::cerr << "Link Error." << std::endl;

		GLsizei bufSize;
		glGetShaderiv(program, GL_INFO_LOG_LENGTH, &bufSize);
		if (bufSize > 1)
		{
			std::vector<GLchar> infoLog(bufSize);
			GLsizei length;
			glGetShaderInfoLog(program, bufSize, &length, infoLog.data());
			std::cerr << infoLog.data() << std::endl;
		}
		return static_cast<GLboolean>(status);
	}

	bool readShaderSource(const char* name, std::vector<GLchar>& buffer)
	{
		if (name == NULL) return false;
		std::ifstream file(name, std::ios::binary);
		if (file.fail())
		{
			std::cerr << "Error: Can't open source file: " << name << std::endl;
			return false;
		}
		file.seekg(0L, std::ios::end);
		GLsizei length = static_cast<GLsizei>(file.tellg());
		buffer.resize(length + 1);

		file.seekg(0L, std::ios::beg);
		file.read(buffer.data(), length);
		buffer[length] = '\0';

		if (file.fail())
		{
			std::cerr << "Error: Couldn't read source file: " << name << std::endl;
			file.close();
			return false;
		}
		file.close();
		return true;
	}

	GLuint loadProgram(const char* vert, const char* flag)
	{
		std::vector<GLchar> vsrc;
		const bool vstat(readShaderSource(vert, vsrc));
		std::vector<GLchar> fsrc;
		const bool fstat(readShaderSource(flag, fsrc));
		return vstat && fstat ? createProgram(vsrc.data(), fsrc.data()) : 0;
	}
}
