#pragma once
#include "PagLightSource.h"



class SpotLight : public PagLightSource
{
private:
	glm::vec3 Id;
	glm::vec3 Is;
	glm::vec3 lightPosition;
	glm::vec3 lightLookAt;
	glm::vec3 lightDirection;
	float spotAngle;
	float cosGamma;


public:
	void aplicateShader(PagShaderProgram *shader, glm::mat4 view);

	SpotLight(glm::vec3 _Id,glm::vec3 _Is,glm::vec3 _lightPosition,glm::vec3 _lightLookAt,float _spotAngle);
	~SpotLight();
};

