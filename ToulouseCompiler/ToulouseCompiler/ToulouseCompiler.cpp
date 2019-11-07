#include "ToulouseCompiler.h"
#include <QSurfaceFormat>

#include <QSizePolicy>


ToulouseCompiler::ToulouseCompiler(QWidget* parent)
	: QMainWindow(parent)
{



	ui.setupUi(this);


	this->setWindowIcon(QIcon(":/img/Resources/img/icono.png"));

	this->configurate();


}
void ToulouseCompiler::changeEvent(QEvent* event)
{
	if (event->type() == QEvent::LanguageChange)
	{
		ui.retranslateUi(this);
	}

	QWidget::changeEvent(event);
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
		openGLWindow->deleteUniforms();
		/*Log::getInstancia()->warning("activado el modo puntos");*/
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

	if (modeMaterial->isChecked()) {
		modeMaterial->setChecked(false);
	}

	if (modeTextures->isChecked()) {
		modeTextures->setChecked(false);
	}


	if (modeLines->isChecked()) {

		openGLWindow->changeTrial(1);
		openGLWindow->deleteUniforms();
		/*Log::getInstancia()->warning("activado el modo lineas");*/
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
		openGLWindow->deleteUniforms();
		/*Log::getInstancia()->warning("activado el modo triangulos");*/
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
		openGLWindow->deleteUniforms();
		//Log::getInstancia()->warning("activado el modo material");
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
		openGLWindow->deleteUniforms();
		/*Log::getInstancia()->warning("activado el modo modeTextures");*/
	}
	else {

		modeTextures->setChecked(false);

	}
}

void ToulouseCompiler::handleToolActionPeon()
{
	if (copa->isChecked()) {
		copa->setChecked(false);
	}
	if (joy->isChecked()) {
		joy->setChecked(false);
	}


	if (peon->isChecked()) {

		openGLWindow->changeObject(0);

		//Log::getInstancia()->warning("activado el modo material");
	}
	else {

		peon->setChecked(false);

	}


}

void ToulouseCompiler::handleToolActionCopa()
{
	if (peon->isChecked()) {
		peon->setChecked(false);
	}
	if (joy->isChecked()) {
		joy->setChecked(false);
	}





	if (copa->isChecked()) {

		openGLWindow->changeObject(1);

		//Log::getInstancia()->warning("activado el modo material");
	}
	else {

		copa->setChecked(false);

	}
}

void ToulouseCompiler::handleToolActionJoy()
{
	if (copa->isChecked()) {
		copa->setChecked(false);
	}
	if (peon->isChecked()) {
		peon->setChecked(false);
	}





	if (joy->isChecked()) {

		openGLWindow->changeObject(2);

		//Log::getInstancia()->warning("activado el modo material");
	}
	else {

		joy->setChecked(false);

	}
}


void ToulouseCompiler::handleToolActionNew()
{

	configuration_tableWindow();



	if (maybeSave()) {
		vertexShader->clear();
		fragmentShader->clear();

		setCurrentFile(QString());
	}



}

void ToulouseCompiler::handleToolActionOpen()
{

	configuration_tableWindow();



	if (maybeSave()) {

		QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
			QDir::homePath(),
			tr("All files (*.*)"));





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

	/*dialog.setDirectory(QDir());*/

	dialog.setWindowModality(Qt::WindowModal);

	dialog.setAcceptMode(QFileDialog::AcceptSave);

	if (dialog.exec() != QDialog::Accepted)
		return false;

	return saveFile(dialog.selectedFiles().first());//coge el primer archivo que seleccionas




}

void ToulouseCompiler::handleToolActionTableUniforms()
{
	table->show();
}

void ToulouseCompiler::on_Spanish_clicked()
{
	qApp->removeTranslator(&englishTranslator);
	// change language to spanish language
	qApp->installTranslator(&spanishTranslator);
	spanishButton->setChecked(true);
	englishButton->setChecked(false);
	this->configuration_tableWindow();
}

