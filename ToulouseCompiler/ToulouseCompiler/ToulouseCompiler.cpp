#include "ToulouseCompiler.h"
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
	delete tabView;
	delete modePoints;
	delete modeLines;
	delete modeMaterial;
	delete modeTextures;
	delete modeTriangles;
	delete save;
	delete render;
	delete OutPut;
	delete openglwidget;
	delete table;
	
	
}





void ToulouseCompiler::handleToolActionPoints() {



	if (modeLines->isChecked()) {
		modeLines->setChecked(false);
	}
	if (modeTriangles->isChecked()) {
		modeTriangles->setChecked(false);
	}
	
	if (modeMaterial->isChecked()) {
		modeMaterial->setChecked(false);
	}

	if (modeTextures->isChecked()) {
		modeTextures->setChecked(false);
	}



	if (modePoints->isChecked()) {

		openGLWindow->changeTrial(0);

		Log::getInstancia()->warning("activado el modo puntos");
	}
	else {

		modePoints->setChecked(false);

	}

}


/******************** TABLE HANDLE********************/
void ToulouseCompiler::handleData(const dataForUniform &data)
{
	

	dataForUniform nuevo = data;
	uniforms.push_back(nuevo);


}

void ToulouseCompiler::handleEditData(const dataForUniform & data)
{
	dataForUniform nuevo = data;
	int id = findData(nuevo);

	if (id != -1) {
		uniforms.at(id) = nuevo;
	}
	else Log::getInstancia()->warning("This uniform didn't exist");
}

void ToulouseCompiler::handleRemoveData(const dataForUniform & data)
{
	dataForUniform nuevo = data;
	int id = findData(nuevo);

	if (id != -1) {
		uniforms.erase(
			std::remove_if(uniforms.begin(), uniforms.end(), [&](dataForUniform const & data) {return data.name == nuevo.name;})
			,uniforms.end());
	}
	else Log::getInstancia()->warning("This uniform didn't exist");


}

/********************END TABLE HANDLE********************/


