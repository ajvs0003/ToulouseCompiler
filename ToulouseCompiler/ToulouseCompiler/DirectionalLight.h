#pragma once
#include "PagLightSource.h"
class DirectionalLight :
	public PagLightSource
{
private :
	glm::vec3 Id;
	glm::vec3 Is;
	glm::vec3 lightPosition;
	glm::vec3 lightLookAt;
	glm::vec3 lightDirection;



public:
	void aplicateShader(PagShaderProgram *shader, glm::mat4 view);
	DirectionalLight(glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _lightPosition, glm::vec3 _lightLookAt);
	~DirectionalLight();
};

