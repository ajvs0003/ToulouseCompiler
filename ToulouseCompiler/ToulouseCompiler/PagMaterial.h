#pragma once
#include "PagShaderProgram.h"
#include <glm.hpp>

class PagMaterial
{
private:
	glm::vec3 Ka;
	glm::vec3 Kd;        /* diffuse, 0 .. 1 */
	glm::vec3 Ks;        /* specular, 0 .. 1 */
	float shininess = 1.0f;    /* shininess, 1 .. 1000 */




	

public:

	

	PagMaterial(glm::vec3 _ka, glm::vec3 _kd, glm::vec3 _ks, float _shininess);

	/*PagMaterial(const PagMaterial &p) {
		this->Ka = p.Ka;
		this->Ks = p.Ks;
		this->Kd = p.Kd;
		this->shininess = p.shininess;
	}*/

	/**
	* @brief para establecer el color ambiental
	* @param nuevo , el color
	*/
	void setKa(glm::vec3 nuevo);

	/**
	* @brief para establecer el color difuso
	* @param nuevo , el color
	*/
	void setKd(glm::vec3 nuevo);

	/**
	* @brief para establecer el color especular
	* @param nuevo , el color
	*/
	void setKs(glm::vec3 nuevo);

	/**
	* @brief para establecer el brillo para los focos
	* @param nuevo , el color
	*/
	void setShininess(float nuevo);

	/**
		* @brief para devolver el color ambiental
		* @return glm::vec3 con las componentes del color
	*/
	glm::vec3 getKa();

	/**
		* @brief para devolver el color difuso
		* @return glm::vec3 con las componentes del color
	*/
	glm::vec3 getKd();

	/**
		* @brief para devolver el color especular
		* @return glm::vec3 con las componentes del color
	*/
	glm::vec3 getKs();

	/**
		* @brief para devolver el color
		* @return float el brillo para los focos
	*/
	float getShininess();


	/**
	* @brief se encarga de poner los uniform del material para el shader
	* @param shader, shader a usar
	*/
	void aplicateMaterial(PagShaderProgram &shader, bool textura);


	

	~PagMaterial();
};

