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
void Log::appendText(const QString & text) {
	QString html{ text };
	int j = 0;
	bool start = true;
	QString textColor;

	while ((j = html.indexOf(QChar('\033'), j)) != -1) {
		html.remove(j, 1);
		QColor color;
		for (auto & pair : m_colours) {
			if (html.mid(j).startsWith(pair.first)) {
				color = pair.second;
				html.remove(j, pair.first.length());
			}
		}
		if (start) {
			textColor = QString("<font color=\"%1\">").arg(color.name());
			start = false;
		}
		else
			textColor = QString("</font><font color=\"%1\">").arg(color.name());
		html.insert(j, textColor);
		j += 1 + textColor.length();
	}
	html.append("</font>");
	OutPut->appendHtml(html);
}




void Log::escribir(string mensaje)
{
	// Escribimos en el log
	this->log << currentDateTime()+" "<< mensaje << endl;

	QString text = QString("\033cyan %1 \033black%2 ").arg(currentDateTime().c_str())
                .arg(mensaje.c_str());

	appendText(text);
	

}
void Log::error(string mensaje){
	// Escribimos en el log
	
	this->log << currentDateTime() + " [ERROR [ " << to_string(errors) + "]" << mensaje << endl;
	this->errors++;

	std::string str =  "[ERROR["+ to_string(errors) + "]" ;

	QString text = QString("\033cyan %1 \033red%2 \033black%3")
		.arg(currentDateTime().c_str())
		.arg(str.c_str())
		.arg(mensaje.c_str());

	appendText(text);
}
void Log::warning(string mensaje){

	// Escribimos en el log
	cout << currentDateTime() + " [WARNING]" << mensaje << endl;
	this->log << currentDateTime() + " [WARNING]" << mensaje << endl;



	QString text = QString("\033cyan %1 \033yellow%2 \033black%3")
		.arg(currentDateTime().c_str())
		.arg("[WARNING]")
		.arg(mensaje.c_str());

	appendText(text);

}
void Log::success(string mensaje)
{
	// Escribimos en el log
	cout << currentDateTime() + " [SUCCESSFUL] " << mensaje << endl;
	this->log << currentDateTime() + " [SUCCESSFUL] " << mensaje << endl;





	QString text = QString("\033cyan %1 \033green%2 \033black%3")
		.arg(currentDateTime().c_str())
		.arg(" [SUCCESSFUL] ")
		.arg(mensaje.c_str());

	appendText(text);


	
}
void Log::close()
{
	this->log << "--------------END LOG------------------- " << endl;
// Cerramos el archivo
	this->log.close();
	
}

