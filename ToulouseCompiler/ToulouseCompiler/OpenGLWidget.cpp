#include "OpenGLWidget.h"

#include <QtCore/QCoreApplication>

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>

#include <QWidget>
#include <QDebug>

#include <gtc/matrix_transform.hpp>

#include "PagEnumerations.h"

OpenGLWidget * OpenGLWidget::instance = nullptr;


OpenGLWidget * OpenGLWidget::getInstance()
{
	if (!instance) {
		instance = new OpenGLWidget();
	}
	return instance;
}

void OpenGLWidget::refreshCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	qDebug() << "Refresh callback called by Renderer";


	if(firstCompile)this->Paint();

}


OpenGLWidget::OpenGLWidget(QWindow *parent)
	: QWindow(parent)
	, m_animating(false)
	, m_context(0)
	, m_device(0)
{
	setSurfaceType(QWindow::OpenGLSurface);

	qDebug() << "MyOpenGLWidget constructor";


	shaderProgram = new PagShaderProgram();



}

OpenGLWidget::~OpenGLWidget()
{
	this->glDeleteProgram(shaderProgram->getHandler());
	delete m_device;
}

void OpenGLWidget::render(QPainter *painter)
{
	Q_UNUSED(painter);
}

void  OpenGLWidget::prepareOpenGL()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);


	glPrimitiveRestartIndex(0xFFFFFFFF);
	glEnable(GL_PRIMITIVE_RESTART);


	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_MULTISAMPLE);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);



	/*createLights();*/



	createObjects();


}




void OpenGLWidget::changeTrial(int nuevo)
{
	typeTrial = nuevo;

}

void OpenGLWidget::setPathShader(string path)
{
	shaderPath = path;

}

void OpenGLWidget::setUniforms(vector<dataForUniform> _uniforms)
{
	uniforms = _uniforms;
}

void OpenGLWidget::compile()
{
	firstCompile = true;

	Log::getInstancia()->success("Inicializando OpenGL");

	Log::getInstancia()->success("Nombre GPU    : " + (string)(const char*)glGetString(GL_RENDERER));
	Log::getInstancia()->success("Fabricante    : " + (string)(const char*)glGetString(GL_VENDOR));
	Log::getInstancia()->success("Version OpenGL: " + (string)(const char*)glGetString(GL_VERSION));
	Log::getInstancia()->success("Version GLSL  : " + (string)(const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));



	this->glDeleteProgram(shaderProgram->getHandler());

	shaderProgram = new PagShaderProgram();
	
	
	chargeShader();

	

	

	renderNow();

	

}

void OpenGLWidget::chargeUniforms()
{
	for (int i = 0; i < uniforms.size(); i++) {


		if (uniforms.at(i).type == "boolean") {

			//shader.setUniform("pointSize", 7.0f);
			if (uniforms.at(i).value == "true")shaderProgram->setUniform(uniforms.at(i).name, true);
			else if (uniforms.at(i).value == "false")shaderProgram->setUniform(uniforms.at(i).name, false);
			else Log::getInstancia()->error("uniform bool value incorrect");

		}
		else if (uniforms.at(i).type == "vec3") {
			//shader.setUniform("vColor", glm::vec3(1.0f, 0.0f, 0.0f));
			std::stringstream val(uniforms.at(i).value);
			std::string segment;
			std::vector<float> seglist;

			while (std::getline(val, segment, ','))
			{
				seglist.push_back(std::stof(segment));
			}

			if (seglist.size() <= 3 && seglist.size() > 0) {


				glm::vec3 vector(seglist.at(0), seglist.at(1) , seglist.at(2) );

				


				shaderProgram->setUniform(uniforms.at(i).name, vector);


			}
			else Log::getInstancia()->error("uniform vec3 value incorrect");



		}
		else if (uniforms.at(i).type == "vec4") {
			std::stringstream val(uniforms.at(i).value);
			std::string segment;
			std::vector<GLfloat> seglist;

			while (std::getline(val, segment, ','))
			{
				seglist.push_back(std::stof(segment));
			}

			if (seglist.size() <= 4 && seglist.size() > 0) {
				glm::vec4 vector(seglist.at(0), seglist.at(1), seglist.at(2), seglist.at(3));

				shaderProgram->setUniform(uniforms.at(i).name, vector);


			}
			else Log::getInstancia()->error("uniform vec4 value incorrect");


		}

		else if (uniforms.at(i).type == "float") {

			GLfloat val = std::stof(uniforms.at(i).value);
			shaderProgram->setUniform(uniforms.at(i).name, val);

		}
		else if (uniforms.at(i).type == "int") {

			GLint val = std::stoi(uniforms.at(i).value);
			shaderProgram->setUniform(uniforms.at(i).name, val);

		}
		else {
			Log::getInstancia()->error("uniform type incorrect");
		}







	}











}

