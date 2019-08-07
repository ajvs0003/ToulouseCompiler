#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ToulouseCompiler.h"
#include "CodeEditor.h"
#include "OpenGLWidget.h"
#include "Log.h"

/*******************/
class ToulouseCompiler : public QMainWindow
{
	Q_OBJECT

public:
	ToulouseCompiler(QWidget *parent = Q_NULLPTR);

private:


	Ui::MainWindowClass ui;//MAIN WINDOW

	


	/********************CODE EDITOR DATA********************/

	
	QStackedWidget* stakedView;//Pointer to the widget for code editor

	CodeEditor* vertexShader;
	CodeEditor* fragmentShader;

	
	QPushButton *changePage;//Pointer to the button for change pages
	QLabel *vistaActivada;//label for indicate the current shader editor active
	int index = 0;//index for change text of button

	/********************END CODE EDITOR DATA********************/



	/********************TOOL BAR DATA********************/


	QAction* modePoints;
	QAction* modeLines;
	QAction* modeTriangles;

	QAction* save;
	QAction* render;

	/********************END TOOL BAR DATA********************/



	/********************OUTPUT DATA********************/

	QPlainTextEdit* OutPut;


	/********************END OUTPUT DATA********************/

	/********************OPENGL DATA********************/
	QWidget* openglwidget;

	OpenGLWidget* openGLWindow;
	/********************END OPENGL DATA********************/


	//metodo que hara que se llamen a todos los configurate de la aplicacion
	//que se encargan de enlazar la ui con las clases cpp que gestionan el funcionamiento
	void configurate();

	void configuration_changePage();
	void configuration_ToolBar();



	void configuration_OutPut();
	void configuration_codeEditor();
	void configuration_opengl();


private slots:
	void handleButton();
	void handleToolActionPoints();
	void handleToolActionLines();
	void handleToolActionTriangles();
	void handleToolActionSave();
	void handleToolActionRender();
};