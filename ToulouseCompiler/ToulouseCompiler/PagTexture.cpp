#include "PagTexture.h"
#include "Log.h"
#include "lodepng.h"
#include "GL/glew.h"



PagTexture::PagTexture( unsigned _width, unsigned _height, std::string filename)
{

	width = _width;
	height = _height;
	unsigned error = lodepng::decode(image, width, height, filename);

	if (error) {
		Log::getInstancia()->error(filename+" cannot be loaded");
		return;
	}
	unsigned char *imgPtr = &image[0];
	unsigned int numColorComponentes = 4;
	unsigned int wInc = width * 4;

	unsigned char* top = nullptr;
	unsigned char* bot = nullptr;
	unsigned char temp = 0;


	for (unsigned int i = 0; i < height / 2; i++) {
		top = imgPtr + i * wInc;
		bot = imgPtr + (height - i - 1)*wInc;
		for (unsigned int j = 0; j < wInc; j++) {

			temp = *top;
			*top = *bot;
			*bot = temp;
			++top;
			++bot;



		}




	}

	
	glGenTextures(1, &textureId);



	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,image.data());
	glGenerateMipmap(GL_TEXTURE_2D);

}




PagTexture::~PagTexture()
{
}

void PagTexture::aplicateTexture(PagShaderProgram &shader, std::string type) {

	if (type == "texture") {
		shader.setUniform("TexSamplerColor", GL_TEXTURE0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureId);
	}
	else if (type == "bumpMapping") {

		shader.setUniform("TexSamplerBump", GL_TEXTURE1);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, textureId);

	}
	else if (type == "displacement") {
		shader.setUniform("TexSamplerBump", GL_TEXTURE2);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, textureId);
	}

}