#include "ToulouseCompiler.h"
#include <QSurfaceFormat>

#include <QSizePolicy>
#include <algorithm>

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
	delete Debug;
	delete openglwidget;
	delete table;


}



void ToulouseCompiler::checkModeOpenGL()
{
	if (actionsButtons.at(Toulouse::MODE_POINTS)->isChecked())actionsButtons.at(Toulouse::MODE_POINTS)->setChecked(false);
	if (actionsButtons.at(Toulouse::MODE_LINES)->isChecked())actionsButtons.at(Toulouse::MODE_LINES)->setChecked(false);
	if (actionsButtons.at(Toulouse::MODE_TRIANGLES)->isChecked())actionsButtons.at(Toulouse::MODE_TRIANGLES)->setChecked(false);
	if (actionsButtons.at(Toulouse::MODE_MATERIALS)->isChecked())actionsButtons.at(Toulouse::MODE_MATERIALS)->setChecked(false);
	if (actionsButtons.at(Toulouse::MODE_TEXTURES)->isChecked())actionsButtons.at(Toulouse::MODE_TEXTURES)->setChecked(false);


}

void ToulouseCompiler::checkObject()
{
	if (actionsButtons.at(Toulouse::CUP)->isChecked())actionsButtons.at(Toulouse::CUP)->setChecked(false);
	if (actionsButtons.at(Toulouse::JOY)->isChecked())actionsButtons.at(Toulouse::JOY)->setChecked(false);
	if (actionsButtons.at(Toulouse::PAWN)->isChecked())actionsButtons.at(Toulouse::PAWN)->setChecked(false);
}




void ToulouseCompiler::handleToolActionPoints() {


	checkModeOpenGL();
	actionsButtons.at(Toulouse::MODE_POINTS)->setChecked(true);
	openGLWindow->changeTrial(0);
	openGLWindow->deleteUniforms();
	/*Log::getInstancia()->warning("activado el modo puntos");*/



}
void ToulouseCompiler::handleToolActionLines()
{

	checkModeOpenGL();
	actionsButtons.at(Toulouse::MODE_LINES)->setChecked(true);
	openGLWindow->changeTrial(1);
	openGLWindow->deleteUniforms();


}

void ToulouseCompiler::handleToolActionTriangles()
{
	checkModeOpenGL();
	actionsButtons.at(Toulouse::MODE_TRIANGLES)->setChecked(true);
	openGLWindow->changeTrial(2);
	openGLWindow->deleteUniforms();
	/*Log::getInstancia()->warning("activado el modo triangulos");*/






}

void ToulouseCompiler::handleToolActionMaterial()
{

	checkModeOpenGL();
	actionsButtons.at(Toulouse::MODE_MATERIALS)->setChecked(true);
	openGLWindow->changeTrial(3);
	openGLWindow->deleteUniforms();

}

void ToulouseCompiler::handleToolActionTextures()
{
	checkModeOpenGL();
	actionsButtons.at(Toulouse::MODE_TEXTURES)->setChecked(true);
	openGLWindow->changeTrial(4);
	openGLWindow->deleteUniforms();

}

void ToulouseCompiler::handleToolActionPeon()
{
	checkObject();
	actionsButtons.at(Toulouse::PAWN)->setChecked(true);
	openGLWindow->changeObject(0);

}

void ToulouseCompiler::handleToolActionCopa()
{


	checkObject();
	actionsButtons.at(Toulouse::CUP)->setChecked(true);
	openGLWindow->changeObject(1);


}

