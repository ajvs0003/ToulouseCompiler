#include "PagCamera.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx\transform.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtx\euler_angles.hpp>

const float MOVE_SPEED = 0.2f;
const double epsilon=0.00000001;
void PagCamera::updateCameraAxis()
{
	glm::vec3 dov = cameraPos-cameralookAt  ;

	n = glm::normalize (dov);
	glm::vec3 Y(0.f, 1.f, 0.f);
	glm::vec3 Z(0.f, 0.f, 1.f);

	glm::vec3 colineal = glm::cross(Y, n);
	if (colineal.x == epsilon && colineal.y == epsilon &&colineal.z == epsilon) {


		if (colineal.y < 0.f) {
			u = glm::normalize(glm::cross(-Z, n));
		}
		
		if(colineal.y > 0.f){
			u = glm::normalize(glm::cross(Z, n));
		}

	}
	else {
		u = glm::normalize(glm::cross(Y, n));
		

	}

	v = glm::normalize(glm::cross(n, u));

}
PagCamera::PagCamera( glm::vec3 position, glm::vec3 position2, float fov){

	this->cameraPos= position;
	this->FoV = fov;
	this->cameralookAt = position2;

	updateCameraAxis();

	
}


PagCamera::~PagCamera()
{}

PagCamera PagCamera::operator=(const PagCamera & other)
{
	FoV=other.FoV;
	cameraPos=other.cameraPos;
	cameralookAt =other.cameralookAt;
	cameraUp=other.cameraUp;
	



	projectionMatrix=other.projectionMatrix;


	return *this;
}


glm::vec3 PagCamera::Position() const
{

	return cameraPos;
}

glm::vec3 PagCamera::Forward() const
{
	return  cameralookAt;
}


glm::vec3 PagCamera::Up() const
{
	return v;
}



void PagCamera::setPosition(glm::vec3 nuev)
{
	cameraPos = nuev;
	updateCameraAxis();
}

void PagCamera::tiltAndPan(float cantidadX, float cantidadY)
{
	

		glm::mat4 rotationPan = glm::translate(glm::mat4(1), glm::vec3(cameraPos));
		rotationPan = glm::rotate(rotationPan, glm::radians(-cantidadX), v);
		rotationPan = glm::translate(rotationPan, glm::vec3(-cameraPos));

		cameralookAt = glm::vec3(rotationPan*(glm::vec4(cameralookAt, 1.0f)));
		updateCameraAxis();//actualizar coordenadas camara

		glm::mat4 rotationTilt = glm::translate(glm::mat4(1), glm::vec3(cameraPos));
		rotationTilt = glm::rotate(rotationTilt, glm::radians(-cantidadY), u);
		rotationTilt = glm::translate(rotationTilt, glm::vec3(-cameraPos));
		

		cameralookAt = glm::vec3(rotationTilt*(glm::vec4(cameralookAt, 1.0f)));
		updateCameraAxis();


}

void PagCamera::SetCameraViewDirection(glm::vec3 & position)
{

	cameralookAt = position;
	updateCameraAxis();

}



void PagCamera::moveFoward()
{
	cameraPos = cameraPos + (-MOVE_SPEED * n);
	cameralookAt = cameralookAt + (-MOVE_SPEED * n);
	updateCameraAxis();

}

void PagCamera::moveBackward()
{
	cameraPos = cameraPos + (MOVE_SPEED * n);
	cameralookAt = cameralookAt + (MOVE_SPEED * n);
	updateCameraAxis();

}

void PagCamera::moveLeft()
{
	
	cameraPos = cameraPos + (-MOVE_SPEED*u);
	cameralookAt = cameralookAt + (-MOVE_SPEED*u);
	
	updateCameraAxis();

	
}

void PagCamera::moveRight()
{
	cameraPos = cameraPos + (MOVE_SPEED*u);
	cameralookAt = cameralookAt + (MOVE_SPEED*u);
	updateCameraAxis();

	
}

void PagCamera::moveUp() {

	cameraPos += MOVE_SPEED * Up();
	cameralookAt += MOVE_SPEED * Up();
	updateCameraAxis();
}
void PagCamera::moveDown() {
	cameraPos += -MOVE_SPEED * Up();
	cameralookAt += -MOVE_SPEED * Up();
	updateCameraAxis();
}

void PagCamera::orbitX(float cantidad)
{
	
	angleOrbitX += cantidad;

	if (angleOrbitX > -70 && angleOrbitX < 60) {
		glm::mat4 rotate = glm::translate(glm::mat4(1), cameralookAt);
		rotate = glm::rotate(rotate, glm::radians(cantidad), u);
		rotate = glm::translate(rotate, -cameralookAt);

		cameraPos = glm::vec3(rotate*(glm::vec4(cameraPos, 1.0f)));
		updateCameraAxis();

	}

}

void PagCamera::orbitY(float cantidad) {

	glm::mat4 rotate = glm::translate(glm::mat4(1), cameralookAt);
	rotate = glm::rotate(rotate, glm::radians(cantidad), glm::vec3(0, 1, 0));
	rotate = glm::translate(rotate, -cameralookAt);


	cameraPos = glm::vec3(rotate*(glm::vec4(cameraPos, 1.0f)));
	updateCameraAxis();




}








glm::mat4 PagCamera::getWorldToViewMatrix() const
{
	return glm::lookAt(this->cameraPos, cameralookAt, v);


}
glm::mat4 PagCamera::getWorldToProjecMatrix(float _width, float _height)
{
	float relacion = (_width / _height);
	float tan = glm::tan(glm::radians(FoV / 2.f));
	float FoVY = 2.f*(glm::atan(tan/relacion));


	projectionMatrix = glm::perspective(
		FoVY, // El campo de visión vertical, en radián: la cantidad de "zoom". Piensa en el lente de la cámara. Usualmente está entre 90° (extra ancho) y 30° (zoom aumentado)
		relacion,       // Proporción. Depende del tamaño de tu ventana 4/3 == 800/600 == 1280/960, Parece familiar?
		0.1f,              // Plano de corte cercano. Tan grande como sea posible o tendrás problemas de precisión.
		100.0f             // Plano de corte lejano. Tan pequeño como se pueda.
	);


	return this->projectionMatrix;
}



void PagCamera::zoom(float factor)
{

	FoV += FoV * factor;
	if (FoV > 150)FoV = 150;//zoom -
	if (FoV < 10)FoV = 10;//zoom +
}