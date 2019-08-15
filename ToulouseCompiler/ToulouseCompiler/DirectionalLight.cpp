#include "DirectionalLight.h"



void DirectionalLight::aplicateShader(PagShaderProgram * shader, glm::mat4 view)
{
	glm::vec3 posicionN;
	glm::vec3 directionN;


	posicionN = glm::vec3(view*(glm::vec4(lightPosition, 1.0f)));
	directionN = glm::vec3(view*(glm::vec4(lightDirection, 0.0f)));

	shader->setUniform("Id", Id);
	shader->setUniform("Is", Is);
	shader->setUniform("lightPosition", posicionN);
	shader->setUniform("lightDirection", directionN);
}

DirectionalLight::DirectionalLight(glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _lightPosition, glm::vec3 _lightLookAt)
{
	Id = _Id;
	Is = _Is;
	lightPosition = _lightPosition;
	lightLookAt = _lightLookAt;
	lightDirection = glm::normalize(lightLookAt - lightPosition);
}


DirectionalLight::~DirectionalLight()
{
}
