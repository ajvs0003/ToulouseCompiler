#pragma once
#include "PagShaderProgram.h"
#include <glm.hpp>
#include <string>
#include <vector>

class PagTexture
{

private:

	unsigned width; 
	unsigned height;

	std::vector<unsigned char> image;
	
	OpenGLFunctions *gl;

	


	GLuint textureId;
	
	
	

public:





	PagTexture(OpenGLFunctions *_gl,unsigned _width,unsigned _height,std::string filename);

	

	void aplicateTexture(PagShaderProgram &shader, std::string type);


	





	~PagTexture();
	
};

