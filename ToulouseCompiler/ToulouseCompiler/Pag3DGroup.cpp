#include "Pag3DGroup.h"
#include <gtc\matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx\euler_angles.hpp>

Pag3DGroup::Pag3DGroup()
{
	modelMatrix = glm::mat4(1);
}


Pag3DGroup::~Pag3DGroup()
{
}



void Pag3DGroup::insertObject(Pag3DElement* nuevo)
{

	objetos.push_back(nuevo);
}



void Pag3DGroup::DrawAsPoints(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	for (unsigned  int i = 0; i < objetos.size(); i++) {
		objetos.at(i)->DrawAsPoints(shader, this->modelMatrix*model, view,
			projection);
	}
	


}

void Pag3DGroup::DrawAsLines(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	for (unsigned int i = 0; i < objetos.size(); i++) {
		objetos.at(i)->DrawAsLines(shader, this->modelMatrix*model, view,
			projection);
	}




}

void Pag3DGroup::DrawAsTriangles(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection, string type)
{
	for (unsigned int i = 0; i < objetos.size(); i++) {
		objetos.at(i)->DrawAsTriangles(shader, modelMatrix*model, view,
			projection,type);
		
	}
}

void Pag3DGroup::DrawFog(PagShaderProgram & shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	for (unsigned int i = 0; i < objetos.size(); i++) {
		objetos.at(i)->DrawFog(shader, modelMatrix*model, view,
			projection);

	}
}





void Pag3DGroup::translate(glm::vec3 move)
{
	modelMatrix = glm::translate(this->modelMatrix, move);
}



void Pag3DGroup::rotateX(float angle)
{
	modelMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), glm::vec3(1.f, 0.f, 0.f));


}

void Pag3DGroup::rotateY(float angle)
{

	modelMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), glm::vec3(0.f, 1.f, 0.f));
}

void Pag3DGroup::rotateZ(float angle)
{
	modelMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), glm::vec3(0.f, 0.f, 1.f));

}

void Pag3DGroup::scale(float tam)
{
	modelMatrix = glm::scale(this->modelMatrix, glm::vec3(tam));
}









//Pag3DElement::Pag3DElement(string name, int subdivisions, int slices)
//{
//	glm::mat4 model(1.f);
//	std::vector <glm::vec2> dataTxt;
//
//	modelMatrix = model;
//	dataTxt = Metodos_especiales::lecturaFichero(dataTxt, "./Objects/" + name + ".txt");
//	geometria = new PagRevolutionObject(dataTxt, subdivisions, slices);
//
//}
//
//Pag3DElement::Pag3DElement(string name)
//{
//	OBJ model(name + ".obj", "");
//	//Pendiente de acabar
//
//}