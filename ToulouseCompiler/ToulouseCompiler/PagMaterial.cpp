#include "PagMaterial.h"





void PagMaterial::setKa(glm::vec3 nuevo) {
	Ka = nuevo;
}


void PagMaterial::setKd(glm::vec3 nuevo) {
	Kd = nuevo;
}
void PagMaterial::setKs(glm::vec3 nuevo) {
	Ks = nuevo;
}
void PagMaterial::setShininess(float nuevo) {
	shininess = nuevo;
}

glm::vec3 PagMaterial::getKa() {
	return Ka;
}

glm::vec3 PagMaterial::getKd() {
	return Kd;
}

glm::vec3 PagMaterial::getKs() {
	return Ks;
}

float PagMaterial::getShininess() {
	return shininess;
}

void PagMaterial::aplicateMaterial(PagShaderProgram &shader,bool textura)
{
	if (!textura) {
		shader.setUniform("Ka", getKa());
		shader.setUniform("Kd", getKd());
		shader.setUniform("Ks", getKs());
		shader.setUniform("shininess", getShininess());
	}
	else {
		shader.setUniform("Ks", getKs());
		shader.setUniform("shininess", getShininess());
	}




}


PagMaterial::PagMaterial(glm::vec3 _ka,glm::vec3 _kd, glm::vec3 _ks, float _shininess) :
	Ka(_ka),Ks(_ks), Kd(_kd), shininess(_shininess) {};


PagMaterial::~PagMaterial()
{
}

