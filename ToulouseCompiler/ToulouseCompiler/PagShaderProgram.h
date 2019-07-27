#pragma once

#include <glm.hpp>
#include <string>
#include "Log.h"
#include "OpenGLFunctions.h"

class PagShaderProgram
{
private:
	QOpenGLFunctions* gl;

	// Identificador del shader
	GLuint handler;

	//Flag que indica si el shader se ha enlazado correctamente
	bool linked;

	// Último mensaje de error del shader
	std::string logString;

	bool showUniformDebugMessages = true;

public:
	PagShaderProgram();
	~PagShaderProgram();

	void setGLFunctions(QOpenGLContext* gl) { this->gl = gl->functions(); };

	/**
	 * Crea un shader program a partir de un fichero
	 * Busca entre los recursos de la aplicación los ficheros [filename]-vert.glsl y [filename]-frag.glsl
	 */
	GLuint createShaderProgram(const std::string& filename);

	GLuint getHandler() {
		return handler;
	}
	/**
	 * Activa el shader program
	 */
	bool use();

	/**
	 * Asignación de uniforms al shader
	 */
	bool setUniform(std::string name, GLfloat value);
	bool setUniform(std::string name, GLint value);
	bool setUniform(std::string name, glm::mat4 value);
	bool setUniform(std::string name, glm::vec3 value);
	bool setUniform(std::string name, bool value);

	std::string getShaderError() { return logString; };

private:
	/**
	 * Método que compila cada una de las partes del shader
	 */
	GLuint compileShader(const std::string& filename, GLenum shaderType);
};

