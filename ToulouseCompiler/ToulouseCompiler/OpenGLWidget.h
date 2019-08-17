#pragma once

#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>
#include "PagShaderProgram.h"
#include "OpenGLFunctions.h"
#include "Metodos_especiales.h"
#include "Pag3DGroup.h"
#include "PagCamera.h"
#include "AmbientLight.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "Spotlight.h"
#include <string>
#include <QMouseEvent>
#include <QEvent>
#include "addDialog.h"

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


	void changeTrial(int nuevo);
	
	void setPathShader(string path);

	void setUniforms(vector<dataForUniform> _uniforms);

	void compile();

	void chargeUniforms();
	

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

	
	float aspect;

	//LIGHTS
	AmbientLight* ambiental;
	PointLight* puntual;
	SpotLight* spot;
	DirectionalLight* directional;

	//REVOLUTION OBJECTS(GRAPH SCENE)
	vector< Pag3DGroup> objetos;
	



	//SHADERS
	// - Shaders program that we will use for paint the geometry

	PagShaderProgram* shaderProgram ;
	std::vector<dataForUniform> uniforms;


	//CAMERA SETTINGS
	
	glm::mat4 view;
	glm::mat4 mvp;



	//MANAGEMENT FOR INPUT KEYS


	enum typePaint {
		points, wire, triangle, material,textures
	};


	string shaderPath;


	bool modeTrial = false;

	int typeTrial = 0;

	bool firstCompile = false;

	

	//PRIVATE METHODS

	
	void Paint();
	
	void chargeShader();

	void checkOpenGLVersion();
	
	void configurateCamera();

	/**
		* @brief metodo que encapsula la creacion de los objetos de la escena
	*/
	void createObjects();

	void createLights();
	/**
	* @brief  Esta función gestiona el tipo de pintado que decirle al group que haga
	* @param  shader a usar
	* @param mode ,para diferenciar los shaders
*/
	void paintObjects(PagShaderProgram &shader, int mode);
};