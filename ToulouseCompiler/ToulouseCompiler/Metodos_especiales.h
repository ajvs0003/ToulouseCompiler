#pragma once
#include <string>
#include <vector>
#include "PagRevolutionObject.h"
#include "Log.h"
#include <qstring.h>
#include <qfile.h>
#include <qtextstream.h>


using namespace std;


namespace Metodos_especiales {


	std::vector <glm::vec2>  lecturaFichero(std::vector <glm::vec2> test, std::string fichero);//Para leer el fichero de puntos

	//Para la creacion de semicirculos
	//glm::vec2 a(1,12);
	//glm::vec2 b(1.5,1.5);
	//test = Metodos_especiales::semiCircunferencia(b,a);
	std::vector <glm::vec2> semiCircunferencia(glm::vec2 punto, glm::vec2 control);//Para crear semicirculos en el origen y trasladarlos al sitio deseado
};

