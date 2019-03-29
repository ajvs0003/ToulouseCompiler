#include "OpenGLWidget.h"

#include <QtCore/QCoreApplication>

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>

#include <QWidget>
#include <QDebug>

#include <gtc/matrix_transform.hpp>

OpenGLWidget::OpenGLWidget(QWindow *parent)
	: QWindow(parent)
	, m_animating(false)
	, m_context(0)
	, m_device(0)
{
	setSurfaceType(QWindow::OpenGLSurface);

	qDebug() << "MyOpenGLWidget constructor";
}

OpenGLWidget::~OpenGLWidget()
{
	delete m_device;
}

void OpenGLWidget::render(QPainter *painter)
{
	Q_UNUSED(painter);
}

void OpenGLWidget::initialize()
{
	qDebug() << "Inicializando OpenGL" << endl;
	qDebug() << "Nombre GPU    : " << (const char*)glGetString(GL_RENDERER);
	qDebug() << "Fabricante    : " << (const char*)glGetString(GL_VENDOR);
	qDebug() << "Version OpenGL: " << (const char*)glGetString(GL_VERSION);
	qDebug() << "Version GLSL  : " << (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);

	shaderProgram = new PagShaderProgram();
	shaderProgram->setGLFunctions(m_context);
	shaderProgram->createShaderProgram("Resources/points-1");

	aspect = float(this->width()) / this->height();
	viewMatrix = glm::lookAt(
		glm::vec3(5, 5, 5), 
		glm::vec3(0, 0, 0), 
		glm::vec3(0, 1, 0)
	);
	projMatrix = glm::perspective(95.0f, aspect, 1.0f, 100.0f);
}

void OpenGLWidget::render()
{
	if (!m_device)
		m_device = new QOpenGLPaintDevice;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	m_device->setSize(size() * devicePixelRatio());
	m_device->setDevicePixelRatio(devicePixelRatio());

	qDebug() << "Rendering";

	GLfloat vertices[] = { -1.0, -1.0,  1.0,
						   1.0, -1.0,  1.0,
						   1.0,  1.0,  1.0,
						  -1.0,  1.0,  1.0,
						  -1.0, -1.0,  -1.0,
						   1.0, -1.0,  -1.0,
						   1.0,  1.0,  -1.0,
						  -1.0,  1.0,  -1.0 };

	GLuint indices[] = { 0,1,2,3,4,5,6,7 };

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);

	glBindVertexArray(vao);

	glm::mat4 modelMatrix(1);

	shaderProgram->use();
	shaderProgram->setUniform("vColor", { 0.1, 0.5, 0.9 });
	shaderProgram->setUniform("mModelViewProj", projMatrix * viewMatrix * modelMatrix);
	shaderProgram->setUniform("pointSize", 100.0f);

	glDrawElements(GL_POINTS, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
}

void OpenGLWidget::resize(int w, int h)
{
	if (m_context)
	{
		glViewport(0, 0, w, h);
		aspect = w / (float)h;
		qDebug() << "Resizing: " << w << " x " << h;
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