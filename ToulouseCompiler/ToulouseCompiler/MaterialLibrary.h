#include "PagMaterial.h"
#include <map>
#include "PagEnumerations.h"

class MaterialLibrary
{

private:
		
	

	static  MaterialLibrary* instance;

	std::map< NameMaterial, PagMaterial*> materiales;

	MaterialLibrary();

public:


	static MaterialLibrary* getInstance();

	PagMaterial* find(NameMaterial name);


	
	~MaterialLibrary();
};

