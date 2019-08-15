#pragma once
#include "PagLightSource.h"
class PointLight :
	public PagLightSource
{
private :
	glm::vec3 Id;
	glm::vec3 Is;
	glm::vec3 lightPosition;
public:
	void aplicateShader(PagShaderProgram *shader, glm::mat4 view);
	PointLight(glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _lightPosition);
	~PointLight();
};

