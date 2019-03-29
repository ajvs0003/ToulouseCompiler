#pragma once

#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>

#include "PagShaderProgram.h"
#include "OpenGLFunctions.h"
#include "Metodos_especiales.h"
#include "Pag3DGroup.h"
#include "PagCamera.h"
class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;

/**
 * Clase OpenGLWidget. Es un QWindow, no un QWidget que contiene un canvas OpenGL. 
 * Para poder incrustarla en otra ventana, se recomienda usar el m�todo QWidget::createWindowContainer(...)
 * Esta clase est� sacada del tutorial https://doc.qt.io/qt-5/qtgui-openglwindow-example.html
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

	static OpenGLWidget *getInstance();

	/**
		* @brief  Esta funci�n callback ser� llamada cada vez que el �rea de dibujo OpenGL deba ser redibujada.
	*/
	void refreshCallback();

	//La misi�n de este m�todo es preparar la escena para su visualizaci�n
	void prepareOpenGL();

public slots:
	void renderLater();
	void renderNow();

protected:
	bool event(QEvent *event) override;

	void exposeEvent(QExposeEvent *event) override;

private:
	bool needsInitialize = false;
	static OpenGLWidget *instance;

	bool m_animating;

	QOpenGLContext *m_context;
	QOpenGLPaintDevice *m_device;

	PagShaderProgram* shaderProgram;
	glm::mat4 viewMatrix, projMatrix;

	GLuint vao;
	GLuint vbo;
	GLuint ibo;
	float aspect;


	//CAMERA SETTINGS
	PagCamera *camera;
	glm::mat4 view;
	glm::mat4 mvp;


	void typePaint();



	//TESTING
	vector< Pag3DGroup> objetos;

	PagVAO dibujoPrueba;


	/**
		* @brief metodo que encapsula la creacion de los objetos de la escena
	*/
	void createObjects();


	/**
	* @brief  Esta funci�n gestiona el tipo de pintado que decirle al group que haga
	* @param  shader a usar
	* @param mode ,para diferenciar los shaders
*/
	void paintObjects(PagShaderProgram &shader, int mode);
};