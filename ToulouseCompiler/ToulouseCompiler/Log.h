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
#include <time.h>
#include <QPlainTextEdit>
#include <QTextCharFormat>
#include <QColor>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>

using namespace std;
class Log{
private:
	static Log *instancia;

	unsigned long int contador;
	unsigned long int errors;
	unsigned long int warnings;
	string name;

	QPlainTextEdit* OutPut;

	const std::map<QString, QColor> m_colours{ {"red", QColor(Qt::darkRed)},
										   {"green", QColor(Qt::darkGreen)},
										   {"black", QColor(Qt::black)},
										{"yellow", QColor(Qt::darkYellow)},
										{"cyan", QColor(Qt::darkCyan)}
	};

	/**
	* @brief Construccion y creacion del log.txt
	*/
	Log();

	void addToFile(string message);
	void appendText(const QString & text);
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
	
};