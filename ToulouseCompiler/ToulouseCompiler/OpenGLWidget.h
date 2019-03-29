#pragma once

#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>

#include "PagShaderProgram.h"
#include "OpenGLFunctions.h"

class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;

/**
 * Clase OpenGLWidget. Es un QWindow, no un QWidget que contiene un canvas OpenGL. 
 * Para poder incrustarla en otra ventana, se recomienda usar el método QWidget::createWindowContainer(...)
 * Esta clase está sacada del tutorial https://doc.qt.io/qt-5/qtgui-openglwindow-example.html
 */
class OpenGLWidget : public QWindow, protected OpenGLFunctions
{
	Q_OBJECT
public:
	explicit OpenGLWidget(QWindow *parent = 0);
	~OpenGLWidget();

	virtual void render(QPainter *painter);
	virtual void render();

	void resize(int w, int h);

	virtual void initialize();

	void setAnimating(bool animating);

public slots:
	void renderLater();
	void renderNow();

protected:
	bool event(QEvent *event) override;

	void exposeEvent(QExposeEvent *event) override;

private:
	bool m_animating;

	QOpenGLContext *m_context;
	QOpenGLPaintDevice *m_device;

	PagShaderProgram* shaderProgram;
	glm::mat4 viewMatrix, projMatrix;

	GLuint vao;
	GLuint vbo;
	GLuint ibo;
	float aspect;
};