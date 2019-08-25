#include "Metodos_especiales.h"

//Para leer los puntos del perfil desde un txt ej:(0,1)
std::vector <glm::vec2>  Metodos_especiales::lecturaFichero(std::vector <glm::vec2> test, std::string fichero) {
	
	/*fstream  file;*/
	string  tipo;
	string linea;
	glm::vec2 punto;
	int cont;

	QFile inputFile(fichero.c_str());
	if (inputFile.open(QIODevice::ReadOnly))
	{

		/*Log::getInstancia()->success("Opening file ...");*/
		QTextStream in(&inputFile);
		while (!in.atEnd())
		{
			QString line = in.readLine();
			
			std::string text = line.toUtf8().constData();
			std::stringstream   stream(text);
			std::string         valor;
			cont = 0;

			while (std::getline(stream, valor, ','))
			{
				if (cont == 0) {
					punto.x = stof(valor.c_str());
					cont++;
				}
				else {
					punto.y = stof(valor.c_str());
				}

			}
			test.push_back(punto);




		}
		inputFile.close();
	}
	else {
		Log::getInstancia()->success("Can't open file: "+ fichero);
	}

	//MODE C++
	/*file.open(fichero.c_str());
	if (file.is_open()) {
		Log::getInstancia()->success("Leyendo fichero" + fichero);
		while (!file.eof()) {
			std::string linea;
			while (getline(file, linea))
			{
				std::stringstream   stream(linea);
				std::string         valor;
				cont = 0;

				while (std::getline(stream, valor, ','))
				{
					if (cont == 0) {
						punto.x = stof(valor.c_str());
						cont++;
					}
					else {
						punto.y = stof(valor.c_str());
					}

				}
				test.push_back(punto);

			}
		}


	}
	else {
		
		Log::getInstancia()->error("Error leyendo fichero" + fichero);
	}*/
	return test;
}




std::vector <glm::vec2> Metodos_especiales::semiCircunferencia(glm::vec2 punto, glm::vec2 control) {
	double delta = 190 / 16;//Para crear circulos para el perfil
	delta = glm::radians(delta);

	std::vector <glm::vec2> nuevo,test;

	for (int s = 0; s <= 16; s++) {
		double a = s * delta;

		glm::vec2 p((punto.x)*glm::sin(a), (punto.y)*glm::cos(a));

		test.push_back(p);
	}

	glm::vec2 a;
	glm::vec2 t;
	for (unsigned int i = 0; i < test.size(); i++) {

		a = test.at(i);
		t = { control.x + a.x,control.y + a.y };
		nuevo.push_back(t);

	}





	return nuevo;
}


