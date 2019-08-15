#pragma once
#include "PagLightSource.h"


class AmbientLight : public PagLightSource
{
private:
	glm::vec3 Ia;
public:
	void aplicateShader(PagShaderProgram *shader, glm::mat4 view);
	AmbientLight(glm::vec3 _Ia);
	~AmbientLight();
};

