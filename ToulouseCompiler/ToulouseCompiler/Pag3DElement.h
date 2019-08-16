#pragma once
#include "MaterialLibrary.h"
#include "TextureLibrary.h"
class Pag3DElement
{
protected:
	glm::mat4 modelMatrix;
	
public:
	
	/**
		* @brief  Esta función gestiona el aplicar a la matriz de modelado el movimiento que quiera el user
		* @param  move vector para mover el objeto o grupo
	*/
	virtual void translate(glm::vec3 move) = 0;

	/**
		* @brief  Esta función gestiona el aplicar a la matriz de modelado la rotacion en el eje x que quiera el user
		* @param angle
	*/
	virtual void rotateX(float angle) = 0;

	/**
		* @brief  Esta función gestiona el aplicar a la matriz de modelado la rotacion en el eje y que quiera el user
		* @param angle el angulo
	*/
	virtual void rotateY(float angle) = 0;

	/**
		* @brief  Esta función gestiona el aplicar a la matriz de modelado la rotacion en el eje z que quiera el user
		* @param el angulo
	*/
	virtual void rotateZ(float angle) = 0;

	/**
		* @brief  Esta función gestiona el aplicar a la matriz de modelado el escalado que quiera el user
		* @param tam el escalado a aplicar
	*/
	virtual void scale(float tam) = 0;

	/**
		* @brief  Esta función gestiona decirle a los onjetos o al grupo que se pinte como puntos
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara

	*/
	virtual void DrawAsPoints(PagShaderProgram &shader,glm::mat4 model,glm::mat4 view,glm::mat4 projection) = 0;

	/**
		* @brief  Esta función gestiona decirle a los onjetos o al grupo que se pinte como lineas
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara
	*/
	virtual void DrawAsLines(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection) = 0;


	virtual void DrawAsTriangles(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection) = 0;


	/**
		* @brief  Esta función gestiona decirle a los onjetos o al grupo que se pinte como triangulos
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara
		* @param type , es apr ala utilizacion de unos uniforms caracteristicos para esta forma de pintar, si se usan luces o texturas
	*/
	virtual void DrawAsTrianglesWithLights(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection, bool textures) = 0;




	virtual void DrawFog(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection) = 0;
};


