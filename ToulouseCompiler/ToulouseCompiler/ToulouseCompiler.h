#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ToulouseCompiler.h"
#include "CodeEditor.h"
#include "OpenGLWidget.h"
#include "Log.h"
#include "tableUniforms.h"
#include <QTableWidget>
#include <QPoint>
#include <QComboBox>
#include <vector>
#include <QDebug>


/*******************/
class ToulouseCompiler : public QMainWindow
{
	Q_OBJECT

public:
	ToulouseCompiler(QWidget *parent = Q_NULLPTR);
	~ToulouseCompiler();
	


private:


	Ui::MainWindowClass ui;//MAIN WINDOW
	
	


	/********************CODE EDITOR DATA********************/

	
	//Pointer to the widget for code editor
	QTabWidget* tabView;
	CodeEditor* vertexShader;
	CodeEditor* fragmentShader;
	QString curFile;
	
	

	/********************END CODE EDITOR DATA********************/



	/********************TOOL BAR DATA********************/


	QAction* modePoints;
	QAction* modeLines;
	QAction* modeTriangles;
	QAction* modeMaterial;
	QAction* modeTextures;


	QAction* peon;
	QAction* copa;
	QAction* joy;

	QAction* UniformTable;
	QAction* newFile;
	QAction* load;
	QAction* save;
	QAction* saveAs;
	QAction* render;

	/********************END TOOL BAR DATA********************/



	/********************OUTPUT DATA********************/

	QPlainTextEdit* OutPut;
	QStatusBar* statusBar;

	/********************END OUTPUT DATA********************/

	/********************OPENGL DATA********************/
	QWidget* openglwidget;
	OpenGLWidget* openGLWindow;
	glm::vec2 oldMousePosition;
	bool isHold = false;

	/********************END OPENGL DATA********************/


	/********************UNIFORMS TABLE DATA********************/

	std::vector<dataForUniform> uniforms;
	tableUniforms* table;

	

	
	/********************END UNIFORMS TABLE DATA********************/





	//metodo que hara que se llamen a todos los configurate de la aplicacion
	//que se encargan de enlazar la ui con las clases cpp que gestionan el funcionamiento
	void configurate();


	void configuration_ToolBar();

	void configuration_tableWindow();

	void configuration_OutPut();
	void configuration_codeEditor();
	void configuration_opengl();


	void loadFile(const QString &fileName);
	bool saveFile(const QString &fileName);
	void setCurrentFile(const QString &fileName);

	int findData(dataForUniform &data);

	bool maybeSave();

private slots:

	//Camera Inputs

	void Mouse_currentPos();
	void Mouse_Pressed();
	void Mouse_Realeased();
	void Mouse_Left();


	//Manage the data send for the ui that add uniforms
	void handleData(const dataForUniform &data);
	void handleEditData(const dataForUniform &data);
	void handleRemoveData(const dataForUniform &data);

	//BUTTONS
	
	void handleToolActionPoints();
	void handleToolActionLines();
	void handleToolActionTriangles();
	void handleToolActionMaterial();
	void handleToolActionTextures();

	void handleToolActionPeon();
	void handleToolActionCopa();
	void handleToolActionJoy();
	

	void handleToolActionNew();
	void handleToolActionOpen();
	bool handleToolActionSave();
	bool handleToolActionSaveAs();

	void handleToolActionTableUniforms();


	void handleToolActionRender();
	
};