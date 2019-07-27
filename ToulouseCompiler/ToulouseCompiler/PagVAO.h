#pragma once
#include <QtGui/QOpenGLFunctions>
#include <vector>
#include "PagEnumerations.h"
#include "PagStructures.h"
#include "OpenGLFunctions.h"
#include "Log.h"

class PagVAO : protected OpenGLFunctions
{
private:
	GLuint vao;
	GLuint ID_vbo0;
	GLuint  ID_vbo1;
	GLuint  ID_vbo2;
	GLuint ID_ibo0;
	GLuint ID_ibo1;
	GLuint ID_ibo2;

	OpenGLFunctions* gl; 

public:
	std::vector<PagPosNorm> PositionsAndNormals;//posiciones y normales
	std::vector<glm::vec2> TextureCoords;//texturas
	std::vector<glm::vec3> Tangents;//tangentes
	std::vector<GLuint> Indices4PointCloud;//puntos
	std::vector<GLuint> Indices4Lines;//wireframe
	std::vector<GLuint> Indices4TrianglesMesh;//triangulos
	

	/**
		* @brief Para la inicializacion de los vbo e ibo
	*/
	void iniciar(std::vector<PagPosNorm> PositionsAndNormals, std::vector<glm::vec2>  TextureCoords, std::vector<glm::vec3> Tangents,
		std::vector<GLuint> Indices4PointCloud, std::vector<GLuint> Indices4Lines, std::vector<GLuint> Indices4TrianglesMesh);

	//TEMPORAL
	GLuint getVao() {
		return vao;
	}



	/**
		* @brief solo se crea el indice del vao a usar
		* @ param OpenGLFunctions
	*/
	PagVAO();

	PagVAO(OpenGLFunctions *_gl);
	~PagVAO();
	
	/**
		* @brief usa puntos para pintar el objeto
	*/
	void drawAsPoints();

	/**
		* @brief se usan lineas para pintar el objeto
	*/
	void drawAsLines();

	/**
		* @brief para pintar tapas con triangulos
	*/
	void drawAsTriangles();

	/**
		* @brief para pintar triangulos en strip
	*/
	void drawAsTriangles2();
};

