#pragma once
#include "Metodos_especiales.h"
#include"Log.h"
#include "PagShaderProgram.h"
class PagLightSource
{
private:
	glm::vec3 Ia;
	glm::vec3 Id;
	glm::vec3 Is;       
	glm::vec3 lightPosition;  
	glm::vec3 lightLookAt;
	glm::vec3 lightDirection;
	float spotAngle;
	float cosGamma;

	int typeLight;
	vector<GLuint> subrutinas;//vector con los indices de las subrutinas del shader


	
public:

	//Constructor de la luz, se le pasa las subrutinas del shader desde el renderer
	PagLightSource(int _type);
	


	/**
		* @brief establece la intensidad ambiental
		* @param nuevo, la nueva Ia
	*/
	void setIa(glm::vec3 nuevo);

	/**
		* @brief establece la intensidad difuso
		* @param nuevo, la nueva Id
	*/
	void setId(glm::vec3 nuevo);

	/**
		* @brief establece la intensidad especular
		* @param nuevo, la nueva Is
	*/
	void setIs(glm::vec3 nuevo);

	/**
		* @brief establece que punto de interes ilumina la luz
		* @param nuevo, la posicion a usar
	*/
	void setLookAt(glm::vec3 nuevo);

	/**
		* @brief establece la posicion de la luz
		* @param nuevo, la posicion a usar
	*/ 
	void setLightPosition(glm::vec3 nuevo);

	
	/**
		* @brief establece el angulo para los focos
		* @param angle, el angulo a usar
	*/
	void setSpotAngle(float angle);

	/**
		* @brief Devuelve la intensidad ambiental de la luz
		* @return devuelve un vec3 con la intensidad de la luz
	*/
	glm::vec3 getIa();

	/**
		* @brief Devuelve la intensidad difusa de la luz
		* @return devuelve un vec3 con la intensidad de la luz
	*/
	glm::vec3 getId();

	/**
		* @brief Devuelve la intensidad especular de la luz
		* @return devuelve un vec3 con la intensidad de la luz
	*/
	glm::vec3 getIs();

	/**
		* @brief Devuelve la posicion de la luz
		* @return devuelve un vec3 con la posicion de la luz
	*/
	glm::vec3 getLightPosition();

	/**
		* @brief calcula a la direction que va la luz con el lookAt y su posicion
		* @return devuelve un vec3 del vector direccion
	*/
	glm::vec3 getLightDirection();

	/**
		* @brief Devuelve el angulo de las luces tipo spot
		* @return el dato 
	*/
	float getSpotAngle();

	/**
		* @brief devuelve el coseno necesario apra los focos
		* @return el dato
	*/
	float getCosGamma();


	/**
		* @brief se encarga de poner los uniform segun el tipo de luz
		* @param adsShader, shader de las luces
		* @param view, matriz de vision de la camara
	*/
	void aplicateLuz(PagShaderProgram &adsShader, glm::mat4 View, vector<GLuint> subru);

	~PagLightSource();
};

