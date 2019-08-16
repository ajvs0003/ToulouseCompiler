#pragma once
#include "PagTexture.h"
#include <map>
#include "PagEnumerations.h"
#include "Log.h"


class TextureLibrary
{
private:
	OpenGLFunctions* gl;
	static  TextureLibrary* instance;

	std::map< NameTexture, PagTexture*> texturas;

	TextureLibrary(OpenGLFunctions *_gl);


public:
	static TextureLibrary* getInstance(OpenGLFunctions *_gl);

	PagTexture* find(NameTexture name);





	~TextureLibrary();
};

