#include "PagShaderProgram.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <QOpenGLFunctions>

PagShaderProgram::PagShaderProgram()
{
	handler = 0;
	linked = false;
	logString = "";
}

PagShaderProgram::~PagShaderProgram()
{
	/*gl->glDeleteProgram(handler);*/
	linked = false;
	logString = "";
}

GLuint PagShaderProgram::createShaderProgram(const std::string& filename) 
{
	// - Creamos el shader program y almacenamos su identificador
	if (handler <= 0) 
	{
		handler = gl->glCreateProgram();
		if (handler == 0) 
		{
			std::cerr << "Cannot create shader program: " << filename << std::endl;
			return 0;
		}
	}

	// - Cargamos y compilamos cada uno de los shader objects que componen este
	// shader program
	GLuint vertexShaderObject = compileShader((filename + "-vert.glsl").c_str(), GL_VERTEX_SHADER);
	if (vertexShaderObject == 0) 
		return 0;

	GLuint fragmentShaderObject = compileShader((filename + "-frag.glsl").c_str(), GL_FRAGMENT_SHADER);
	if (fragmentShaderObject == 0) 
		return 0;

	GLuint geometryShaderObject = compileShader((filename + "-geom.glsl").c_str(), GL_GEOMETRY_SHADER);

	// - Asociamos los shader objects compilados sin errores al shader program
	gl->glAttachShader(handler, vertexShaderObject);
	gl->glAttachShader(handler, fragmentShaderObject);
	if (geometryShaderObject != 0)
	{
		std::cout << "Habemus geometry shader! (" << filename << "-geom.glsl)" << std::endl;
		gl->glAttachShader(handler, geometryShaderObject);
	}

	// - Enlazamos el shader program y comprobamos si hay errores
	gl->glLinkProgram(handler);
	GLint linkSuccess = 0;
	gl->glGetProgramiv(handler, GL_LINK_STATUS, &linkSuccess);
	if (linkSuccess == GL_FALSE) 
	{
		GLint logLen = 0;
		gl->glGetProgramiv(handler, GL_INFO_LOG_LENGTH, &logLen);
		if (logLen > 0) 
		{
			char * cLogString = new char[logLen];
			GLint written = 0;
			gl->glGetProgramInfoLog(handler, logLen, &written, cLogString);
			logString.assign(cLogString);

			delete[] cLogString;


			//aqui detectamos los posibles errores del shader
			std::cout << "Cannot link shader " << filename << std::endl
				<< logString << std::endl;
		}
		return 0;
	}
	else 
	{
		linked = true;
	}

	return handler;
}

bool PagShaderProgram::use() 
{
	// - Antes de activar un shader program para su uso, hay que comprobar
	// si se ha creado bien y se ha enlazado bien
	if ((handler > 0) && (linked)) 
	{
		gl->glUseProgram(handler);
		return true;
	}
	else 
	{
		std::cout << "Cannot use shader program"<<endl;
		return false;
	}
}
bool PagShaderProgram::setUniform(std::string name, GLint value) 
{
	// - Para asignar valor a un uniform, primero hay que buscar si en el shader
	// program existe alguna variable de tipo uniform cuyo nombre coincida con
	// el que pasamos como argumento
	GLint location = gl->glGetUniformLocation(handler, name.c_str());
	// - Si location es un valor positivo, es que existe el uniform y podemos
	// asignarlo
	if (location >= 0) 
	{
		// - Aquí usamos la función glUniform que recibe un argumento de tipo
		// GLint
		gl->glUniform1i(location, value);
		return true;
	}
	else 
	{
		if (showUniformDebugMessages)
			std::cout << "Cannot find localization for: " << name << std::endl;
		return false;
	}
}

bool PagShaderProgram::setUniform(std::string name, GLfloat value) 
{
	GLint location = gl->glGetUniformLocation(handler, name.c_str());
	if (location >= 0) 
	{
		// - Aquí usamos la función glUniform que recibe un argumento de tipo
		// GLfloat
		gl->glUniform1f(location, value);
		return true;
	}
	else 
	{
		if (showUniformDebugMessages)
			std::cout << "Cannot find localization for: " << name << std::endl;
		return false;
	}
}

