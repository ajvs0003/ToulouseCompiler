#pragma once

// Para cambiar la versi�n de OpenGL cambiar aqu� y en la clase MainWindow
#include <qopenglfunctions_4_5_core>
using GLCurrentVersion = QOpenGLFunctions_4_5_Core;

class OpenGLFunctions : public GLCurrentVersion
{

public:
	OpenGLFunctions() {};
	~OpenGLFunctions() {};

};

