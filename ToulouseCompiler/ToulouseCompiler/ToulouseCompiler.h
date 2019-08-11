#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ToulouseCompiler.h"
#include "CodeEditor.h"
#include "OpenGLWidget.h"
#include "Log.h"
#include <QTableWidget>
#include "addDialog.h"
#include <QPoint>
#include <QComboBox>
#include <vector>
#include <QDebug>
#include <QMessageBox>
#include<QDir>

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

	
	QStackedWidget* stakedView;//Pointer to the widget for code editor

	CodeEditor* vertexShader;
	CodeEditor* fragmentShader;
	QString curFile;
	
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
	QStatusBar* statusBar;

	/********************END OUTPUT DATA********************/

	/********************OPENGL DATA********************/
	QWidget* openglwidget;
	std::vector<dataForUniform> uniforms;
	OpenGLWidget* openGLWindow;
	/********************END OPENGL DATA********************/


	/********************UNIFORMS TABLE DATA********************/

	QTableWidget* tableUniforms;
	QPushButton *addUniform;//Pointer to the button for add uniforms
	addDialog* addForm;

	enum column {
		name,type, value,deleteRow
	};

	bool empty = true;
	/********************END UNIFORMS TABLE DATA********************/

	//metodo que hara que se llamen a todos los configurate de la aplicacion
	//que se encargan de enlazar la ui con las clases cpp que gestionan el funcionamiento
	void configurate();

	void configuration_changePage();
	void configuration_ToolBar();

	void configuration_tablaUniforms();

	void configuration_OutPut();
	void configuration_codeEditor();
	void configuration_opengl();


	void loadFile(const QString &fileName);
	bool saveFile(const QString &fileName);
	void setCurrentFile(const QString &fileName);


private slots:

	//Manage the data send for the ui that add uniforms
	void handleData(const dataForUniform &data);

	//Manage the data that is edit
	void editSlot(int row, int col);
	void cell_onClicked();
	void cell_comboBoxChanged(const QString &newValue);

	//BUTTONS
	void handleButton();
	void handleToolActionPoints();
	void handleToolActionLines();
	void handleToolActionTriangles();
	void handleToolActionSave();
	void handleToolActionRender();
	void handleButtonAddUniform();
};