﻿#include "ToulouseCompiler.h"
#include <QSurfaceFormat>

#include <QSizePolicy>


ToulouseCompiler::ToulouseCompiler(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	this->setWindowIcon(QIcon(":/img/Resources/img/icono.png"));

	this->configurate();


}




ToulouseCompiler::~ToulouseCompiler()
{
	delete stakedView;
	delete changePage;
	delete vistaActivada;
	delete modePoints;
	delete modeLines;
	delete modeTriangles;
	delete save;
	delete render;
	delete OutPut;
	delete openglwidget;
	delete tableUniforms;
	delete addUniform;

}

void ToulouseCompiler::handleButton() {

	if (index == 0) {
		index = 1;
		vistaActivada->setText("Fragment Shader");
	}
	else {
		index = 0;
		vistaActivada->setText("Vertex Shader");
	}

	stakedView->setCurrentIndex(index);
}

void ToulouseCompiler::handleToolActionPoints() {



	if (modeLines->isChecked()) {
		modeLines->setChecked(false);
	}
	if (modeTriangles->isChecked()) {
		modeTriangles->setChecked(false);
	}




	if (modePoints->isChecked()) {

		openGLWindow->changeTrial(0);

		Log::getInstancia()->warning("activado el modo puntos");
	}
	else {

		modePoints->setChecked(false);

	}

}

void ToulouseCompiler::handleToolActionLines()
{


	if (modePoints->isChecked()) {
		modePoints->setChecked(false);
	}
	if (modeTriangles->isChecked()) {
		modeTriangles->setChecked(false);
	}




	if (modeLines->isChecked()) {

		openGLWindow->changeTrial(1);

		Log::getInstancia()->warning("activado el modo lineas");
	}
	else {

		modeLines->setChecked(false);

	}







}

void ToulouseCompiler::handleToolActionTriangles()
{

	if (modeLines->isChecked()) {
		modeLines->setChecked(false);
	}
	if (modePoints->isChecked()) {
		modePoints->setChecked(false);
	}




	if (modeTriangles->isChecked()) {

		openGLWindow->changeTrial(2);

		Log::getInstancia()->warning("activado el modo triangulos");
	}
	else {

		modeTriangles->setChecked(false);

	}




}

void ToulouseCompiler::handleToolActionSave()
{


	Log::getInstancia()->warning("Pulsado guardar");

}

void ToulouseCompiler::handleToolActionRender()
{
	/*Log::getInstancia()->warning("Pulsado render");*/

	OutPut->clear();


	if (!uniforms.empty()) {
		Log::getInstancia()->warning("HAY chicha");
	}

	//resetear log
	openGLWindow->compile();
}

void ToulouseCompiler::editSlot(int row, int col) {

	
	if (row>=0) {

		switch (col) {
		case column::name:
			uniforms.at(row).name = tableUniforms->item(row, col)->text().toStdString();
			
			break;
		case column::value:
			uniforms.at(row).value = tableUniforms->item(row, col)->text().toStdString();
			
			break;

		default:
			break;

		}
	}

}

//Method that manage the signal for remove the uniform
void ToulouseCompiler::cell_onClicked() {
	QWidget *w = qobject_cast<QWidget *>(sender()->parent());
	if (w) {
		int row = tableUniforms->indexAt(w->pos()).row();

		string id = uniforms.at(row).name;

		uniforms.erase(
			std::remove_if(uniforms.begin(), uniforms.end(), [&](dataForUniform const & data) {
			return data.name == id;
		}),
			uniforms.end());

		tableUniforms->removeRow(row);
		tableUniforms->setCurrentCell(0, 0);
	}
}



//Method that manage the signal for edit type of the uniform
void ToulouseCompiler::cell_comboBoxChanged(const QString & newValue)
{

	int row = sender()->property("row").toInt();
	uniforms.at(row).type = newValue.toStdString();

}


