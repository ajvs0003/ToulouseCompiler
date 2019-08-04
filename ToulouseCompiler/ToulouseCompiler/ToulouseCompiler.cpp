#include "ToulouseCompiler.h"
#include <QSurfaceFormat>
#include "OpenGLWidget.h"
#include <QSizePolicy>
#include <CodeEditor.h>

ToulouseCompiler::ToulouseCompiler(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);



	this->configuration_changePage();
	this->configuration_OutPut();




	//I take the stakedWidget and assign to a pointer for can manage later all the stuff that i will need
	editor = ui.stackedWidget;
	editor->setCurrentIndex(index);
	
	



	QSurfaceFormat format;
	format.setSamples(16);

	// Para cambiar la versión de OpenGL cambiar aquí y en la clase OpenGLFunctions
	format.setVersion(4, 5);

	
	//CodeEditor *editor=new CodeEditor(ui.VertexShader);
	//editor->setGeometry(0, 0, 541, 587);
	//editor->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	CodeEditor *editor = new CodeEditor();
	
	ui.vertexLayout->addWidget(editor);
	editor->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);




	OpenGLWidget* openGLWindow = new OpenGLWidget();
	openGLWindow->setFormat(format);

	
	// Let's do the magic my dear TFG students :)
	QWidget* openglwidget = QWidget::createWindowContainer(openGLWindow);
	

	ui.opengl_layout->addWidget(openglwidget);

	openglwidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void ToulouseCompiler::handleButton() {

	if (index == 0) {
		index = 1;
		changePage->setText("Vertex Shader");
	}
	else {
		index = 0;
		changePage->setText("Fragment Shader");
	}

	editor->setCurrentIndex(index);
}

void ToulouseCompiler::configuration_changePage()
{
	//Take the button that i design in de editor and conect the signal for can handle the click event, and change the page in the stakec view
	changePage = ui.changePage;
	connect(changePage, SIGNAL(released()), this, SLOT(handleButton()));

	
	changePage->setText("Fragment Shader");
}

void ToulouseCompiler::configuration_OutPut()
{
	OutPut = ui.OutPut;
}