void ToulouseCompiler::handleToolActionJoy()
{
	checkObject();
	actionsButtons.at(Toulouse::JOY)->setChecked(true);
	openGLWindow->changeObject(2);
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

void ToulouseCompiler::Spanish_clicked()
{
	qApp->removeTranslator(&englishTranslator);
	// change language to spanish language
	qApp->installTranslator(&spanishTranslator);
	spanishButton->setChecked(true);
	englishButton->setChecked(false);
	this->configuration_tableWindow();
}

void ToulouseCompiler::English_clicked()
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
		Debug->clear();
		statusBar->showMessage("Compiling....");

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

	this->configuration_Debug();


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
	ui.actionPoints->setChecked(true);
	ui.actionPeon->setChecked(true);

	actionsButtons.insert(pair<int, QAction*>(Toulouse::MODE_POINTS, ui.actionPoints));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::MODE_LINES, ui.actionLines));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::MODE_TRIANGLES, ui.actiontriangles));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::MODE_MATERIALS, ui.actionModeMarterial));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::MODE_TEXTURES, ui.actionModeTexture));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::PAWN, ui.actionPeon));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::CUP, ui.actioncopa));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::JOY, ui.actionjoy));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::UNIFORM_TABLE, ui.actionUniform_Table));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::NEW_FILE, ui.actionNew));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::LOAD, ui.actionOpen));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::SAVE, ui.actionSave));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::SAVE_AS, ui.actionSave_As));
	actionsButtons.insert(pair<int, QAction*>(Toulouse::RENDER, ui.actionRender));

	connect(ui.actionLines, SIGNAL(triggered()), this, SLOT(handleToolActionLines()));
	connect(ui.actionPoints, SIGNAL(triggered()), this, SLOT(handleToolActionPoints()));
	connect(ui.actiontriangles, SIGNAL(triggered()), this, SLOT(handleToolActionTriangles()));
	connect(ui.actionModeMarterial, SIGNAL(triggered()), this, SLOT(handleToolActionMaterial()));
	connect(ui.actionModeTexture, SIGNAL(triggered()), this, SLOT(handleToolActionTextures()));
	connect(ui.actionPeon, SIGNAL(triggered()), this, SLOT(handleToolActionPeon()));
	connect(ui.actioncopa, SIGNAL(triggered()), this, SLOT(handleToolActionCopa()));
	connect(ui.actionjoy, SIGNAL(triggered()), this, SLOT(handleToolActionJoy()));
	connect(ui.actionUniform_Table, SIGNAL(triggered()), this, SLOT(handleToolActionTableUniforms()));
	connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(handleToolActionNew()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(handleToolActionOpen()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(handleToolActionSave()));
	connect(ui.actionSave_As, SIGNAL(triggered()), this, SLOT(handleToolActionSaveAs()));
	connect(ui.actionRender, SIGNAL(triggered()), this, SLOT(handleToolActionRender()));


}


void ToulouseCompiler::configuration_translators() {


	spanishButton = ui.actionEspanol;
	connect(spanishButton, SIGNAL(triggered()), this, SLOT(Spanish_clicked()));

	englishButton = ui.actionEnglish;
	connect(englishButton, SIGNAL(triggered()), this, SLOT(English_clicked()));

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
		qApp->installTranslator(&spanishTranslator);
		spanishButton->setChecked(true);
		englishButton->setChecked(false);
	}
	else {
		qApp->installTranslator(&englishTranslator);
		englishButton->setChecked(true);
		spanishButton->setChecked(false);
	}

	this->configuration_tableWindow();
}



void ToulouseCompiler::handleData(const QVector<dataForUniform>& data)
{


	openGLWindow->setUniforms(data);



}


void ToulouseCompiler::configuration_tableWindow()
{
	//**************widget add uniforms data***************//

	table = new tableUniforms(this);
	table->setWindowTitle(tr("Uniforms Table"));

	connect(table, SIGNAL(addUniforms(const QVector<dataForUniform>&)), this, SLOT(handleData(const QVector<dataForUniform>&)));


}


void ToulouseCompiler::configuration_Debug()
{
	Debug = ui.OutPut;

	Debug->setReadOnly(true);// lo pongo en solo modo lectura

	//Gestiono que el log reciba el output para que otras clases puedan trabajar con el
	Log::getInstancia()->setOutPut(Debug);

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


	// Se le pasa al widget el objeto OpenGLWidget(Renderer)
	openglwidget = QWidget::createWindowContainer(openGLWindow);
	ui.opengl_layout->addWidget(openglwidget);
	openglwidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


	//Para la configuracion de los movimientos de la camara
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