void OpenGLWidget::mouseMoveEvent(QMouseEvent * ev)
{
	this->posX = ev->x();
	this->posY = ev->y();
	emit Mouse_Pos();

}

void OpenGLWidget::mousePressEvent(QMouseEvent * ev)
{

	if (ev->button() == Qt::MidButton)   // Middle button...
	{

		emit Mouse_Pressed();
	}


}

void OpenGLWidget::leaveEvent(QMouseEvent *)
{

	emit Mouse_Left();
}



void OpenGLWidget::mouseReleaseEvent(QMouseEvent *e)
{
	if (e->button() == Qt::MidButton)   // Middle button...
	{

		emit Mouse_Released();
	}
}



void OpenGLWidget::chargeShader()
{

	shaderProgram->setGLFunctions(m_context);

	if (modeTrial) {
		switch (typeTrial) {
		case typePaint::points:

			//We want to try the shaders for poitns
			shaderProgram->createShaderProgram("./Shaders/pointShader");//"Resources/points-1"
			break;

		case typePaint::wire:


			shaderProgram->createShaderProgram("./Shaders/wireShader");//"Resources/points-1"
			break;
		case typePaint::triangle:

			shaderProgram->createShaderProgram("./Shaders/triangleShader");//"Resources/points-1"
			break;
		case typePaint::material:

			//shaderProgram->createShaderProgram("./Shaders/triangleShader");//"Resources/points-1"
			break;
		case typePaint::textures:

			//We want to try the shaders for poitns
			//shaderProgram->createShaderProgram("./Shaders/triangleShader");//"Resources/points-1"
			break;
		}

	}
	else {
		//Here we use the shader that the user wrote



		shaderProgram->createShaderProgram(shaderPath);
		
	}


}


void OpenGLWidget::initialize()
{



	Log::getInstancia()->escribir("Inicializando OpenGL");

	Log::getInstancia()->escribir("Nombre GPU    : " + (string)(const char*)glGetString(GL_RENDERER));
	Log::getInstancia()->escribir("Fabricante    : " + (string)(const char*)glGetString(GL_VENDOR));
	Log::getInstancia()->escribir("Version OpenGL: " + (string)(const char*)glGetString(GL_VERSION));
	Log::getInstancia()->escribir("Version GLSL  : " + (string)(const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));


	

	//CAMARA SETTINGS

	glm::vec3 look(0.0f, 6.0f, 0.0f);

	glm::vec3 pos(0.0f, 6.f, 30.0f);
	camera = new PagCamera(pos, look, 90);

	prepareOpenGL();



	aspect = float(this->width()) / this->height();

	h = this->height();
	w = this->width();


	viewMatrix = camera->getWorldToViewMatrix();


	projMatrix = camera->getWorldToProjecMatrix(this->width(), this->height());
}






void OpenGLWidget::render()
{
	if (!m_device)
		m_device = new QOpenGLPaintDevice;

	refreshCallback();

	m_device->setSize(size() * devicePixelRatio());
	m_device->setDevicePixelRatio(devicePixelRatio());

	/*Log::getInstancia()->success("Rendering");*/


}

void OpenGLWidget::resize(int w, int h)
{
	if (m_context)
	{
		this->h = h;
		this->w = w;
		glViewport(0, 0, w, h);
		aspect = w / (float)h;
		/*Log::getInstancia()->success("Resizing: "+ std::to_string(w) +" X: "+ std::to_string(h));*/
		qDebug() << "Resizing: " << w << " X : " << h;

	}
}

void OpenGLWidget::renderLater()
{
	requestUpdate();
}

bool OpenGLWidget::event(QEvent *event)
{
	switch (event->type()) {
	case QEvent::Resize:
		resize(width(), height());
		return true;
	case QEvent::UpdateRequest:
		renderNow();
		return true;
	default:
		return QWindow::event(event);
	}
}

void OpenGLWidget::exposeEvent(QExposeEvent *event)
{
	Q_UNUSED(event);

	if (isExposed())
		renderNow();
}



