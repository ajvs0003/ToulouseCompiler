#pragma once
#include "PagTexture.h"
#include <map>
#include "PagEnumerations.h"
#include "Log.h"


class TextureLibrary
{
private:
	static  TextureLibrary* instance;

	std::map< NameTexture, PagTexture*> texturas;

	TextureLibrary();


public:
	static TextureLibrary* getInstance();

	PagTexture* find(NameTexture name);





	~TextureLibrary();
};

