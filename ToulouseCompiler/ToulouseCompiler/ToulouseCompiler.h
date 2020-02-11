#pragma once

#include <QtWidgets/QMainWindow>
#include <QTableWidget>
#include <QPoint>
#include <QComboBox>
#include <map>
#include <QDebug>

#include "ToulouseConstants.h"
#include "ui_ToulouseCompiler.h"
#include "CodeEditor.h"
#include "OpenGLWidget.h"
#include "Log.h"
#include "tableUniforms.h"
#include "Highlighter.h"



/*******************/
class ToulouseCompiler : public QMainWindow
{
	Q_OBJECT

private:
	/******************** MAIN WINDOW ********************/
	Ui::MainWindowClass ui;

	/********************CODE EDITOR DATA********************/

	QTabWidget* tabView;//Pointer to the widget for code editor
	CodeEditor* vertexShader;
	CodeEditor* fragmentShader;

	QString curFile;//actual address for save location

	//Highlight of words
	Highlighter* VertexHighlighter;
	Highlighter* FragmentHighlighter;

	/********************TOOL BAR DATA********************/

	map<int, QAction*> actionsButtons;



	/********************OUTPUT DATA********************/
	QPlainTextEdit* Debug;
	QStatusBar* statusBar;

	/********************OPENGL DATA********************/
	QWidget* openglwidget;
	OpenGLWidget* openGLWindow;
	glm::vec2 oldMousePosition;
	bool isHold = false;

	/********************UNIFORMS TABLE DATA********************/
	TableUniforms* table;

	/********************LANGUAGE DATA********************/
	QTranslator spanishTranslator;
	QTranslator englishTranslator;
	QAction* spanishButton;
	QAction* englishButton;


	//metodo que hara que se llamen a todos los configurate de la aplicacion
	//que se encargan de enlazar la ui con las clases cpp que gestionan el funcionamiento
	void configurate();
	void configuration_ToolBar();
	void configuration_tableWindow();
	void configuration_Debug();
	void configuration_codeEditor();
	void configuration_opengl();
	void configuration_translators();


	void checkModeOpenGL();
	void checkObject();

	//Metodos para la gestion de guardar los shader program o abrir alguno existente
	void loadFile(const QString& fileName);
	bool saveFile(const QString& fileName);
	void setCurrentFile(const QString& fileName);
	bool maybeSave();


public:
	ToulouseCompiler(QWidget* parent = Q_NULLPTR);
	~ToulouseCompiler();

protected:
	void changeEvent(QEvent*);

protected slots:

	//Camera Inputs

	void Mouse_currentPos();
	void Mouse_Pressed();
	void Mouse_Realeased();
	void Mouse_Left();
	void manageUniformsFromTable(const QVector<dataForUniform>& data);


	//BUTTONS

	void handleToolActionPoints();
	void handleToolActionLines();
	void handleToolActionTriangles();
	void handleToolActionMaterial();
	void handleToolActionTextures();
	void handleToolActionPeon();
	void handleToolActionCopa();
	void handleToolActionJoy();
	void handleToolActionRender();

	//FILE 
	void handleToolActionNew();
	void handleToolActionOpen();
	bool handleToolActionSave();
	bool handleToolActionSaveAs();

	//TOOLS
	void handleToolActionTableUniforms();


	//Language
	void Spanish_clicked();
	void English_clicked();

};