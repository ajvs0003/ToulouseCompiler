#include "PagTexture.h"
#include "Log.h"
#include "lodepng.h"



PagTexture::PagTexture(OpenGLFunctions *_gl, unsigned _width, unsigned _height, std::string filename)
{
	gl = _gl;
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



	gl->glBindTexture(GL_TEXTURE_2D, textureId);
	gl->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	gl->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	gl->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	gl->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	gl->glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,image.data());
	gl->glGenerateMipmap(GL_TEXTURE_2D);

}




PagTexture::~PagTexture()
{
}

void PagTexture::aplicateTexture(PagShaderProgram &shader, std::string type) {

	if (type == "texture") {
		shader.setUniform("TexSamplerColor", GL_TEXTURE0);
		gl->glActiveTexture(GL_TEXTURE0);
		gl->glBindTexture(GL_TEXTURE_2D, textureId);
	}
	else if (type == "bumpMapping") {

		shader.setUniform("TexSamplerBump", GL_TEXTURE1);
		gl->glActiveTexture(GL_TEXTURE1);
		gl->glBindTexture(GL_TEXTURE_2D, textureId);

	}
	else if (type == "displacement") {
		shader.setUniform("TexSamplerBump", GL_TEXTURE2);
		gl->glActiveTexture(GL_TEXTURE2);
		gl->glBindTexture(GL_TEXTURE_2D, textureId);
	}

}