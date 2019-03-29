#pragma once
//#include "PagMaterial.h"
#/*include "Pag3DElement.h"*/
//#include "MaterialLibrary.h"
#include "PagRevolutionObject.h"
#include "PagPlane.h"
class Pag3DGroup:public Pag3DElement
{
private:

	vector<Pag3DElement*> objetos;


public:
	Pag3DGroup();
	~Pag3DGroup();


	void insertObject(Pag3DElement* nuevo);


	glm::mat4 getModelMatrix() {return this->modelMatrix;}

	/**
		* @brief  Esta función gestiona el aplicar a la matriz de modelado el movimiento que quiera el user
		* @param  move vector para mover el objeto o grupo
	*/
	void translate(glm::vec3 move);

	/**
		* @brief  Esta función gestiona el aplicar a la matriz de modelado la rotacion en el eje x que quiera el user
		* @param angle
	*/
	void rotateX(float angle);

	/**
		* @brief  Esta función gestiona el aplicar a la matriz de modelado la rotacion en el eje y que quiera el user
		* @param angle el angulo
	*/
	void rotateY(float angle);

	/**
		* @brief  Esta función gestiona el aplicar a la matriz de modelado la rotacion en el eje z que quiera el user
		* @param el angulo
	*/
	void rotateZ(float angle);

	/**
		* @brief  Esta función gestiona el aplicar a la matriz de modelado el escalado que quiera el user
		* @param tam el escalado a aplicar
	*/
	void scale(float tam);

	/**
		* @brief  Esta función gestiona decirle a los onjetos o al grupo que se pinte como puntos
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara

	*/
	void DrawAsPoints(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection);

	/**
		* @brief  Esta función gestiona decirle a los onjetos o al grupo que se pinte como lineas
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara
	*/
	void DrawAsLines(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection);

	/**
		* @brief  Esta función gestiona decirle a los onjetos o al grupo que se pinte como triangulos
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara
		* @param type , es apr ala utilizacion de unos uniforms caracteristicos para esta forma de pintar, si se usan luces o no
	*/
	void DrawAsTriangles(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection, string type);

	

	
	void DrawFog(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection);


	
};

