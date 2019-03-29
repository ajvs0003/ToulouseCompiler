#include "Log.h"

Log *Log::instancia = nullptr;

using namespace std;

//consigo la hora del sistema 
 std::string currentDateTime() {

	 char str[32]{};

	 time_t a = time(nullptr);

	 struct tm time_info;

	 // localtime_s, Microsoft version (returns zero on success, an error code on failure)
	 if (localtime_s(&time_info, &a) == 0) strftime(str, sizeof(str), "%H:%M:%S", &time_info);

	 return str;

}





Log::Log() {

	this->contador = 0;
	this->errors = 0;
	this->warnings = 0;
	this->log_file.assign("./SystemFiles/log.txt");
	/*this->log.open(log_file.c_str(), ios::app);*/
	this->log.open(log_file.c_str());
	// Escribimos una línea con el nombre del archivo
	this->log << "LogFile de la practica_(tiempo ejecucion "+ currentDateTime() +")." << endl;
	this->log << "---------------------------------- " << endl;
}

Log::~Log() {

}

Log *Log::getInstancia()
{
	if (!instancia) {
		instancia = new Log();
	}
	return instancia;
}

void Log::escribir(string mensaje)
{
	// Escribimos en el log
	this->log << currentDateTime()+" "<< mensaje << endl;
	

}
void Log::error(string mensaje){
	// Escribimos en el log
	cout << currentDateTime() + " [ERROR [ " << to_string(errors) + "]" << mensaje << endl;
	this->log << currentDateTime() + " [ERROR [ " << to_string(errors) + "]" << mensaje << endl;
	this->errors++;


}
void Log::warning(string mensaje){

	// Escribimos en el log
	cout << currentDateTime() + " [WARNING]" << mensaje << endl;
	this->log << currentDateTime() + " [WARNING]" << mensaje << endl;


}
void Log::success(string mensaje)
{
	// Escribimos en el log
	cout << currentDateTime() + " [SUCCESSFUL] " << mensaje << endl;
	this->log << currentDateTime() + " [SUCCESSFUL] " << mensaje << endl;
}
void Log::close()
{
	this->log << "--------------END LOG------------------- " << endl;
// Cerramos el archivo
	this->log.close();
	
}

