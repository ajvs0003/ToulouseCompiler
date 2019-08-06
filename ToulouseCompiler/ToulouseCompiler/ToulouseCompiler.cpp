#include "ToulouseCompiler.h"
#include <QSurfaceFormat>
#include "OpenGLWidget.h"
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

void ToulouseCompiler::configurate()
{
	this->configuration_changePage();
	this->configuration_OutPut();
	this->configuration_codeEditor();
	this->configuration_opengl();
		
	//I take the stakedWidget and assign to a pointer for can manage later all the stuff that i will need
	stakedView = ui.stackedWidget;
	stakedView->setCurrentIndex(index);

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

void ToulouseCompiler::configuration_OutPut()
{
	OutPut = ui.OutPut;
	OutPut->setReadOnly(true);// lo pongo en solo modo lectura

	//Gestiono que el log reciba el output para que otras clases puedan trabajar con el
	Log::getInstancia()->setOutPut(OutPut);


}

void ToulouseCompiler::configuration_codeEditor()
{
	

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

	OpenGLWidget* openGLWindow = new OpenGLWidget();
	openGLWindow->setFormat(format);


	// Let's do the magic my dear TFG students :)
	QWidget* openglwidget = QWidget::createWindowContainer(openGLWindow);


	ui.opengl_layout->addWidget(openglwidget);

	openglwidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