void ToulouseCompiler::Mouse_currentPos() {
	float width = openGLWindow->w;
	float height = openGLWindow->h;

	glm::vec2 newMousePosition((float)openGLWindow->posX, (float)openGLWindow->posY);
	GLfloat mouseSensitive = 0.1f;
	glm::vec2 mouseDelta = newMousePosition - oldMousePosition;//cuanto de movio el raton


	if (glm::length(mouseDelta) > 50.0f) {
		oldMousePosition = newMousePosition;
		return;
	}

	if (isHold) {
		/*openGLWindow->camera->tiltAndPan(mouseDelta.x*mouseSensitive, mouseDelta.y*mouseSensitive);*/
		if (mouseDelta.y > 0) {
			openGLWindow->camera->orbitX(1.f);

		}
		else if (mouseDelta.y < 0) {
			openGLWindow->camera->orbitX(-1.f);

		}
		else {

			if (mouseDelta.x > 0) {
				openGLWindow->camera->orbitY(1.f);

			}
			else if (mouseDelta.x < 0) {
				openGLWindow->camera->orbitY(-1.f);

			}

		}
		
		openGLWindow->renderNow();
	}


	oldMousePosition = newMousePosition;


	

}


void ToulouseCompiler::Mouse_Pressed()
{

	isHold = true;

}

void ToulouseCompiler::Mouse_Realeased()
{
	
	isHold = false;
}

void ToulouseCompiler::Mouse_Left()
{
	isHold = false;
}

//this slot handle the data that for the uniforms that the widget send
void ToulouseCompiler::handleData(const dataForUniform &data)
{
	tableUniforms->setEditTriggers(QAbstractItemView::DoubleClicked);

	//**************table widget data***************//
	int row = tableUniforms->rowCount();
	tableUniforms->insertRow(tableUniforms->rowCount());


	dataForUniform nuevo = data;
	uniforms.push_back(nuevo);


	//create qt elements for the table
	QTableWidgetItem *name = new QTableWidgetItem(QString::fromStdString(data.name));
	QTableWidgetItem *value = new QTableWidgetItem(QString::fromStdString(data.value));


	//insert values to the table
	tableUniforms->setItem(row, column::name, name);
	tableUniforms->setItem(row, column::value, value);



	//comboBox for type
	QWidget* pWi = new QWidget();
	QComboBox* combo = new QComboBox();

	combo->setProperty("row", (int)row); // row represents the row number in qtablewidget

	combo->addItems(QStringList() << tr("boolean") << tr("vec3") << tr("vec4") << tr("float") << tr("int")); //add the types for the uniforms

	combo->setCurrentText(QString::fromStdString(data.type));

	connect(combo, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(cell_comboBoxChanged(const QString&)));//conect signalk if something change

//# layout for the comboBox
	QHBoxLayout* pLayout = new QHBoxLayout(pWi);
	pLayout->addWidget(combo);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWi->setLayout(pLayout);
	tableUniforms->setCellWidget(row, column::type, pWi);


	QWidget* pWidget = new QWidget();
	QPushButton* btn_edit = new QPushButton();
	btn_edit->setText("Remove");

	connect(btn_edit, SIGNAL(clicked()), this, SLOT(cell_onClicked()));

	//# layout for the qPushButton
	QHBoxLayout* Layout = new QHBoxLayout(pWidget);
	Layout->addWidget(btn_edit);
	Layout->setAlignment(Qt::AlignCenter);
	Layout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(Layout);
	tableUniforms->setCellWidget(row, column::deleteRow, pWidget);





	//**************end table widget data***************//


}


void ToulouseCompiler::handleButtonAddUniform()
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



void ToulouseCompiler::configurate()
{

	this->configuration_OutPut();

	this->configuration_changePage();
	this->configuration_codeEditor();
	this->configuration_opengl();
	this->configuration_ToolBar();
	this->configuration_tablaUniforms();



	statusBar->showMessage("Ready for start");


}

void ToulouseCompiler::configuration_changePage()
{

	vistaActivada = ui.vistaActivada;
	vistaActivada->setText("Vertex Shader");

	//Take the button that i design in de editor and conect the signal for can handle the click event, and change the page in the stakeck view
	changePage = ui.changePage;
	changePage->setStyleSheet("QPushButton{background: transparent;}");
	//gestiona los conect del boton
	connect(changePage, SIGNAL(released()), this, SLOT(handleButton()));



}

void ToulouseCompiler::configuration_ToolBar()
{

	//signals for manage the action in the toolbar

	modePoints = ui.actionPoints;

	modePoints->setChecked(true);
	connect(modePoints, SIGNAL(triggered()), this, SLOT(handleToolActionPoints()));


	modeLines = ui.actionLines;
	connect(modeLines, SIGNAL(triggered()), this, SLOT(handleToolActionLines()));


	modeTriangles = ui.actiontriangles;
	connect(modeTriangles, SIGNAL(triggered()), this, SLOT(handleToolActionTriangles()));

	save = ui.actionSave;
	connect(save, SIGNAL(triggered()), this, SLOT(handleToolActionSave()));

	render = ui.actionRender;
	connect(render, SIGNAL(triggered()), this, SLOT(handleToolActionRender()));
}


