#include "addDialog.h"
#include "ui_addDialog.h"
addDialog::addDialog(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::addDialog();
	ui->setupUi(this);

	guardar_cancelar = ui->buttonBox;
	guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(false);

	options = ui->comboBox;
	connect(options, SIGNAL(currentIndexChanged(const QString&)),this, SLOT(switchcall(const QString&)));


	inputValue = ui->lineEdit;
	connect(inputValue, SIGNAL(textChanged(const QString&)), this, SLOT(text_changed(const QString &)));




	multipleAddings = ui->checkBox;



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
	
		
		dataForUniform nuevo;
		Log::getInstancia()->warning("Pulsado guardar");


		nuevo.value = inputValue->text().toUtf8().constData();
		nuevo.type = options->currentIndex();

		emit dataChanged(nuevo);
		if (!multipleAddings->isChecked())this->close();

		guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(false);
	

	

}

void addDialog::text_changed(const QString &newValue) {
	Log::getInstancia()->warning("detectado cambio texto");

	if (newValue != "") {
		textCheck = true;
		if (typeCheck == true)guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(true);
	}
}
void addDialog::switchcall(const QString&  value) {
	Log::getInstancia()->warning("Detectado cambio de tipo");
	if (value != "") {
		typeCheck = true;
		if (textCheck == true)guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(true);
	}

}