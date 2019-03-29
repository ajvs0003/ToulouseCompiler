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
	


	


	GLuint textureId;
	
	
	

public:
	PagTexture(unsigned _width,unsigned _height,std::string filename);

	

	void aplicateTexture(PagShaderProgram &shader, std::string type);


	





	~PagTexture();
	
};

