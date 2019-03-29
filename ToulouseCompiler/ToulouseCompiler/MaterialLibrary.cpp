#include "MaterialLibrary.h"

MaterialLibrary * MaterialLibrary::instance = nullptr;

MaterialLibrary::MaterialLibrary()
{

	PagMaterial* materialPeon;
	materialPeon = new PagMaterial(glm::vec3(1.f, 1.f, 1.f), glm::vec3(255.0 / 255.0, 204 / 255.0, 153.0 / 255.0), glm::vec3(0.54, 0.54, 0.54), 36.0);

	PagMaterial* materialMesa;
	materialMesa = new PagMaterial(glm::vec3(1.f, 1.f, 1.f), glm::vec3(102.0 / 255.0, 51.0 / 255.0, 0.0 / 255.0), glm::vec3(0.54, 0.54, 0.54), 20.0);

	PagMaterial* materialPared;
	materialPared = new PagMaterial(glm::vec3(1.f, 1.f, 1.f), glm::vec3(255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0), glm::vec3(0.54, 0.54, 0.54), 20.0);


	PagMaterial* materialCorona;
	materialCorona = new PagMaterial(glm::vec3(1.f, 1.f, 1.f), glm::vec3(0.0 / 255.0, 0.0 / 255.0, 102.0 / 255.0), glm::vec3(0.54, 0.54, 0.54), 36.0);

	PagMaterial* glass;
	glass = new PagMaterial(glm::vec3(1.f, 1.f, 1.f), glm::vec3(153 / 255.0, 217.0 / 243.0, 234 / 255.0), glm::vec3(153 / 255.0, 217.0 / 243.0, 234 / 255.0), 40.0);



	std::pair<NameMaterial, PagMaterial*> uno(WOOD_LIGHT, materialPeon);
	

	std::pair<NameMaterial, PagMaterial*> dos(WOOD_DARK, materialMesa);
	

	std::pair<NameMaterial, PagMaterial*> tres(BLUE_DARK, materialCorona);

	std::pair<NameMaterial, PagMaterial*> cuatro(MATERIAL_GLASS, glass);

	std::pair<NameMaterial, PagMaterial*> cinco(MATERIAL_WALL, materialPared);

	materiales.insert(uno);
	materiales.insert(dos);
	materiales.insert(tres);
	materiales.insert(cuatro);
	materiales.insert(cinco);






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