void OpenGLWidget::Paint()
{


	//Un vector con los uniforms que cuando ya temga el modo de pintura agregue los uniforms que el usuario relleno



	switch (typeTrial) {
	case typePaint::points:

		glDisable(GL_BLEND);
		shaderProgram->use();
		chargeUniforms();
		paintObjects(*shaderProgram, 0);
		break;

	case typePaint::wire:

		glDisable(GL_BLEND);
		shaderProgram->use();
		chargeUniforms();
		paintObjects(*shaderProgram, 1);

		break;
	case typePaint::triangle:

		glDisable(GL_BLEND);
		shaderProgram->use();
		chargeUniforms();
		paintObjects(*shaderProgram, 2);
		break;
	case typePaint::material:
		glEnable(GL_BLEND);
		shaderProgram->use();
		chargeUniforms();
		for (unsigned int i = 0; i < luces.size(); i++) {

			if (i == 0) glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			else glBlendFunc(GL_SRC_ALPHA, GL_ONE);

			luces.at(i).aplicateShader(shaderProgram, camera->getWorldToViewMatrix());

			paintObjects(*shaderProgram, 3);
		}

		break;
	case typePaint::textures:
		glEnable(GL_BLEND);
		shaderProgram->use();
		chargeUniforms();

		for (unsigned int i = 0; i < luces.size(); i++) {

			if (i == 0) glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			else glBlendFunc(GL_SRC_ALPHA, GL_ONE);

			luces.at(i).aplicateShader(shaderProgram, camera->getWorldToViewMatrix());


			paintObjects(*shaderProgram, 4);


		}

		break;
	}

	
}





void OpenGLWidget::createObjects()
{
	std::vector <glm::vec2> dataTxt;

	Pag3DGroup* ob;
	ob = new Pag3DGroup();




	dataTxt = Metodos_especiales::lecturaFichero(dataTxt, ":/obj/Resources/Objects/peon.txt");
	PagRevolutionObject* peon;

	peon = new PagRevolutionObject(this, dataTxt, 2, 60);
	peon->translate(glm::vec3(0.f, 0.01f, 0.f));




	ob->insertObject(peon);

	ob->translate(glm::vec3(0.f, 0.f, 0.f));
	objetos.push_back(*ob);




}




void OpenGLWidget::paintObjects(PagShaderProgram &shader, int mode) {
	switch (mode)
	{
	case 0://Modo puntos
		for (unsigned int i = 0; i < objetos.size(); i++) {
			objetos.at(i).DrawAsPoints(shader, objetos.at(i).getModelMatrix(), camera->getWorldToViewMatrix(),
				camera->getWorldToProjecMatrix(width(), height()));
		}
		break;

	case 1://Modo lineas
		for (unsigned int i = 0; i < objetos.size(); i++) {
			objetos.at(i).DrawAsLines(shader, glm::mat4(1), camera->getWorldToViewMatrix(),
				camera->getWorldToProjecMatrix(width(), height()));
		}


		break;

	case 2://Modo triangulos ver orden indices
		for (unsigned int i = 0; i < objetos.size(); i++) {
			objetos.at(i).DrawAsTriangles(shader, glm::mat4(1), camera->getWorldToViewMatrix(),
				camera->getWorldToProjecMatrix(width(), height()));
		}

		break;




	case 3://Modo triangulos para shader luces y materiales
		for (unsigned int i = 0; i < objetos.size(); i++) {
			objetos.at(i).DrawAsTrianglesWithLights(shader, objetos.at(i).getModelMatrix(), camera->getWorldToViewMatrix(),
				camera->getWorldToProjecMatrix(width(), height()), false);
		}

		break;
	case 4://Modo triangulos para shader luces y materiales

		for (unsigned int i = 0; i < objetos.size(); i++) {
			objetos.at(i).DrawAsTrianglesWithLights(shader, objetos.at(i).getModelMatrix(), camera->getWorldToViewMatrix(),
				camera->getWorldToProjecMatrix(width(), height()), true);

		}



		break;


	default:
		break;
	}




}





void OpenGLWidget::renderNow()
{
	if (!isExposed())
		return;

	bool needsInitialize = false;

	if (!m_context) {
		m_context = new QOpenGLContext(this);
		m_context->setFormat(requestedFormat());
		m_context->create();

		needsInitialize = true;

	}

	m_context->makeCurrent(this);


	if (needsInitialize) {
		initializeOpenGLFunctions();
		initialize();
	}

	render();

	m_context->swapBuffers(this);

	if (m_animating)
		renderLater();
}

void OpenGLWidget::setAnimating(bool animating)
{
	m_animating = animating;

	if (animating)
		renderLater();
}