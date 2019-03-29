#include "PagPlane.h"
#include <gtc\matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx\euler_angles.hpp>


PagPlane::PagPlane(unsigned int tam, unsigned int tam2, unsigned int divisiones)
{
	 PlaneTam=tam;
	 PlaneTam2=tam2;
	 PlaneDivisiones= divisiones;
	modelMatrix = glm::mat4(1);
	
	unsigned int incremento = tam / divisiones;
	unsigned int incremento2 = tam2 / divisiones;
	float incText = (float) 1.0 / incremento;


	for (unsigned int i = 0; i < divisiones+1; i++) {
		for (unsigned int j = 0; j < divisiones+1; j++) {
			
				PagPosNorm nuevo;
				nuevo.position = glm::vec3(incremento * j, 0.f, incremento2 * i);
				nuevo.normal = glm::vec3(0.f, 1.f, 0.f);
				planeData.PositionsAndNormals.push_back(nuevo);
				planeData.Tangents.push_back(glm::vec3(1.f, 0.f, 0.f));
				planeData.TextureCoords.push_back(glm::vec2(incText*i, incText*j));
			
		}

	}

	



	for (unsigned int i = 0; i < divisiones; i++){
		for (unsigned int j = 0; j <= divisiones; j++) {
			
			planeData.Indices4TrianglesMesh.push_back(j*(divisiones + 1) + (i + 1));
			planeData.Indices4TrianglesMesh.push_back(j*(divisiones + 1) + i);
			
			
			
			
			
		}

		planeData.Indices4TrianglesMesh.push_back(0xFFFFFFFF);


		
		

	}
	for (unsigned int i = 0; i <= divisiones; i++) {
		for (unsigned int j = 0; j <= divisiones; j++) {
			//wireframe verticales
			planeData.Indices4Lines.push_back(j*(divisiones + 1) + i);
				


				
		}
		planeData.Indices4Lines.push_back(0xFFFFFFFF);
	}
	for (unsigned int i = 0; i <= divisiones; i++) {
		for (unsigned int j = 0; j <= divisiones; j++) {
			//wireframe horizontales
			planeData.Indices4Lines.push_back(j + i * (divisiones + 1));
			
			



		}
		planeData.Indices4Lines.push_back(0xFFFFFFFF);
	}






	for (unsigned int s = 0; s < planeData.PositionsAndNormals.size(); s++) {
		planeData.Indices4PointCloud.push_back(s);
		


	}
	planeData.Indices4PointCloud.push_back(0xFFFFFFFF);
	


	VaoPlane = new PagVAO();
	VaoPlane->iniciar(planeData.PositionsAndNormals, planeData.TextureCoords, planeData.Tangents,
		planeData.Indices4PointCloud, planeData.Indices4Lines, planeData.Indices4TrianglesMesh);

}


PagPlane::~PagPlane()
{
}


void PagPlane::Aplicate(PagShaderProgram &shader, bool textures) {
	
	
	material->aplicateMaterial(shader, textures);
	


	if (textures) {

	std::map<string, PagTexture*>::iterator texture;
	std::map<string, PagTexture*>::iterator bumpMapping;
	std::map<string, PagTexture*>::iterator displacement;

	texture = Maptextures.find("texture");
	bumpMapping = Maptextures.find("bumpMapping");
	displacement = Maptextures.find("displacement");

	if (texture != Maptextures.end())texture->second->aplicateTexture(shader, "texture");
	if (bumpMapping != Maptextures.end())bumpMapping->second->aplicateTexture(shader, "bumpMapping");
	if (displacement != Maptextures.end())displacement->second->aplicateTexture(shader, "displacement");





	}else
	Log::getInstancia()->error("pagrevolution:aplicate texture BotFace");





	



	
}

void PagPlane::setMat(NameMaterial name)
{
	nameMaterial = name;
	PagMaterial* aux;
	aux = MaterialLibrary::getInstance()->find(nameMaterial);
	if (aux == nullptr)Log::getInstancia()->error("pagplane: this material dont exists");
	else {
		material = aux;

	}

}

void PagPlane::setTex(NameTexture nuevo, std::string type)
{
	if(type != "") {

		PagTexture* aux;
		aux = TextureLibrary::getInstance()->find(nuevo);
		if (aux == nullptr)Log::getInstancia()->error("pagrevolution: this material dont exists");
		else {

			if (aux == nullptr)Log::getInstancia()->error("pagrevolution: this material doesnt exist");
			else Maptextures.emplace(type, aux);

		}
	}
	else {
	Log::getInstancia()->error("not type texture choosed");
	}



}

void PagPlane::DrawAsPoints(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	// - Asignamos los parámetros de tipo uniform del shader program.
	// Cada shader program tiene su propio conjunto de parámetros.
	shader.setUniform("pointSize", 7.0f);
	shader.setUniform("vColor", glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 matriz = this->modelMatrix * model;

	shader.setUniform("mModelViewProj", projection*view*matriz);

	VaoPlane->drawAsPoints();

}

void PagPlane::DrawAsLines(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{

	// - Asignamos los parámetros de tipo uniform del shader program.
	// Cada shader program tiene su propio conjunto de parámetros.
	shader.setUniform("vColor", glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 matriz = modelMatrix * model;
	shader.setUniform("mModelViewProj", projection*view*matriz);


	VaoPlane->drawAsLines();
}

void PagPlane::DrawAsTriangles(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection, string type)
{
	bool activate = false;
	// - Asignamos los parámetros de tipo uniform del shader program.
	// Cada shader program tiene su propio conjunto de parámetros.
	if (type == "luces" || type == "textures") {
		
		if (type == "textures")activate = true;


		Aplicate(shader, activate);
		
		glm::mat4 matriz = this->modelMatrix * model;
		//mModelViewProj
		shader.setUniform("mvpMatrix", projection*view*matriz);
		shader.setUniform("mModelView", view*matriz);

	}
	else {

		glm::mat4 matriz = this->modelMatrix * model;
		//mModelViewProj
		shader.setUniform("mvpMatrix", projection*view*matriz);

	}
	

	VaoPlane->drawAsTriangles2();
}

void PagPlane::DrawFog(PagShaderProgram & shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	glm::mat4 matriz = this->modelMatrix * model;
	//mModelViewProj
	shader.setUniform("mvpMatrix", projection*view*matriz);
	shader.setUniform("mModelView", view*matriz);

	VaoPlane->drawAsTriangles2();
}



void PagPlane::translate(glm::vec3 move)
{
	modelMatrix = glm::translate(modelMatrix, move);
}



void PagPlane::rotateX(float angle)
{
	modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(1.f, 0.f, 0.f));


}

void PagPlane::rotateY(float angle)
{

	modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(0.f, 1.f, 0.f));
}

void PagPlane::rotateZ(float angle)
{
	modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(0.f, 0.f, 1.f));

	
}

void PagPlane::scale(float tam)
{
	modelMatrix = glm::scale(modelMatrix, glm::vec3(tam));
}






