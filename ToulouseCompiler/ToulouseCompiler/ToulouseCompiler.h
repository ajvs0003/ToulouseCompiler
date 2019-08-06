#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ToulouseCompiler.h"
#include <CodeEditor.h>
#include "Log.h"


class ToulouseCompiler : public QMainWindow
{
	Q_OBJECT

public:
	ToulouseCompiler(QWidget *parent = Q_NULLPTR);

private:


	Ui::MainWindowClass ui;

	//Pointer to the button for change pages
	QPushButton *changePage;
	QLabel *vistaActivada;


	/*CODE EDITOR DATA*/

	//Pointer to the widget for code editor
	QStackedWidget* stakedView;

	CodeEditor* vertexShader;
	CodeEditor* fragmentShader;

	//index for change text of button
	int index = 0;







	QPlainTextEdit* OutPut;


	

	//metodo que hara que se llamen a todos los configurate de la aplicacion
	//que se encargan de enlazar la ui con las clases cpp que gestionan el funcionamiento
	void configurate();

	void configuration_changePage();
	void configuration_OutPut();
	void configuration_codeEditor();
	void configuration_opengl();


private slots:
	void handleButton();


};
