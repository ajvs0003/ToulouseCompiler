#pragma once
#include "PagShaderProgram.h"
class PagLightSource
{
public:
	virtual void aplicateShader(PagShaderProgram *shader, glm::mat4 view) = 0;
};


