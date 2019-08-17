
#pragma once
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include "PagVAO.h"
#include "PagSubdivisionProfile.h"
#include "Pag3DElement.h"
#include "PagStructures.h"
#include <list>

struct part {
	//Data
	std::vector<PagPosNorm> PositionsAndNormals;//posiciones y normales
	std::vector<glm::vec2> TextureCoords;//texturas
	std::vector<glm::vec3> Tangents;//tangentes
	//indices
	std::vector<GLuint> Indices4PointCloud;//puntos
	std::vector<GLuint> Indices4Lines;//wireframe
	std::vector<GLuint> Indices4TrianglesMesh;//triangulos
};






class PagRevolutionObject:public Pag3DElement{

private:
	std::map <PagRevObjParts, PagMaterial* > material;

	PagTexture* textureTopFace;
	PagTexture* textureBotFace;
	PagTexture* textureBody;

	NameMaterial MatBody;
	NameMaterial MatTopFace;
	NameMaterial MatBotFace;

	PagVAO* VaoBody;
	PagVAO* VaoTopFace;
	PagVAO* VaoBotFace;

	
	

	PagSubdivisionProfile *Original;
	PagSubdivisionProfile *SubdividedProfile;
	vector<glm::vec2> NormalsOfProfile;//vector con las normales de los puntos del perfil 

	part TopFace;
	part Body;
	part BotFace;

	OpenGLFunctions* gl;

	/**
		* @brief  Esta Metodo calcula el vector de los dos puntos y la normal
		* @param a Es el punto 1
		* @param b Es el punto 2
		* @return devuelve la normal de esos dos puntos ya normalizada
	*/
	glm::vec3 CalculateNormalVector(glm::vec3 a, glm::vec3 b);

	/**
		* @brief  Esta Metodo rota el vector 90 grados y lo nromaliza
		* @param a Es el punto
		* @return devuelve la normal de ese
	*/
	glm::vec2 CalculateNormal(glm::vec2 a);


	/**
		* @brief  Esta crea las vi de las texturas del cuerpo en la generatriz
		* @return devuelve un vectoor de flotantes con las coordenadas vi para su posterior revolucion
	*/
	vector<float> BodyTextures();

	void createGeometryBody(int slices,double delta);
	void createGeometryTopFace(int slices,double delta);
	void createGeometryBotFace(int slices,double delta);



	/**
		* @brief  Esta Metodo se encarga de la revolucion segun la parte que le pasas
		* @param part La parte a revolucionar
		* @param slices El numero de slices para la revolucion
	*/
	void Revolution(PagRevObjParts part,unsigned int slices);


	/**
		* @brief  Esta Metodo calcula las normales y se las asigna a el vector que se encarga de ello
	*/
	void NormalsProfile();





public:
	/**
		* @brief  para establecer el tipo de material para body
		* @param NameMaterial nuevo, el material a buscar en la biblioteca de materiales
	*/
	void setMatBody(NameMaterial nuevo);

	/**
		* @brief  para establecer el tipo de material para cara arriba
		* @param NameMaterial nuevo, el material a buscar en la biblioteca de materiales
	*/
	void setMatTopFace(NameMaterial nuevo);

	/**
		* @brief  para establecer el tipo de material para cara abajo
		* @param NameMaterial nuevo, el material a buscar en la biblioteca de materiales
	*/
	void setMatBotFace(NameMaterial nuevo);

	/**
		* @brief  para establecer el tipo de textura ya sea normal o para bumpMapping(No funcional) para body
		* @param NameTexture nuevo, la textura a buscar en la biblioteca de texturas
		* @param string type para indicar el tipo (normal,bump,...)
	*/
	void setTexBody(NameTexture nuevo);

	/**
		* @brief  para establecer el tipo de textura ya sea normal o para bumpMapping(No funcional) para cara arriba
		* @param NameTexture nuevo, la textura a buscar en la biblioteca de texturas
		* @param string type para indicar el tipo (normal,bump,...)
	*/
	void setTexTopFace(NameTexture nuevo);

