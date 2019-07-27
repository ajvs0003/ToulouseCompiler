#include "PagLightSource.h"
#include <gtc\matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx\euler_angles.hpp>


PagLightSource::PagLightSource(int _type)
{
	//typeLuz = 0 -> ambiental
	//typeLuz = 1 -> puntual
	//typeLuz = 2 -> direccional
	//typeLuz = 3 -> spot 

	typeLight = _type;

}

void PagLightSource::setLookAt(glm::vec3 nuevo)
{
	lightLookAt = nuevo;
}


PagLightSource::~PagLightSource()
{
}


void PagLightSource::setIa(glm::vec3 nuevo)
{
	Id = nuevo;
}


void PagLightSource::setId(glm::vec3 nuevo)
{
	Id = nuevo;
}

void PagLightSource::setIs(glm::vec3 nuevo)
{
	Is = nuevo;
}

void PagLightSource::setLightPosition(glm::vec3 nuevo)
{
	lightPosition = nuevo;
}

//void PagLightSource::setLightDirection(glm::vec3 nuevo)
//{
//	lightDirection = nuevo;
//}

void PagLightSource::setSpotAngle(float angle)
{
	spotAngle = angle;
	cosGamma = glm::cos(glm::radians(spotAngle));
}

glm::vec3 PagLightSource::getIa()
{
	return Id;
}

glm::vec3 PagLightSource::getId()
{
	return Id;
}

glm::vec3 PagLightSource::getIs()
{
	return Is;
}

glm::vec3 PagLightSource::getLightPosition()
{
	return lightPosition;
}

glm::vec3 PagLightSource::getLightDirection()
{
	return glm::normalize(lightLookAt-lightPosition);
}

float PagLightSource::getSpotAngle()
{
	return spotAngle;
}

float PagLightSource::getCosGamma()
{
	return cosGamma;
}

void PagLightSource::aplicateLuz(PagShaderProgram &adsShader,glm::mat4 View, vector<GLuint> subru)
{
	
	subrutinas = subru;


	adsShader.setUniform("c1",0.5f);
	adsShader.setUniform("c2",0.f);
	adsShader.setUniform("c3",0.f);


	glm::vec3 posicionN;
	glm::vec3 directionN;
	
	switch (typeLight) {

	case 0:
		/*adsShader.activateSubrutines(GL_FRAGMENT_SHADER, 1, &subrutinas.at(typeLight));*/
		
		adsShader.setUniform("Ia", getIa());

		
	break;

	case 1:
		
		posicionN = glm::vec3(View*(glm::vec4(lightPosition, 1.0f)));

		/*adsShader.activateSubrutines(GL_FRAGMENT_SHADER, 1, &subrutinas.at(typeLight));*/
		adsShader.setUniform("Id", getId());
		adsShader.setUniform("Is", getIs());
		adsShader.setUniform("lightPosition", posicionN);
		
		
	break;

	case 2:
		
		directionN = glm::vec3(View*(glm::vec4(getLightDirection(), 0.0f)));
		
		/*adsShader.activateSubrutines(GL_FRAGMENT_SHADER, 1, &subrutinas.at(typeLight));*/
		
		adsShader.setUniform("Id", getId());
		adsShader.setUniform("Is", getIs());
		adsShader.setUniform("lightDirection", directionN);
		
		
		break;

	case 3:
		
		posicionN = glm::vec3(View*(glm::vec4(lightPosition, 1.0f)));
		directionN = glm::vec3(View*(glm::vec4(getLightDirection(), 0.0f)));
		
		/*adsShader.activateSubrutines(GL_FRAGMENT_SHADER, 1, &subrutinas.at(typeLight));*/
		
		adsShader.setUniform("Id", getId());
		adsShader.setUniform("Is", getIs());
		adsShader.setUniform("lightPosition", posicionN);
		adsShader.setUniform("lightDirection", directionN);
		adsShader.setUniform("cosGamma", this->getCosGamma());
		
		
		break;
	}





}
