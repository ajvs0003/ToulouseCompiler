#include "ToulouseCompiler.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BOOL WINAPI FreeConsole(void);
	ToulouseCompiler app;
	app.show();


	
	return a.exec();
}