void ToulouseCompiler::configuration_tablaUniforms()
{
	tableUniforms = ui.uniforms;

	tableUniforms->setColumnCount(4);

	tableUniforms->setHorizontalHeaderLabels(QStringList() << tr("Name") << tr("Type Uniform") << tr("Value") << tr("Delete"));

	

	//only read if i active this
	tableUniforms->setEditTriggers(QAbstractItemView::NoEditTriggers);


	tableUniforms->verticalHeader()->setVisible(false);


	//for put that all the widget is only the 4 columns that we have
	QHeaderView* header = tableUniforms->horizontalHeader();
	header->setSectionResizeMode(QHeaderView::Stretch);




	//para editar celdas

	connect(tableUniforms, SIGNAL(cellChanged(int, int)), this, SLOT(editSlot(int, int)));

	tableUniforms->show();



	addUniform = ui.addUniform;

	addUniform->setStyleSheet("QPushButton{background: transparent;}");
	//gestiona los conect del boton
	connect(addUniform, SIGNAL(released()), this, SLOT(handleButtonAddUniform()));
}





void ToulouseCompiler::configuration_OutPut()
{
	OutPut = ui.OutPut;
	
	OutPut->setReadOnly(true);// lo pongo en solo modo lectura

	//Gestiono que el log reciba el output para que otras clases puedan trabajar con el
	Log::getInstancia()->setOutPut(OutPut);

	statusBar = ui.statusBar;
	

}

void ToulouseCompiler::configuration_codeEditor()
{
	//I take the stakedWidget and assign to a pointer for can manage later all the stuff that i will need
	stakedView = ui.stackedWidget;
	stakedView->setCurrentIndex(index);

	this->vertexShader = new CodeEditor();
	this->fragmentShader = new CodeEditor();

	//Para que funcionara el resize hay que tener en cuenta que los valores de maximumSize en qt designer esten en el "maximo" (16777215) 
	ui.vertexLayout->addWidget(vertexShader);
	this->vertexShader->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



	ui.FragmentLayout->addWidget(fragmentShader);
	this->fragmentShader->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



}

void ToulouseCompiler::configuration_opengl()
{

	QSurfaceFormat format;
	format.setSamples(16);

	// Para cambiar la versión de OpenGL cambiar aquí y en la clase OpenGLFunctions
	format.setVersion(4, 5);

	openGLWindow = new OpenGLWidget();
	openGLWindow->setFormat(format);


	// Let's do the magic my dear TFG students :)
	openglwidget = QWidget::createWindowContainer(openGLWindow);


	ui.opengl_layout->addWidget(openglwidget);

	openglwidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


	//Configuration for camera inputs
	connect(openGLWindow, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_currentPos()));
	connect(openGLWindow, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed()));
	connect(openGLWindow, SIGNAL(Mouse_Released()), this, SLOT(Mouse_Realeased()));
	connect(openGLWindow, SIGNAL(Mouse_Left()), this, SLOT(Mouse_Left()));
}








void ToulouseCompiler::loadFile(const QString &fileName)

{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("Application"),
			tr("Cannot read file %1:\n%2.")
			.arg(QDir::toNativeSeparators(fileName), file.errorString()));
		return;
	}
}

bool ToulouseCompiler::saveFile(const QString &fileName)
		
	{
		QFile file(fileName);
		if (!file.open(QFile::WriteOnly | QFile::Text)) {
			QMessageBox::warning(this, tr("Application"),
				tr("Cannot write file %1:\n%2.")
				.arg(QDir::toNativeSeparators(fileName),
					file.errorString()));
			return false;
		}

		QTextStream out(&file);
#ifndef QT_NO_CURSOR
		QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
		out << vertexShader->toPlainText();

#ifndef QT_NO_CURSOR
		QApplication::restoreOverrideCursor();
#endif

		setCurrentFile(fileName);
		statusBar->showMessage(tr("File saved"), 2000);
		return true;
	}

void ToulouseCompiler::setCurrentFile(const QString &fileName)
{
	curFile = fileName;

	vertexShader->document()->setModified(false);

	setWindowModified(false);

	QString shownName = curFile;
	if (curFile.isEmpty())
		shownName = "untitled.txt";
	setWindowFilePath(shownName);
}