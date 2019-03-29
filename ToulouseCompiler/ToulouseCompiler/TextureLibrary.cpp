#include "TextureLibrary.h"

TextureLibrary* TextureLibrary::instance = nullptr;

TextureLibrary::TextureLibrary()
{
	PagTexture* large;
	large = new PagTexture(1024,1024,"./Textures/uv_checker large.png");
	


	PagTexture* half;
	half = new PagTexture(1024, 512, "./Textures/uv_checker vHalf.png");




	PagTexture* quart;
	quart = new PagTexture(1024, 256, "./Textures/uv_checker vQuart.png");



	PagTexture* peon;
	peon = new PagTexture(1024, 1024, "./Textures/wood.png");
	
	PagTexture* tapa;
	tapa = new PagTexture(900, 600, "./Textures/mesa.png");

	PagTexture* plastico;
	plastico = new PagTexture(1024, 1024, "./Textures/plastico.png");

	PagTexture* tapaPlastico;
	tapaPlastico = new PagTexture(1024, 1024, "./Textures/tapa_plastico.png");


	PagTexture* cristal;
	cristal = new PagTexture(1024, 1024, "./Textures/cristal.png");

	PagTexture* fconde;
	fconde = new PagTexture(1024, 256, "./Textures/fconde.png");


	PagTexture* joy;
	joy = new PagTexture(1024, 1024, "./Textures/joy.png");


	PagTexture* black;
	black = new PagTexture(1024, 1024, "./Textures/black.png");

	PagTexture* gray;
	gray = new PagTexture(1024, 1024, "./Textures/gray.png");

	PagTexture* bump;
	bump = new PagTexture(1024, 1024, "./Textures/Bump/bumpJoy.png");

	PagTexture* normals;
	normals = new PagTexture(1024, 1024, "./Textures/Bump/NormalMap.png");

	texturas.insert(std::pair<NameTexture, PagTexture*>(GRAY, gray));
	texturas.insert(std::pair<NameTexture, PagTexture*>(BLACK, black));
	texturas.insert(std::pair<NameTexture, PagTexture*>(JOY, joy));
	texturas.insert(std::pair<NameTexture, PagTexture*> (TEXT, large));
	texturas.insert(std::pair<NameTexture, PagTexture*>(TEXT2, half));
	texturas.insert(std::pair<NameTexture, PagTexture*>(TEXT3, quart));
	texturas.insert(std::pair<NameTexture, PagTexture*>(PAWN, peon));
	texturas.insert(std::pair<NameTexture, PagTexture*>(TABLE, tapa));
	texturas.insert(std::pair<NameTexture, PagTexture*>(PLASTIC, plastico));
	texturas.insert(std::pair<NameTexture, PagTexture*>(PLASTIC, plastico));
	texturas.insert(std::pair<NameTexture, PagTexture*>(PLASTIC1, tapaPlastico));
	texturas.insert(std::pair<NameTexture, PagTexture*>(FCONDE, fconde));
	texturas.insert(std::pair<NameTexture, PagTexture*>(GLASS, cristal));

	texturas.insert(std::pair<NameTexture, PagTexture*>(COPYRIGHT, bump));
	texturas.insert(std::pair<NameTexture, PagTexture*>(NCOPYRIGHT, normals));



}

TextureLibrary* TextureLibrary::getInstance()
{
	if (!instance) {
		instance = new TextureLibrary();
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
