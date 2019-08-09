#include "ToulouseCompiler.h"
#include <QSurfaceFormat>

#include <QSizePolicy>


ToulouseCompiler::ToulouseCompiler(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);



	this->configurate();


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


	bool desactivate = false;
	if (modeLines->isChecked()) {
		desactivate = true;
	}
	if (modeTriangles->isChecked()) {
		desactivate = true;
	}




	if (!desactivate) {

		openGLWindow->changeTrial(0);

		Log::getInstancia()->warning("activado el modo puntos");
	}
	else {

		modePoints->setChecked(false);

	}

}

void ToulouseCompiler::handleToolActionLines()
{

	bool desactivate = false;
	if (modePoints->isChecked()) {
		desactivate = true;
	}
	if (modeTriangles->isChecked()) {
		desactivate = true;
	}




	if (!desactivate) {

		openGLWindow->changeTrial(1);

		Log::getInstancia()->warning("activado el modo lineas");
	}
	else {

		modeLines->setChecked(false);

	}







}

void ToulouseCompiler::handleToolActionTriangles()
{
	bool desactivate = false;
	if (modeLines->isChecked()) {
		desactivate = true;
	}
	if (modePoints->isChecked()) {
		desactivate = true;
	}




	if (!desactivate) {

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

	openGLWindow->compile();
}



//this slot handle the data that for the uniforms that the widget send
void ToulouseCompiler::handleData(const dataForUniform &data)
{
	Log::getInstancia()->escribir(data.value);



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


	//**************table widget data***************//



	//**************end table widget data***************//


}

void ToulouseCompiler::configurate()
{

	this->configuration_OutPut();

	this->configuration_changePage();
	this->configuration_codeEditor();
	this->configuration_opengl();
	this->configuration_ToolBar();
	this->configuration_tablaUniforms();






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
	tablaUniforms = ui.uniforms;
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
}





//QList<QPair<QString, QColor> > list;
//list << QPair<QString, QColor>(tr("Alice"), QColor("aliceblue")) <<
//QPair<QString, QColor>(tr("Neptun"), QColor("aquamarine")) <<
//QPair<QString, QColor>(tr("Ferdinand"), QColor("springgreen"));
//
//QTableWidget *table = new QTableWidget(3, 2);
//table->setHorizontalHeaderLabels(QStringList() << tr("Name")
//	<< tr("Hair Color"));
//table->verticalHeader()->setVisible(false);
//table->resize(150, 50);
//
//for (int i = 0; i < 3; ++i) {
//	QPair<QString, QColor> pair = list.at(i);
//
//	QTableWidgetItem *nameItem = new QTableWidgetItem(pair.first);
//	QTableWidgetItem *colorItem = new QTableWidgetItem;
//	colorItem->setData(Qt::DisplayRole, pair.second);
//
//	table->setItem(i, 0, nameItem);
//	table->setItem(i, 1, colorItem);
//}
//table->resizeColumnToContents(0);
//table->horizontalHeader()->setStretchLastSection(true);
//
//QGridLayout *layout = new QGridLayout;
//layout->addWidget(table, 0, 0);
//
//setLayout(layout);
//
//setWindowTitle(tr("Color Editor Factory"));