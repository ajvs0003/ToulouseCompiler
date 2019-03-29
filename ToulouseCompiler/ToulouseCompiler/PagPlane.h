#pragma once
#include "PagVAO.h"
#include "Pag3DElement.h"
#include <vector>
#include<map>
struct Part {
	//Data
	std::vector<PagPosNorm> PositionsAndNormals;//posiciones y normales
	std::vector<glm::vec2> TextureCoords;//texturas
	std::vector<glm::vec3> Tangents;//tangentes
	//indices
	std::vector<GLuint> Indices4PointCloud;//puntos
	std::vector<GLuint> Indices4Lines;//wireframe
	std::vector<GLuint> Indices4TrianglesMesh;//triangulos
};

class PagPlane:public Pag3DElement
{
private:
	 PagMaterial* material;
	 std::map<string, PagTexture*> Maptextures;

	NameMaterial nameMaterial;
	NameTexture nameTex;

	unsigned int PlaneTam; 
	unsigned int PlaneTam2;
	unsigned int PlaneDivisiones;

	Part planeData;
	PagVAO* VaoPlane;




public:
	//el constructor que se encarga de todo para el plano
	PagPlane(unsigned int tam, unsigned int tam2, unsigned int divisiones);
	~PagPlane();

	/**
		* @brief  Esta funci�n gestiona el aplicar a la matriz de modelado el movimiento que quiera el user
		* @param  move vector para mover el objeto o grupo
	*/
	void translate(glm::vec3 move);

	/**
		* @brief  Esta funci�n gestiona el aplicar a la matriz de modelado la rotacion en el eje x que quiera el user
		* @param angle
	*/
	void rotateX(float angle);

	/**
		* @brief  Esta funci�n gestiona el aplicar a la matriz de modelado la rotacion en el eje y que quiera el user
		* @param angle el angulo
	*/
	void rotateY(float angle);

	/**
		* @brief  Esta funci�n gestiona el aplicar a la matriz de modelado la rotacion en el eje z que quiera el user
		* @param el angulo
	*/
	void rotateZ(float angle);

	/**
		* @brief  Esta funci�n gestiona el aplicar a la matriz de modelado el escalado que quiera el user
		* @param tam el escalado a aplicar
	*/
	void scale(float tam);


	/**
		* @brief  para establecer el tipo de material 
		* @param NameMaterial nuevo, el material a buscar en la biblioteca de materiales
	*/
	void setMat(NameMaterial nuevo);


	/**
	* @brief  para establecer el tipo de textura ya sea normal o para bumpMapping(No funcional) 
	* @param NameTexture nuevo, la textura a buscar en la biblioteca de texturas
	* @param string type para indicar el tipo (normal,bump,...)
*/
	void setTex(NameTexture nuevo, std::string type);

	/**
		* @brief  Esta funci�n gestiona la aplicacion de un material para este tipo de objeto
		* @param shader pues el shader a usar
		*/

	void Aplicate(PagShaderProgram &shader,bool textures);

	/**
		* @brief  Esta funci�n gestiona decirle a los onjetos o al grupo que se pinte como puntos
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara

	*/
	void DrawAsPoints(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection);


	/**
		* @brief  Esta funci�n gestiona decirle a los onjetos o al grupo que se pinte como lineas
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara
	*/
	void DrawAsLines(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection);

	/**
		* @brief  Esta funci�n gestiona decirle a los onjetos o al grupo que se pinte como triangulos
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara
		* @param type , es apr ala utilizacion de unos uniforms caracteristicos para esta forma de pintar, si se usan luces o no
	*/
	void DrawAsTriangles(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection, string type);


	/**
	* @brief  Esta funci�n gestiona decirle a los onjetos o al grupo que pinte el fog
	* @param shader shader a usar
	* @param model , matriz acumulada
	* @param view , matriz vision de la camara
	* @param projection , matriz de proyeccion de la camara
*/
	void DrawFog(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection);
};

