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


	inputValue = ui->lineEdit;
	connect(inputValue, SIGNAL(textChanged(const QString &)), this, SLOT(customSlot(const QString &newValue)));




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


	if (newValue != "") {
		textCheck = true;
		if (typeCheck == true)enableButtonSave = true;
	}
}