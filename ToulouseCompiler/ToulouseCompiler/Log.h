#pragma once
/**
* @file Log.h
* @Author Antonio Jesus Viso Sanchez
* @date 20/09/2018
* @brief Creacion de un log.txt
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>
#include <QPlainTextEdit>
using namespace std;
class Log{
private:
	static Log *instancia;

	ofstream log;
	string log_file;
	unsigned long int contador;
	unsigned long int errors;
	unsigned long int warnings;
	string name;

	QPlainTextEdit* OutPut;


	/**
	* @brief Construccion y creacion del log.txt
	*/
	Log();

public:
	
	void setOutPut(QPlainTextEdit* nuevo) {
		OutPut = nuevo;
	}



	/**
	* @brief permite acceder al log desde cualquier sitio
	*/
	static Log *getInstancia();


	~Log();
	


	/**
	* @brief Escribir lineas para el log
	* @param mensaje es un string con el dato a escribir
	*/
	void escribir(string mensaje);
		

	/**
		* @brief Escribir lineas para el log
		* @param mensaje es un string con el error a escribir
		*/
	void error(string mensaje);



	/**
		* @brief Escribir lineas para el log
		* @param mensaje es un string con el warning a escribir
		*/
	void warning(string mensaje);

	/**
		* @brief Escribir lineas para el log
		* @param mensaje es un string con el exito 
		*/
	void success(string mensaje);
	/**
		* @brief cierra el archivo
	*/
	void close();
};