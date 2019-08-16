#include "MaterialLibrary.h"

MaterialLibrary * MaterialLibrary::instance = nullptr;

MaterialLibrary::MaterialLibrary()
{



	PagMaterial* materialPeon;
	materialPeon = new PagMaterial(glm::vec3(1.f, 1.f, 1.f), glm::vec3(255.0 / 255.0, 204 / 255.0, 153.0 / 255.0), glm::vec3(0.54, 0.54, 0.54), 36.0);

	



	std::pair<NameMaterial, PagMaterial*> uno(WOOD_LIGHT, materialPeon);
	

	

	materiales.insert(uno);
	





}


 MaterialLibrary* MaterialLibrary::getInstance()
{
	if (!instance) {
		instance = new MaterialLibrary();
	}
	

	return instance;



	
}

PagMaterial* MaterialLibrary::find(NameMaterial name)
{
	std::map<NameMaterial, PagMaterial*>::iterator it;
	it = materiales.find(name);
	if(it != materiales.end())
		return it->second;
	else return nullptr;
	
	
}

MaterialLibrary::~MaterialLibrary()
{
	/*delete instance;*/
}
