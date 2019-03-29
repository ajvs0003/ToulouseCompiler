#include "ToulouseCompiler.h"
#include <QSurfaceFormat>
#include "OpenGLWidget.h"
#include <QSizePolicy>
ToulouseCompiler::ToulouseCompiler(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QSurfaceFormat format;
	format.setSamples(16);

	// Para cambiar la versión de OpenGL cambiar aquí y en la clase OpenGLFunctions
	format.setVersion(4, 5);

	//OpenGLWidget* openGLWindow = new OpenGLWidget();
	OpenGLWidget::getInstance()->setFormat(format);

	// Let's do the magic my dear TFG students :)
	QWidget* openglwidget = QWidget::createWindowContainer(OpenGLWidget::getInstance());
	ui.opengl_layout->addWidget(openglwidget);
	openglwidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
