#pragma once

#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>
#include "PagShaderProgram.h"
#include "OpenGLFunctions.h"
#include "Metodos_especiales.h"
#include "Pag3DGroup.h"
#include "PagCamera.h"
#include "PagLightSource.h"
#include <string>
#include <QMouseEvent>
#include <QEvent>


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
	//CAMERA SETTINGS
	PagCamera *camera;
	int w, h;
	int posX, posY;

	explicit OpenGLWidget(QWindow *parent = 0);
	~OpenGLWidget();

	virtual void render(QPainter *painter);

	virtual void render();

	void resize(int w, int h);

	virtual void initialize();

	void setAnimating(bool animating);

	static OpenGLWidget *getInstance();

	/**
		* @brief  Esta función callback será llamada cada vez que el área de dibujo OpenGL deba ser redibujada.
	*/
	void refreshCallback();

	//La misión de este método es preparar la escena para su visualización
	void prepareOpenGL();


	void changeTrial(int nuevo) {
		
		typeTrial = nuevo;
	}
	
	void compile();


	//EVENTS for mouse


	void mouseMoveEvent(QMouseEvent *ev);
	void mousePressEvent(QMouseEvent *ev);
	void leaveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *e);

	

	

signals:
	void Mouse_Pressed();
	void Mouse_Released();
	void Mouse_Pos();
	void Mouse_Left();

public slots:
	void renderLater();
	void renderNow();




protected:
	bool event(QEvent *event) override;

	void exposeEvent(QExposeEvent *event) override;

private:


	//QT DATA

	bool needsInitialize = false;
	static OpenGLWidget *instance;

	bool m_animating;
	QOpenGLContext *m_context;
	QOpenGLPaintDevice *m_device;





	//OpenGL DATA
	
	
	glm::mat4 viewMatrix, projMatrix;

	GLuint vao;
	GLuint vbo;
	GLuint ibo;
	float aspect;

	//LIGHTS
	vector< PagLightSource> luces;


	//REVOLUTION OBJECTS(GRAPH SCENE)
	vector< Pag3DGroup> objetos;
	



	//SHADERS
	// - Shaders program that we will use for paint the geometry

	PagShaderProgram* shaderProgram ;



	//CAMERA SETTINGS
	
	glm::mat4 view;
	glm::mat4 mvp;



	//MANAGEMENT FOR INPUT KEYS
	int cont = 0;
	int fog = 0;
	string _typePaint;
	string rutaShaderUsuario;


	bool modeTrial = true;

	int typeTrial = 0;

	bool lightsOn = false;

	
	


	
	
	


	//PRIVATE METHODS

	void addUserShader(string path);

	void typePaint(string type);
	
	void chargeShader();

	

	/**
		* @brief metodo que encapsula la creacion de los objetos de la escena
	*/
	void createObjects();


	/**
	* @brief  Esta función gestiona el tipo de pintado que decirle al group que haga
	* @param  shader a usar
	* @param mode ,para diferenciar los shaders
*/
	void paintObjects(PagShaderProgram &shader, int mode);
};