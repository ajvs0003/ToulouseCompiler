#include "addDialog.h"
#include "ui_addDialog.h"
addDialog::addDialog(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::addDialog();
	ui->setupUi(this);


	//take the pointer to the QDialogButtonBox 
	guardar_cancelar = ui->buttonBox;

	//Set to don allow to push the save button
	guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(false);


	//take the pointer to the comBox 
	options = ui->comboBox;
	//for manage when is changed the value
	connect(options, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(switchcall(const QString&)));


	inputValue = ui->lineEdit;
	//for manage when is changed the value
	connect(inputValue, SIGNAL(textChanged(const QString&)), this, SLOT(text_changed(const QString &)));


	nameVar = ui->nameVar;
	//for manage when is changed the value
	connect(inputValue, SIGNAL(textChanged(const QString&)), this, SLOT(textName_changed(const QString &)));


	//checkBox
	multipleAddings = ui->checkBox;


	//This is important for manage the save button and cancel button
	connect(guardar_cancelar, SIGNAL(accepted()), this, SLOT(push_save()));
	connect(guardar_cancelar, SIGNAL(rejected()), this, SLOT(push_reject()));
}

addDialog::~addDialog()
{
	delete ui;
}



void addDialog::push_reject()
{

	this->close();
}



void addDialog::push_save()
{
	/*Log::getInstancia()->warning("Pulsado guardar");*/

	dataForUniform nuevo;

	nuevo.name = nameVar->text().toStdString();
	nuevo.type = options->currentText().toStdString();
	nuevo.value = inputValue->text().toStdString();
	
	
	//Send the data to the mainWindow
	emit dataChanged(nuevo);
	if (!multipleAddings->isChecked())this->close();

	guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(false);




}

void addDialog::textName_changed(const QString &newValue) {

	//Manage that all fields aren't empty


	if (newValue != "") {
		textNameCheck = true;
		if (typeCheck == true && textCheck)guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(true);
	}
	else {
		textNameCheck = false;
		guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(false);
	}
}


void addDialog::text_changed(const QString &newValue) {

	//Manage that all fields aren't empty


	if (newValue != "") {
		textCheck = true;
		if (typeCheck == true && textNameCheck)guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(true);
	}
	else {
		textCheck = false;
		guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(false);
	}
}
void addDialog::switchcall(const QString&  value) {

	if (value != "") {
		typeCheck = true;
		if (textCheck == true && textNameCheck)guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(true);
	}
	else {
		typeCheck = false;
		guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(false);
	}

}