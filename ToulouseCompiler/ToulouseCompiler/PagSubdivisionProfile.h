#pragma once
#include <glm.hpp>
#include "Log.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "PagEnumerations.h"
#include "Log.h"



class PagSubdivisionProfile{

private:
	std::vector <glm::vec2> Pure;
	

	/**
		* @brief  Esta función se encarga de tratar con el caso de un perfil de una linea
		* @param  points es el vector de puntos 2D
		* @return true si no descarta puntos y elige el tipo,false si uno de los puntos no es adecuado
	*/
	bool line(std::vector<glm::vec2> points);




public:
	bool topFace;
	bool bottomFace;
	bool Body;

	std::vector <glm::vec2> profile;//Vector con el perfil en si

	/**
		* @brief  Esta función se encarga del chequeo del perfil de subdivision
		* @param  points es el vector de puntos 2D
	*/
	bool CheckPoints();

	/**
		* @brief  Esta función se procesa el array para ver puntos erroneos, y construye el perfil
		* @param  points es el conjuntos de putos pasados por el usuario
		
	*/
	PagSubdivisionProfile(std::vector <glm::vec2> points);


	/**
		* @brief  Constructor copia
		* @param  &p El pagSubdivision
	*/
	PagSubdivisionProfile(const PagSubdivisionProfile &p) {
		this->profile = p.profile;
		this->topFace = p.topFace;
		this->bottomFace = p.bottomFace;
		this->Body = p.Body;
	}


	~PagSubdivisionProfile();



	/**
		* @brief  Operador asignacion
		* @param  &p El pagSubdivision 
		* @return devuelve el perfil subdividido
	*/
	PagSubdivisionProfile& operator = (const PagSubdivisionProfile &p)
	{
		if (this != &p) { //Comprueba que no se esté intentanod igualar un objeto a sí mismo
			if (p.profile != this->profile) this->profile = p.profile;
			if (p.topFace != this->topFace) this->topFace = p.topFace;
			if (p.bottomFace != this->bottomFace) this->bottomFace = p.bottomFace;
			if (p.Body != this->Body) this->Body = p.Body;
		}
		return *this;
	}


	/**
		* @brief  Esta función se encarga de los calculos de la subdivision del perfil
		* @param   times el numero de veces que se subdivide
		* @return devuelve el perfil subdividido
	*/
	PagSubdivisionProfile subdivide(unsigned int times);



};

