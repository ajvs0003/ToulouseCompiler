#pragma once
#include "Metodos_especiales.h"
#include"Log.h"
#include <glm.hpp>

class PagCamera
{
private:
	float FoV;
	glm::vec3 cameraPos;
	glm::vec3 cameralookAt;
	glm::vec3 cameraUp;
	glm::vec3 n;
	glm::vec3 u;
	glm::vec3 v;

	float angleOrbitX = 0;
	void updateCameraAxis();



	glm::mat4 projectionMatrix;
public:
	/**
		* @brief Constructor de la camara
		* @param position posicion de la camara
		* @param position2 posicion lookAt que se le quiere poner a la camara
		* @param fov angulo de apertura de la camara
	*/
	PagCamera( glm::vec3 position, glm::vec3 position2, float fov);
	
	~PagCamera();

	/**
		* @brief Operador asignacion de la camara
		* @param other camara a copiar
		* @return un tipo PagCamera
	*/
	PagCamera operator=(const PagCamera& other);

	/**
		* @brief devuelve la posicion de la camara
		* @return devuelve un glm::vec3 con  la posicion
	*/
	glm::vec3 Position() const;

	/**
		* @brief devuelve la posicion del punto hacia donde mira la camara
		* @return devuelve un glm::vec3 con  el punto hacia donde mira la camara
	*/
	glm::vec3 Forward() const;

	/**
		* @brief devuelve el vector up de la camara
		* @return devuelve un glm::vec3 con el vector up de la camara
	*/
	glm::vec3 Up() const;

	/**
		* @brief Establece la posicion de la camara en el vector que se le pase
		* @param nuev la nueva posicion de la camara
	*/
	void setPosition(glm::vec3 nuev);

	/**
		* @brief Establece el lookAt de la camara en el vector que se le pase
		* @param position posicion lookAt que se le quiere poner a la camara
	*/
	void SetCameraViewDirection(glm::vec3& position);

	/**
		* @brief metodos para el movimiento truck de la camara
	*/
	void moveFoward();
	void moveBackward();



	/**
		* @brief metodos para el movimiento dolly de la camara
	*/
	void moveLeft();
	void moveRight();

	/**
		* @brief metodo para el movimiento boom de la camara
	*/
	void moveUp();

	/**
		* @brief metodo para el movimiento crane de la camara
	*/
	void moveDown();

	/**
		* @brief metododo para el orbit girando por encima
		* @param cantidadX cantidad de movimiento para el Pan
		* @param cantidadY cantidad de movimiento para el Tilt
	*/
	void tiltAndPan(float cantidadX, float cantidadY);
	

	/**
		* @brief metodo para el orbit girando por encima
	*/
	void orbitX(float cantidad);

	/**
		* @brief metodo para el orbit girar alrededor
	*/
	void orbitY(float cantidad);

	/**
		* @brief devuelve la matriz de proyeccion y ademas calcula el fovY
	*/
	void zoom(float factor);


	/**
		* @brief devuelve la matriz de proyeccion y ademas calcula el fovY
		* @param _width ancho de la ventana
		* @param _height alto de la ventana
		* @return devuelve un glm::mat4 con los datos de la matriz de proyeccion
	*/
	glm::mat4 getWorldToProjecMatrix(float _width, float _height);


	/**
		* @brief devuelve la matriz de vision
		* @return devuelve un glm::mat4 con los datos de la matriz de vision
	*/
	glm::mat4 getWorldToViewMatrix() const;



	

};

