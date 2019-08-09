#pragma once

#include <QDialog>
#include <QDialogButtonBox>
#include "Log.h"
#include <QCheckBox>
#include <QPushButton>
#include <QLineEdit>
#include <Qstring>
typedef struct
{
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

	QLineEdit* inputValue;


	bool textCheck = false;
	bool typeCheck = false;

private slots:
	
	void push_save();
	void push_reject();

	void text_changed(const QString &newValue);
	void switchcall(const QString&value);
	
signals:
	void dataChanged(const dataForUniform &data);
	
	
};