void ToulouseCompiler::on_English_clicked()
{
	qApp->removeTranslator(&spanishTranslator);
	// change language to english language
	qApp->installTranslator(&englishTranslator);
	englishButton->setChecked(true);
	spanishButton->setChecked(false);
	this->configuration_tableWindow();
}

void ToulouseCompiler::handleToolActionRender()
{
	/*Log::getInstancia()->warning("Pulsado render");*/

	if (maybeSave()) {
		//resetear log
		OutPut->clear();


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


	this->configuration_translators();

	statusBar->showMessage("Ready to start");


}




void ToulouseCompiler::configuration_ToolBar()
{

	//signals for manage the action in the toolbar

	ui.mainToolBar->setIconSize(QSize(24, 24));

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


	peon = ui.actionPeon;
	peon->setChecked(true);
	connect(peon, SIGNAL(triggered()), this, SLOT(handleToolActionPeon()));


	copa = ui.actioncopa;
	connect(copa, SIGNAL(triggered()), this, SLOT(handleToolActionCopa()));


	joy = ui.actionjoy;
	connect(joy, SIGNAL(triggered()), this, SLOT(handleToolActionJoy()));





	newFile = ui.actionNew;
	connect(newFile, SIGNAL(triggered()), this, SLOT(handleToolActionNew()));


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


void ToulouseCompiler::configuration_translators() {


	spanishButton = ui.actionEspanol;
	connect(spanishButton, SIGNAL(triggered()), this, SLOT(on_Spanish_clicked()));

	englishButton = ui.actionEnglish;
	connect(englishButton, SIGNAL(triggered()), this, SLOT(on_English_clicked()));

	if (spanishTranslator.load(":/translattions/Languages/toulousecompiler_es.qm"))
		qDebug() << "successfully load toulousecompiler_es.qm file.";
	else
		qDebug() << "problem in load toulousecompiler_es.qm file.";

	if (englishTranslator.load(":/translattions/Languages/toulousecompiler_en.qm"))
		qDebug() << "successfully load toulousecompiler_es.qm file.";
	else
		qDebug() << "problem in load toulousecompiler_en.qm file.";

	// format systems language
	QString defaultLocale = QLocale::system().name();
	defaultLocale.truncate(defaultLocale.lastIndexOf('_'));

	if (defaultLocale == "es")
	{

		qApp->removeTranslator(&englishTranslator);
		// change language to spanish language
		qApp->installTranslator(&spanishTranslator);


		spanishButton->setChecked(true);
		englishButton->setChecked(false);
	}
	else {
		qApp->removeTranslator(&spanishTranslator);
		// change language to english language
		qApp->installTranslator(&englishTranslator);

		englishButton->setChecked(true);
		spanishButton->setChecked(false);
	}





}

void ToulouseCompiler::handleData(const QVector<dataForUniform>& data)
{


	openGLWindow->setUniforms(data);



}


void ToulouseCompiler::configuration_tableWindow()
{
	//**************widget add uniforms data***************//

	table = new tableUniforms(this);
	table->setWindowTitle("Uniforms Table");

	connect(table, SIGNAL(addUniforms(const QVector<dataForUniform>&)), this, SLOT(handleData(const QVector<dataForUniform>&)));


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

	VertexHighlighter = new Highlighter(vertexShader->document());
	FragmentHighlighter = new Highlighter(fragmentShader->document());
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







void ToulouseCompiler::loadFile(const QString& fileName)

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

bool ToulouseCompiler::saveFile(const QString& fileName)

{
	QFile file(fileName + "-vert.glsl");
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("Application"),
			tr("Cannot write file %1:\n%2.")
			.arg(QDir::toNativeSeparators(fileName),
				file.errorString()));
		return false;
	}
	QFile file2(fileName + "-frag.glsl");
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

void ToulouseCompiler::setCurrentFile(const QString& fileName)
{
	curFile = fileName;

	vertexShader->document()->setModified(false);

	setWindowModified(false);

	QString shownName = curFile;
	if (curFile.isEmpty())
		shownName = "untitled-vert.glsl";
	setWindowFilePath(shownName);
}


