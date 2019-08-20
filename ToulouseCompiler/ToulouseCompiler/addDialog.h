#pragma once

#include <QDialog>
#include <QDialogButtonBox>
#include "Log.h"
#include <QCheckBox>
#include <QPushButton>
#include <QLineEdit>
#include <Qstring>


//Very important for can send data to the main window
typedef struct
{
	int id;
	string name;
	string type;
	string value;
} dataForUniform;

Q_DECLARE_METATYPE(dataForUniform);


namespace Ui { class addDialog; };

class addDialog : public QDialog
{
	Q_OBJECT

public:
	


	addDialog(QWidget *parent = Q_NULLPTR);
	~addDialog();




	


private:
	Ui::addDialog *ui;


	QDialogButtonBox* guardar_cancelar;

	QComboBox* options;

	QCheckBox* multipleAddings;

	QLineEdit* nameVar;
	QLineEdit* inputValue;

	bool textNameCheck = false;
	bool textCheck = false;
	bool typeCheck = false;

	int idCont = 0;

	bool event(QEvent *event);

	void about();

private slots:
	
	void push_save();
	void push_reject();

	void text_changed(const QString &newValue);
	void switchcall(const QString&value);
	void textName_changed(const QString &newValue);
signals:
	void dataChanged(const dataForUniform &data);
	
	
};
