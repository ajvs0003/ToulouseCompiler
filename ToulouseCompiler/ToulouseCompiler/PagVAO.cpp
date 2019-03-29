#include "PagVAO.h"
#include <QOpenGLFunctions>
const int salto = 0xFFFFFFFF;
PagVAO::PagVAO()
{


	
	glGenVertexArrays(1, &vao);//generacion del id del vao
}


PagVAO::~PagVAO()
{

}






void PagVAO::iniciar(std::vector<PagPosNorm> PositionsAndNormals, std::vector<glm::vec2>  TextureCoords,std::vector<glm::vec3> Tangents,
	std::vector<GLuint> Indices4PointCloud,  std::vector<GLuint> Indices4Lines, std::vector<GLuint> Indices4TrianglesMesh)
{
	Log::getInstancia()->success("Iniciating Vao");
	this->PositionsAndNormals = PositionsAndNormals;
	this->TextureCoords = TextureCoords;
	this->Tangents = Tangents;
	this->Indices4PointCloud = Indices4PointCloud;
	this->Indices4TrianglesMesh = Indices4TrianglesMesh;
	this->Indices4Lines = Indices4Lines;

	glBindVertexArray(vao);
	glGenBuffers(1, &ID_vbo0);
	// - Siempre que se quiere usar un VAO, hay que activarlo con esta orden.


	// - se activa el vbo0 
	glBindBuffer(GL_ARRAY_BUFFER, ID_vbo0);

	// - Se describe c�mo es la geometr�a que hay en ese array
	// - Aqu� se indica que uno de los elementos del array entrelazado va asociado con el
	// layout (location=0) en el shader, en concreto la posici�n
	glEnableVertexAttribArray(0);

	// - Aqu� se describen las caracter�sticas del puntero que permite a la GPU acceder a las
	// posiciones
	glVertexAttribPointer(0, sizeof(glm::vec3) / sizeof(GLfloat),
		GL_FLOAT, GL_FALSE, sizeof(PagPosNorm),
		((GLubyte *)NULL + (0)));

	// - Como es un array entrelazado, hay que repetir el proceso para los dem�s elementos,
	// en este caso para la normal

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, sizeof(glm::vec3) / sizeof(GLfloat),
		GL_FLOAT, GL_FALSE, sizeof(PagPosNorm),
		((GLubyte *)NULL + (sizeof(glm::vec3))));

	// - Se le pasa el array que contiene los datos
	glBufferData(GL_ARRAY_BUFFER, this->PositionsAndNormals.size() * sizeof(PagPosNorm),
		this->PositionsAndNormals.data(), GL_STATIC_DRAW);


	glGenBuffers(1, &ID_vbo1);
	// - Siempre que se quiere usar un VAO, hay que activarlo con esta orden.


	// - se activa el vbo0 
	glBindBuffer(GL_ARRAY_BUFFER, ID_vbo1);

	// - Se describe c�mo es la geometr�a que hay en ese array
	// - Aqu� se indica que uno de los elementos del array entrelazado va asociado con el
	// layout (location=0) en el shader, en concreto la posici�n
	glEnableVertexAttribArray(2);

	// - Aqu� se describen las caracter�sticas del puntero que permite a la GPU acceder a las
	// posiciones
	glVertexAttribPointer(2, sizeof(glm::vec2) / sizeof(GLfloat),
		GL_FLOAT, GL_FALSE, sizeof(glm::vec2),
		((GLubyte *)NULL + (0)));
	glBufferData(GL_ARRAY_BUFFER, this->TextureCoords.size() * sizeof(glm::vec2),
		this->TextureCoords.data(), GL_STATIC_DRAW);



	glGenBuffers(1, &ID_vbo2);
	glBindBuffer(GL_ARRAY_BUFFER, ID_vbo2);

	// - Se describe c�mo es la geometr�a que hay en ese array
	// - Aqu� se indica que uno de los elementos del array entrelazado va asociado con el
	// layout (location=0) en el shader, en concreto la posici�n
	glEnableVertexAttribArray(3);

	// - Aqu� se describen las caracter�sticas del puntero que permite a la GPU acceder a las
	// posiciones
	glVertexAttribPointer(3, sizeof(glm::vec3) / sizeof(GLfloat),
		GL_FLOAT, GL_FALSE, sizeof(glm::vec3),
		((GLubyte *)NULL + (0)));

	glBufferData(GL_ARRAY_BUFFER, this->Tangents.size() * sizeof(glm::vec3),
		this->Tangents.data(), GL_STATIC_DRAW);







	glGenBuffers(1, &ID_ibo0);

	//glBindVertexArray(this->vao);
	// - Se activa el IBO que se quiere rellenar
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo0);
	// - Se le pasa el array que contiene los �ndices
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Indices4PointCloud.size() * sizeof(GLuint), this->Indices4PointCloud.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &ID_ibo1);
	// - Se activa el IBO que se quiere rellenar
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo1);
	// - Se le pasa el array que contiene los �ndices
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Indices4Lines.size() * sizeof(GLuint), this->Indices4Lines.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &ID_ibo2);
	// - Se activa el IBO que se quiere rellenar
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo2);
	// - Se le pasa el array que contiene los �ndices
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Indices4TrianglesMesh.size() * sizeof(GLuint), this->Indices4TrianglesMesh.data(), GL_STATIC_DRAW);

}





void PagVAO::drawAsPoints()
{
	glBindVertexArray(this->vao);
	// - Se activa el IBO que se quiere rellenar
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo0);

	glDrawElements(GL_POINTS, Indices4PointCloud.size(), GL_UNSIGNED_INT, NULL);
}







void PagVAO::drawAsLines()
{
	glBindVertexArray(this->vao);
	// - Se activa el IBO que se quiere rellenar
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo1);

	glDrawElements(GL_LINE_STRIP, Indices4Lines.size(), GL_UNSIGNED_INT, NULL);
}

void PagVAO::drawAsTriangles()
{
	/*for (int i = 0; i < this->PositionsAndNormals.size(); i++) {
		cout << this->PositionsAndNormals.at(i).position.x <<","<< this->PositionsAndNormals.at(i).position.y << endl;
	}*/
	glBindVertexArray(this->vao);
	// - Se activa el IBO que se quiere rellenar
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices4TrianglesMesh.size() * sizeof(GLuint), Indices4TrianglesMesh.data(), GL_STATIC_DRAW);
	glDrawElements(GL_TRIANGLE_FAN, Indices4TrianglesMesh.size(), GL_UNSIGNED_INT, NULL);
	

}
void PagVAO::drawAsTriangles2() {
	glBindVertexArray(this->vao);
	// - Se activa el IBO que se quiere rellenar
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_ibo2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices4TrianglesMesh.size() * sizeof(GLuint), Indices4TrianglesMesh.data(), GL_STATIC_DRAW);
	glDrawElements(GL_TRIANGLE_STRIP, Indices4TrianglesMesh.size(), GL_UNSIGNED_INT, NULL);
}