bool PagShaderProgram::setUniform(std::string name, glm::mat4 value) 
{
	GLint location = gl->glGetUniformLocation(handler, name.c_str());
	if (location >= 0) 
	{
		// - Aquí usamos la función glUniform que recibe un argumento de tipo
		// mat4 con valores GLfloat y expresado como un array
		gl->glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
		return true;
	}
	else 
	{
		if (showUniformDebugMessages)
			std::cout << "Cannot find localization for: " << name << std::endl;
		return false;
	}
}
bool PagShaderProgram::setUniform(std::string name, glm::vec3 value) 
{
	GLint location = gl->glGetUniformLocation(handler, name.c_str());
	if (location >= 0) 
	{
		// - Aquí usamos la función glUniform que recibe un argumento de tipo
		// vec3 con valores GLfloat y expresado como un array
		gl->glUniform3fv(location, 1, &value[0]);
		return true;
	}
	else 
	{
		if (showUniformDebugMessages)
			std::cout << "Cannot find localization for: " << name << std::endl;
		return false;
	}
}

bool PagShaderProgram::setUniform(std::string name, bool value)
{
	// - Para asignar valor a un uniform, primero hay que buscar si en el shader
	// program existe alguna variable de tipo uniform cuyo nombre coincida con
	// el que pasamos como argumento
	GLint location = gl->glGetUniformLocation(handler, name.c_str());
	// - Si location es un valor positivo, es que existe el uniform y podemos
	// asignarlo
	if (location >= 0) 
	{
		// - Aquí usamos la función glUniform que recibe un argumento de tipo
		gl->glUniform1i(location, value);
		return true;
	}
	else 
	{
		if (showUniformDebugMessages)
			std::cout << "Cannot find localization for: " << name << std::endl;
		return false;
	}
}

GLuint PagShaderProgram::compileShader(const std::string& filename, GLenum shaderType)
{
	// - Si existe se lee en una cadena de caracteres que contiene el listado
	// completo del shader source
	std::ifstream shaderSourceFile;
	shaderSourceFile.open(filename);
	if (!shaderSourceFile) 
	{
		if (shaderType == GL_GEOMETRY_SHADER)
		{
			return 0; // Para no ensuciar la consola con shaders opcionales
		}

		std::cout << "Cannot open shader source file: " << filename << std::endl;
		return 0;
	}

	std::stringstream shaderSourceStream;
	shaderSourceStream << shaderSourceFile.rdbuf();
	std::string shaderSourceString = shaderSourceStream.str();
	shaderSourceFile.close();
	// - Creamos un shader object para ese archivo que se ha leído
	GLuint shaderHandler = gl->glCreateShader(shaderType);
	if (shaderHandler == 0) 
	{
		std::cout << "Cannot create shader object" << std::endl;
		return 0;
	}
	// - Le asignamos el código fuente leído y lo compilamos
	const char * shaderSourceCString = shaderSourceString.c_str();
	gl->glShaderSource(shaderHandler, 1, &shaderSourceCString, NULL);
	gl->glCompileShader(shaderHandler);
	// - Se comprueba si la compilación se ha realizado con éxito
	GLint compileResult;
	gl->glGetShaderiv(shaderHandler, GL_COMPILE_STATUS, &compileResult);
	if (compileResult == GL_FALSE) 
	{
		GLint logLen = 0;
		logString = "";
		gl->glGetShaderiv(shaderHandler, GL_INFO_LOG_LENGTH, &logLen);
		if (logLen > 0) 
		{
			char * cLogString = new char[logLen];
			GLint written = 0;
			gl->glGetShaderInfoLog(shaderHandler, logLen, &written, cLogString);
			logString.assign(cLogString);
			delete[] cLogString;
			std::cout << "Cannot compile shader " << shaderType << std::endl
				<< logString << std::endl;
		}
	}
	return shaderHandler;
}
