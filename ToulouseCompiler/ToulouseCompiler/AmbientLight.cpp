#include "AmbientLight.h"



AmbientLight::AmbientLight(glm::vec3 _Ia)
{
	Ia =  _Ia;
}


void AmbientLight::aplicateShader(PagShaderProgram * shader, glm::mat4 view)
{
	shader->setUniform("Ia", Ia);
}

AmbientLight::~AmbientLight()
{
}
