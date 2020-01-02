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
	options->setEditable(true);
	options->lineEdit()->setReadOnly(true);
	options->lineEdit()->setAlignment(Qt::AlignCenter);
	
	options->addItems(QStringList() << tr("boolean") << tr("vec3") << tr("vec4") << tr("float") << tr("int")); //add the types for the uniforms
	
	//for manage when is changed the value
	connect(options, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(switchcall(const QString&)));


	inputValue = ui->lineEdit;

	/*QLineEdit *lineedit = new QLineEdit;
	ui->layoutValueUniform->addWidget(lineedit);*/

	inputValue->setStyleSheet("border-image:  url(:/img/Resources/img/lineEdit.png) 5 5 5 5 stretch stretch;border-width: 5px 5px 5px 5px;");
	/*inputValue->hide();*/
	//for manage when is changed the value
	connect(inputValue, SIGNAL(textChanged(const QString&)), this, SLOT(text_changed(const QString &)));


	nameVar = ui->nameVar;
	nameVar->setStyleSheet("border-image:  url(:/img/Resources/img/lineEdit.png) 5 5 5 5 stretch stretch;border-width: 5px 5px 5px 5px;");
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
	nuevo.id = idCont;
	nuevo.name = nameVar->text().toStdString();
	nuevo.type = options->currentText().toStdString();
	nuevo.value = inputValue->text().toStdString();
	
	idCont++;
	
	
	//Send the data to the mainWindow
	emit dataChanged(nuevo);
	if (!multipleAddings->isChecked())this->close();

	guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(false);
	nameVar->setText("");
	inputValue->setText("");

	//set the index in null
	options->setCurrentIndex(-1);

}

void addDialog::textName_changed(const QString &newValue) {

	//Manage that all fields aren't empty


	if (newValue != "") {
		textNameCheck = true;
		if (typeCheck  && textCheck)guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(true);
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
		if (typeCheck  && textNameCheck)guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(true);
	}
	else {
		textCheck = false;
		guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(false);
	}
}
void addDialog::switchcall(const QString&  value) {

	if (value != "") {
		typeCheck = true;
		if (textCheck  && textNameCheck)guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(true);
	}
	else {
		typeCheck = false;
		guardar_cancelar->button(QDialogButtonBox::Save)->setEnabled(false);
	}

}

void addDialog::about()

{

	QMessageBox::about(this, tr("About Uniform form"),
		tr("The <b>Form below</b> show data that the user can fill for an uniform. "
			"<b> Important: </b>if you use vec3 or vec4 enter the data separated by <b>comma</b>. "
			"Ex:(1.0,0.0,0.0)"));
}


bool addDialog::event(QEvent *event)
{
	if (event->type() == QEvent::EnterWhatsThisMode) {

		about();
	}


	return QDialog::event(event);
}