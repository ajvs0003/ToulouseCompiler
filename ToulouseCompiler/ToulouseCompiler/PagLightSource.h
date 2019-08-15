#pragma once
#include "Metodos_especiales.h"
#include"Log.h"
#include "PagShaderProgram.h"
class PagLightSource
{
public:
	virtual void aplicateShader(PagShaderProgram *shader, glm::mat4 view) = 0;
};


