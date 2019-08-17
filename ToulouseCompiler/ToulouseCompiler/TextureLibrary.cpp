#include "TextureLibrary.h"

TextureLibrary* TextureLibrary::instance = nullptr;

TextureLibrary::TextureLibrary(OpenGLFunctions *_gl)
{

	gl = _gl;

	PagTexture* large;
	large = new PagTexture(gl,1024,1024, QString(QDir::currentPath() + "/Textures/uv_checker large.png").toStdString());
	


	PagTexture* half;
	half = new PagTexture(gl, 1024, 512, QString(QDir::currentPath() + "/Textures/uv_checker vHalf.png").toStdString());




	PagTexture* quart;
	quart = new PagTexture(gl, 1024, 256, QString(QDir::currentPath() + "/Textures/uv_checker vQuart.png").toStdString());



	
	texturas.insert(std::pair<NameTexture, PagTexture*> (TEXT, large));
	texturas.insert(std::pair<NameTexture, PagTexture*>(TEXT2, half));
	texturas.insert(std::pair<NameTexture, PagTexture*>(TEXT3, quart));
	



}

TextureLibrary* TextureLibrary::getInstance(OpenGLFunctions *_gl)
{
	if (!instance) {
		instance = new TextureLibrary(_gl);
	}


	return instance;




}

PagTexture* TextureLibrary::find(NameTexture name)
{
	std::map<NameTexture, PagTexture* >::iterator it;
	it = texturas.find(name);
	if (it != texturas.end())
		return it->second;
	else return nullptr;


}

TextureLibrary::~TextureLibrary()
{
}