void ToulouseCompiler::handleToolActionLines()
{


	if (modePoints->isChecked()) {
		modePoints->setChecked(false);
	}
	if (modeTriangles->isChecked()) {
		modeTriangles->setChecked(false);
	}

	if (modeMaterial->isChecked()) {
		modeMaterial->setChecked(false);
	}

	if (modeTextures->isChecked()) {
		modeTextures->setChecked(false);
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

	if (modeMaterial->isChecked()) {
		modeMaterial->setChecked(false);
	}

	if (modeTextures->isChecked()) {
		modeTextures->setChecked(false);
	}


	if (modeTriangles->isChecked()) {

		openGLWindow->changeTrial(2);

		Log::getInstancia()->warning("activado el modo triangulos");
	}
	else {

		modeTriangles->setChecked(false);

	}




}

void ToulouseCompiler::handleToolActionMaterial()
{
	if (modeLines->isChecked()) {
		modeLines->setChecked(false);
	}
	if (modePoints->isChecked()) {
		modePoints->setChecked(false);
	}
	if (modeTriangles->isChecked()) {
		modeTriangles->setChecked(false);
	}

	if (modeTextures->isChecked()) {
		modeTextures->setChecked(false);
	}


	if (modeMaterial->isChecked()) {

		openGLWindow->changeTrial(3);

		Log::getInstancia()->warning("activado el modo material");
	}
	else {

		modeMaterial->setChecked(false);

	}





	
}

void ToulouseCompiler::handleToolActionTextures()
{
	if (modeLines->isChecked()) {
		modeLines->setChecked(false);
	}
	if (modePoints->isChecked()) {
		modePoints->setChecked(false);
	}

	if (modeMaterial->isChecked()) {
		modeMaterial->setChecked(false);
	}

	if (modeTriangles->isChecked()) {
		modeTriangles->setChecked(false);
	}


	if (modeTextures->isChecked()) {

		openGLWindow->changeTrial(4);

		Log::getInstancia()->warning("activado el modo modeTextures");
	}
	else {

		modeTextures->setChecked(false);

	}
}

void ToulouseCompiler::handleToolActionOpen()
{
	uniforms.clear();
	configuration_tableWindow();


	openGLWindow->deleteUniforms();
	if (maybeSave()) {
		
		QString fileName = QFileDialog::getOpenFileName(this);
		if (!fileName.isEmpty())
			loadFile(fileName);
	}



}


bool ToulouseCompiler::maybeSave()

{
	if (!vertexShader->document()->isModified() && !fragmentShader->document()->isModified())
		return true;
	const QMessageBox::StandardButton ret
		= QMessageBox::warning(this, tr("Application"),
			tr("The document has been modified.\n"
				"Do you want to save your changes?"),
			QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
	switch (ret) {
	case QMessageBox::Save:
		return handleToolActionSave();
	case QMessageBox::Cancel:
		return false;
	default:
		break;
	}
	return true;
}

bool ToulouseCompiler::handleToolActionSave()
{
	if (curFile.isEmpty()) {
		return handleToolActionSaveAs();
	}
	else {
		return saveFile(curFile);
	}


}

bool ToulouseCompiler::handleToolActionSaveAs()
{
	QFileDialog dialog(this);
	dialog.setWindowModality(Qt::WindowModal);
	dialog.setAcceptMode(QFileDialog::AcceptSave);
	if (dialog.exec() != QDialog::Accepted)
		return false;
	return saveFile(dialog.selectedFiles().first());



	
}

void ToulouseCompiler::handleToolActionTableUniforms()
{

	


	table->show();







}

void ToulouseCompiler::handleToolActionRender()
{
	/*Log::getInstancia()->warning("Pulsado render");*/

	if (maybeSave()) {
		//resetear log
		OutPut->clear();
		

		if (!uniforms.empty()) {
			
			openGLWindow->setUniforms(uniforms);

		}

		
		openGLWindow->setPathShader(curFile.toStdString());
		openGLWindow->compile();
		
	}
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




void ToulouseCompiler::configurate()
{

	this->configuration_OutPut();

	
	this->configuration_codeEditor();
	this->configuration_opengl();
	this->configuration_ToolBar();
	

	this->configuration_tableWindow();

	statusBar->showMessage("Ready to start");


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


	modeMaterial = ui.actionModeMarterial;
	connect(modeMaterial, SIGNAL(triggered()), this, SLOT(handleToolActionMaterial()));

	modeTextures = ui.actionModeTexture;
	connect(modeTextures, SIGNAL(triggered()), this, SLOT(handleToolActionTextures()));


	load = ui.actionOpen;
	connect(load, SIGNAL(triggered()), this, SLOT(handleToolActionOpen()));


	save = ui.actionSave;
	connect(save, SIGNAL(triggered()), this, SLOT(handleToolActionSave()));

	saveAs = ui.actionSave_As;
	connect(saveAs, SIGNAL(triggered()), this, SLOT(handleToolActionSaveAs()));


	UniformTable = ui.actionUniform_Table;
	connect(UniformTable, SIGNAL(triggered()), this, SLOT(handleToolActionTableUniforms()));

	render = ui.actionRender;
	connect(render, SIGNAL(triggered()), this, SLOT(handleToolActionRender()));
}

void ToulouseCompiler::configuration_tableWindow()
{
	//**************widget add uniforms data***************//

	table = new tableUniforms(this);
	// connect your signal to the mainwindow slot
	connect(table, SIGNAL(newUniform(const dataForUniform &)), this, SLOT(handleData(const dataForUniform &)));
	connect(table, SIGNAL(editUniform(const dataForUniform &)), this, SLOT(handleEditData(const dataForUniform &)));
	connect(table, SIGNAL(removeUniform(const dataForUniform &)), this, SLOT(handleRemoveData(const dataForUniform &)));

	table->setWindowTitle("Uniform Data");
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
	//I take the qtabWidget and assign to a pointer for can manage later all the stuff that i will need
	

	tabView = ui.tabWidget;
	tabView->setCurrentIndex(0);
	
	tabView->setStyleSheet("QTabBar { font:bold 10pt; font-family: Arial; }");

	this->vertexShader = new CodeEditor();
	this->fragmentShader = new CodeEditor();

	
	//Para que funcionara el resize hay que tener en cuenta que los valores de maximumSize en qt designer esten en el "maximo" (16777215) 

	
	tabView->removeTab(0);
	tabView->insertTab(0, vertexShader, QString("Vertex Shader"));

	this->vertexShader->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



	tabView->removeTab(1);
	tabView->insertTab(1, fragmentShader, QString("Fragment Shader"));
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

	string aux = fileName.toStdString();
	aux = aux.substr(0, aux.find("-", 0));

	QString filename = QString::fromStdString(aux);

	QFile file(filename + "-vert.glsl");
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("Application"),
			tr("Cannot read file %1:\n%2.")
			.arg(QDir::toNativeSeparators(filename + "-vert.glsl"), file.errorString()));
		return;
	}

	QTextStream in(&file);

	QFile file2(filename + "-frag.glsl");
	if (!file2.open(QFile::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("Application"),
			tr("Cannot read file %1:\n%2.")
			.arg(QDir::toNativeSeparators(filename + "-frag.glsl"), file2.errorString()));
		return;
	}

	QTextStream in2(&file2);


#ifndef QT_NO_CURSOR
	QApplication::setOverrideCursor(Qt::WaitCursor);
#endif

	vertexShader->setPlainText(in.readAll());
	fragmentShader->setPlainText(in2.readAll());


#ifndef QT_NO_CURSOR
	QApplication::restoreOverrideCursor();
#endif
	file.close();
	file2.close();
	setCurrentFile(filename);
	statusBar->showMessage(tr("File loaded"), 2000);
}

bool ToulouseCompiler::saveFile(const QString &fileName)
		
	{
		QFile file(fileName + "-vert.glsl");
		if (!file.open(QFile::WriteOnly | QFile::Text)) {
			QMessageBox::warning(this, tr("Application"),
				tr("Cannot write file %1:\n%2.")
				.arg(QDir::toNativeSeparators(fileName),
					file.errorString()));
			return false;
		}
		QFile file2(fileName+"-frag.glsl");
		if (!file2.open(QFile::WriteOnly | QFile::Text)) {
			QMessageBox::warning(this, tr("Application"),
				tr("Cannot write file %1:\n%2.")
				.arg(QDir::toNativeSeparators(fileName),
					file2.errorString()));
			return false;
		}



		QTextStream vertex(&file);
		QTextStream fragment(&file2);


#ifndef QT_NO_CURSOR
		QApplication::setOverrideCursor(Qt::WaitCursor);
#endif

		vertex << vertexShader->toPlainText();
		fragment << fragmentShader->toPlainText();


#ifndef QT_NO_CURSOR
		QApplication::restoreOverrideCursor();
#endif
		file.close();
		file2.close();
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
		shownName = "untitled-vert.glsl";
	setWindowFilePath(shownName);
}

int ToulouseCompiler::findData(dataForUniform & data)
{
	for (int i = 0; i < uniforms.size(); i++) {
		if (data.id == uniforms.at(i).id)
			return i;
	}
	return -1;
}
