#include "PointLight.h"



PointLight::PointLight(glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _lightPosition)
{
	Id = _Id;
	Is = _Is;
	lightPosition = _lightPosition;
}


void PointLight::aplicateShader(PagShaderProgram * shader, glm::mat4 view)
{
	glm::vec3 posicionN;
	


	posicionN = glm::vec3(view*(glm::vec4(lightPosition, 1.0f)));
	

	shader->setUniform("Id", Id);
	shader->setUniform("Is", Is);
	shader->setUniform("lightPosition", posicionN);
	
}

PointLight::~PointLight()
{
}
