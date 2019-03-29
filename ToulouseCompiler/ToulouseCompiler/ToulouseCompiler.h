#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ToulouseCompiler.h"

class ToulouseCompiler : public QMainWindow
{
	Q_OBJECT

public:
	ToulouseCompiler(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindowClass ui;
};
