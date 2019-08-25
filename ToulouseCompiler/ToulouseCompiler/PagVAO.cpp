#include "PagVAO.h"

#include <QtCore/QCoreApplication>

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>

#include <QWidget>
#include <QDebug>

#include <gtc/matrix_transform.hpp>
const int salto = 0xFFFFFFFF;








PagVAO::PagVAO()
{
}

PagVAO::PagVAO(OpenGLFunctions *_gl)
{
	gl = _gl;
		
	gl->glGenVertexArrays(1, &vao);//generacion del id del vao
	
	
}


PagVAO::~PagVAO()
{

}






void PagVAO::iniciar(std::vector<PagPosNorm> PositionsAndNormals, std::vector<glm::vec2>  TextureCoords,std::vector<glm::vec3> Tangents,
	std::vector<GLuint> Indices4PointCloud,  std::vector<GLuint> Indices4Lines, std::vector<GLuint> Indices4TrianglesMesh)
{
	/*Log::getInstancia()->success("Iniciating Vao");*/
	this->PositionsAndNormals = PositionsAndNormals;
	this->TextureCoords = TextureCoords;
	this->Tangents = Tangents;
	this->Indices4PointCloud = Indices4PointCloud;
	this->Indices4TrianglesMesh = Indices4TrianglesMesh;
	this->Indices4Lines = Indices4Lines;
	
	
	gl->glBindVertexArray(vao);
	gl->glGenBuffers(1, &ID_vbo0);
	// - Siempre que se quiere usar un VAO, hay que activarlo con esta orden.


	// - se activa el vbo0 
	gl->glBindBuffer(GL_ARRAY_BUFFER, ID_vbo0);

	// - Se describe cómo es la geometría que hay en ese array
	// - Aquí se indica que uno de los elementos del array entrelazado va asociado con el
	// layout (location=0) en el shader, en concreto la posición
	gl->glEnableVertexAttribArray(0);

	// - Aquí se describen las características del puntero que permite a la GPU acceder a las
	// posiciones
	gl->glVertexAttribPointer(0, sizeof(glm::vec3) / sizeof(GLfloat),
		GL_FLOAT, GL_FALSE, sizeof(PagPosNorm),
		((GLubyte *)NULL + (0)));

	// - Como es un array entrelazado, hay que repetir el proceso para los demás elementos,
	// en este caso para la normal

	gl->glEnableVertexAttribArray(1);
	gl->glVertexAttribPointer(1, sizeof(glm::vec3) / sizeof(GLfloat),
		GL_FLOAT, GL_FALSE, sizeof(PagPosNorm),
		((GLubyte *)NULL + (sizeof(glm::vec3))));

	// - Se le pasa el array que contiene los datos
	gl->glBufferData(GL_ARRAY_BUFFER, this->PositionsAndNormals.size() * sizeof(PagPosNorm),
		this->PositionsAndNormals.data(), GL_STATIC_DRAW);


	gl->glGenBuffers(1, &ID_vbo1);
	// - Siempre que se quiere usar un VAO, hay que activarlo con esta orden.


	// - se activa el vbo0 
	gl->glBindBuffer(GL_ARRAY_BUFFER, ID_vbo1);

	// - Se describe cómo es la geometría que hay en ese array
	// - Aquí se indica que uno de los elementos del array entrelazado va asociado con el
	// layout (location=0) en el shader, en concreto la posición
	gl->glEnableVertexAttribArray(2);

	// - Aquí se describen las características del puntero que permite a la GPU acceder a las
	// posiciones
	gl->glVertexAttribPointer(2, sizeof(glm::vec2) / sizeof(GLfloat),
		GL_FLOAT, GL_FALSE, sizeof(glm::vec2),
		((GLubyte *)NULL + (0)));
	gl->glBufferData(GL_ARRAY_BUFFER, this->TextureCoords.size() * sizeof(glm::vec2),
		this->TextureCoords.data(), GL_STATIC_DRAW);



	gl->glGenBuffers(1, &ID_vbo2);
	gl->glBindBuffer(GL_ARRAY_BUFFER, ID_vbo2);

	// - Se describe cómo es la geometría que hay en ese array
	// - Aquí se indica que uno de los elementos del array entrelazado va asociado con el
	// layout (location=0) en el shader, en concreto la posición
	gl->glEnableVertexAttribArray(3);

	// - Aquí se describen las características del puntero que permite a la GPU acceder a las
	// posiciones
	gl->glVertexAttribPointer(3, sizeof(glm::vec3) / sizeof(GLfloat),
		GL_FLOAT, GL_FALSE, sizeof(glm::vec3),
		((GLubyte *)NULL + (0)));

	gl->glBufferData(GL_ARRAY_BUFFER, this->Tangents.size() * sizeof(glm::vec3),
		this->Tangents.data(), GL_STATIC_DRAW);







	gl->glGenBuffers(1, &ID_ibo0);

	//glBindVertexArray(this->vao);
	// - Se activa el IBO que se quiere rellenar
	gl->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo0);
	// - Se le pasa el array que contiene los índices
	gl->glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Indices4PointCloud.size() * sizeof(GLuint), this->Indices4PointCloud.data(), GL_STATIC_DRAW);

	gl->glGenBuffers(1, &ID_ibo1);
	// - Se activa el IBO que se quiere rellenar
	gl->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo1);
	// - Se le pasa el array que contiene los índices
	gl->glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Indices4Lines.size() * sizeof(GLuint), this->Indices4Lines.data(), GL_STATIC_DRAW);

	gl->glGenBuffers(1, &ID_ibo2);
	// - Se activa el IBO que se quiere rellenar
	gl->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo2);
	// - Se le pasa el array que contiene los índices
	gl->glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Indices4TrianglesMesh.size() * sizeof(GLuint), this->Indices4TrianglesMesh.data(), GL_STATIC_DRAW);

}





void PagVAO::drawAsPoints()
{
	gl->glBindVertexArray(this->vao);
	// - Se activa el IBO que se quiere rellenar
	gl->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo0);

	gl->glDrawElements(GL_POINTS, Indices4PointCloud.size(), GL_UNSIGNED_INT, NULL);
}







void PagVAO::drawAsLines()
{
	gl->glBindVertexArray(this->vao);
	// - Se activa el IBO que se quiere rellenar
	gl->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo1);

	gl->glDrawElements(GL_LINE_STRIP, Indices4Lines.size(), GL_UNSIGNED_INT, NULL);
}

void PagVAO::drawAsTriangles()
{
	/*for (int i = 0; i < this->PositionsAndNormals.size(); i++) {
		cout << this->PositionsAndNormals.at(i).position.x <<","<< this->PositionsAndNormals.at(i).position.y << endl;
	}*/
	gl->glBindVertexArray(this->vao);
	// - Se activa el IBO que se quiere rellenar
	gl->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo2);
	gl->glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices4TrianglesMesh.size() * sizeof(GLuint), Indices4TrianglesMesh.data(), GL_STATIC_DRAW);
	gl->glDrawElements(GL_TRIANGLE_FAN, Indices4TrianglesMesh.size(), GL_UNSIGNED_INT, NULL);
	

}
void PagVAO::drawAsTriangles2() {
	gl->glBindVertexArray(this->vao);
	// - Se activa el IBO que se quiere rellenar
	gl->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo2);
	gl->glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices4TrianglesMesh.size() * sizeof(GLuint), Indices4TrianglesMesh.data(), GL_STATIC_DRAW);
	gl->glDrawElements(GL_TRIANGLE_STRIP, Indices4TrianglesMesh.size(), GL_UNSIGNED_INT, NULL);
}