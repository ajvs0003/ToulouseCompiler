#include "tableUniforms.h"
#include "ui_tableUniforms.h"

tableUniforms::tableUniforms(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::tableUniforms();
	ui->setupUi(this);


	table = ui->table;

	table->setColumnCount(4);

	table->setHorizontalHeaderLabels(QStringList() << tr("Name") << tr("Uniform Type") << tr("Value") << tr(""));



	//only read if i active this
	table->setEditTriggers(QAbstractItemView::NoEditTriggers);


	table->verticalHeader()->setVisible(false);
	table->setShowGrid(false);

	//for put that all the widget is only the 4 columns that we have
	QHeaderView* header = table->horizontalHeader();
	header->setSectionResizeMode(QHeaderView::Stretch);




	//para editar celdas

	connect(table, SIGNAL(cellChanged(int, int)), this, SLOT(editSlot(int, int)));

	table->show();



	addUniform = ui->addUniform;

	addUniform->setStyleSheet("QPushButton{background: transparent;}");
	//gestiona los conect del boton
	connect(addUniform, SIGNAL(released()), this, SLOT(handleButtonAddUniform()));


	help = ui->help;
	help->setStyleSheet("QPushButton{background: transparent;}");
	connect(help, SIGNAL(released()), this, SLOT(handleButtonAboutUniform()));

	accept = ui->aceptar;
	connect(accept, SIGNAL(released()), this, SLOT(handleButtonAccept()));




	Qt::WindowFlags flags = windowFlags();
	flags |= Qt::CustomizeWindowHint;
	flags &= ~Qt::WindowContextHelpButtonHint;
	flags &= ~Qt::WindowSystemMenuHint;
	setWindowFlags(flags);
}

tableUniforms::~tableUniforms()
{
	delete ui;
}



void tableUniforms::handleButtonAboutUniform()
{
	QMessageBox::about(this, tr("About Uniforms Table "),
		tr("The <b>Table</b> show the uniforms that the user added for this shader. "
			"<b> Important: </b>you must read the manual for know what uniforms are included by configuration. "
			"Ex:(material mode & lights mode)"));





}



void tableUniforms::handleButtonAccept()
{
	close();



}

void tableUniforms::handleButtonAddUniform()
{
	/*Log::getInstancia()->warning("Pulsado add");*/



	//**************widget add uniforms data***************//

	addForm = new addDialog(this);
	// connect your signal to the mainwindow slot
	connect(addForm, SIGNAL(dataChanged(const dataForUniform &)), this, SLOT(handleData(const dataForUniform &)));

	addForm->setWindowTitle("Uniform Data");

	//if is true dont let change the window until close

	/*addForm->setModal(true);*/

	addForm->show();



	//**************end widget add uniforms data***************//





}

void tableUniforms::editSlot(int row, int col) {


	if (row >= 0) {

		switch (col) {
		case column::name:
			uniforms.at(row).name = table->item(row, col)->text().toStdString();
			emit editUniform(uniforms.at(row));
			break;
		case column::value:
			uniforms.at(row).value = table->item(row, col)->text().toStdString();
			emit editUniform(uniforms.at(row));
			break;

		default:
			break;

		}
	}

}
//Method that manage the signal for edit type of the uniform
void tableUniforms::cell_comboBoxChanged(const QString & newValue)
{

	int row = sender()->property("row").toInt();
	uniforms.at(row).type = newValue.toStdString();
	emit editUniform(uniforms.at(row));

}
//Method that manage the signal for remove the uniform
void tableUniforms::cell_onClicked() {
	

	QWidget *w = qobject_cast<QWidget *>(sender()->parent());
	if (w) {
		int row = table->indexAt(w->pos()).row();

		string id = uniforms.at(row).name;
		dataForUniform aux = uniforms.at(row);
		uniforms.erase(
			std::remove_if(uniforms.begin(), uniforms.end(), [&](dataForUniform const & data) {
			return data.name == id;
		}),
			uniforms.end());

		emit removeUniform(aux);
		table->removeRow(row);
		table->setCurrentCell(0, 0);
	}
}




//this slot handle the data that for the uniforms that the widget send
void tableUniforms::handleData(const dataForUniform &data)
{
	table->setEditTriggers(QAbstractItemView::DoubleClicked);
	emit newUniform(data);
	//**************table widget data***************//
	int row = table->rowCount();
	table->insertRow(table->rowCount());


	dataForUniform nuevo = data;
	uniforms.push_back(nuevo);


	//create qt elements for the table
	QTableWidgetItem *name = new QTableWidgetItem(QString::fromStdString(data.name));
	name->setTextAlignment(Qt::AlignCenter);
	
	QTableWidgetItem *value = new QTableWidgetItem(QString::fromStdString(data.value));
	value->setTextAlignment(Qt::AlignCenter);

	//insert values to the table
	table->setItem(row, column::name, name);
	table->setItem(row, column::value, value);



	//comboBox for type
	QWidget* pWi = new QWidget();
	QComboBox* combo = new QComboBox();

	combo->setProperty("row", (int)row); // row represents the row number in qtablewidget

	combo->addItems(QStringList() << tr("boolean") << tr("vec3") << tr("vec4") << tr("float") << tr("int")); //add the types for the uniforms

	if (nuevo.type == "boolean")combo->setCurrentIndex(0);
	else if (nuevo.type == "vec3")combo->setCurrentIndex(1);
	else if (nuevo.type == "vec4")combo->setCurrentIndex(2);
	else if (nuevo.type == "float")combo->setCurrentIndex(3);
	else if (nuevo.type == "int")combo->setCurrentIndex(4);





	connect(combo, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(cell_comboBoxChanged(const QString&)));//conect signalk if something change

//# layout for the comboBox
	QHBoxLayout* pLayout = new QHBoxLayout(pWi);
	pLayout->addWidget(combo);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWi->setLayout(pLayout);
	table->setCellWidget(row, column::type, pWi);

	QIcon icon(":/img/Resources/img/delete.png");
	QWidget* pWidget = new QWidget();
	QPushButton* btn_edit = new QPushButton();
	btn_edit->setIcon(icon);
	btn_edit->setStyleSheet("QPushButton{background: transparent;}");

	connect(btn_edit, SIGNAL(clicked()), this, SLOT(cell_onClicked()));

	//# layout for the qPushButton
	QHBoxLayout* Layout = new QHBoxLayout(pWidget);
	Layout->addWidget(btn_edit);
	Layout->setAlignment(Qt::AlignCenter);
	Layout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(Layout);
	table->setCellWidget(row, column::deleteRow, pWidget);





	//**************end table widget data***************//


}





