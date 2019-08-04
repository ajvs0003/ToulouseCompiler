#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ToulouseCompiler.h"

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

	//Pointer to the widget for code editor
	QStackedWidget* editor;


	QPlainTextEdit* OutPut;


	int index = 0;




	void configuration_changePage();
	void configuration_OutPut();


private slots:
	void handleButton();


};