	/**
		* @brief  para establecer el tipo de textura ya sea normal o para bumpMapping(No funcional) para cara abajo
		* @param NameTexture nuevo, la textura a buscar en la biblioteca de texturas
		* @param string type para indicar el tipo (normal,bump,...)
	*/
	void setTexBotFace(NameTexture nuevo);



	/**
		* @brief  para devolver la matriz de modelado
	*/
	glm::mat4 getModelMatrix()
	{
		return modelMatrix;
	}

	

	PagRevolutionObject(OpenGLFunctions *_gl,std::vector<glm::vec2> points, unsigned int subdivisions, unsigned int slices);

	~PagRevolutionObject();

	/**
		* @brief  Esta Metodo es para gestion de errores en la subdivision
	*/
	void CheckSubdivide(int times) {
			int n = ((Original->profile.size() - 2) * 2) + 3;

			if (times == 1)
				Log::getInstancia()->escribir("Expectated  " + to_string(n));
			else 
				Log::getInstancia()->escribir("Expectated  " + to_string((n * 2) - 1));

			Log::getInstancia()->escribir("Total " + to_string(SubdividedProfile->profile.size()));

			for(unsigned int i=0;i< SubdividedProfile->profile.size();i++)
				Log::getInstancia()->escribir("Control Point " + to_string(SubdividedProfile->profile.at(i).x)+","+to_string(SubdividedProfile->profile.at(i).y));
			

	}



	/**
		* @brief  Esta función se encarga de ver si el perfil es adecuado
		* @return  true si lo es y false si no
	*/
	bool isValid();

	/**
		* @brief  Esta función se encarga de decir si tiene cuerpo,cara arriba,cara abajo
		* @param part Es la parte a comprobar
		* @return true si cumple que posee esa parte
	*/
	bool has(PagRevObjParts part);


	/**
		* @brief  Esta función escribe un txt, las normales y las posiciones para que las lea meshlab
		* @brief (Anotacion, esta modificado para que no se sobreescriba y se pueda escribir todo el modelo,ademas si pasas test escribe el perfil)
		* @param part Es la parte que se escribira em el txt
		
	*/
	void WriteTxt(PagRevObjParts part);




	/**
		* @brief Devuelve el número de vértices de la parte del objeto que se pasa como argumento
		* @param part Es la parte de la cual se devuelve el vector
		* @return devuelve un int con el numero total de puntos
	*/
	unsigned int getNPoints(PagRevObjParts part);

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
	* @brief  Esta función gestiona la aplicacion de un material para este tipo de objeto
	* @param shader pues el shader a usar
	* @param material pues el shader a usar
	*/

	void Aplicate(PagShaderProgram &shader,  PagRevObjParts part,bool textures);

	/**
		* @brief  Esta función gestiona decirle a los onjetos o al grupo que se pinte como puntos
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara

	*/
	void DrawAsPoints(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection) ;


	/**
		* @brief  Esta función gestiona decirle a los onjetos o al grupo que se pinte como lineas
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara
	*/
	void DrawAsLines(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection)  ;

	void DrawAsTriangles(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection);

	/**
		* @brief  Esta función gestiona decirle a los onjetos o al grupo que se pinte como triangulos
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara
		* @param type , es apr ala utilizacion de unos uniforms caracteristicos para esta forma de pintar, si se usan luces o no
	*/
	void DrawAsTrianglesWithLights(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection, bool textures);



	/**
		* @brief  Esta función gestiona decirle a los onjetos o al grupo que pinte el fog
		* @param shader shader a usar
		* @param model , matriz acumulada
		* @param view , matriz vision de la camara
		* @param projection , matriz de proyeccion de la camara
	*/
	void DrawFog(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection);
	



};

