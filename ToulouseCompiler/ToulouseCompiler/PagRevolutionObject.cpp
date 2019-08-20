#include "PagRevolutionObject.h"
#include <gtc\matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx\euler_angles.hpp>


//PAG_BODY = 0, 
//PAG_TOP_FAN = 1,
//PAG_BOTTOM_FAN = 2
//test=99,


glm::vec3 PagRevolutionObject::CalculateNormalVector(glm::vec3 a, glm::vec3 b)
{
	glm::vec3 v1 = (b - a);
	glm::vec3 n1(v1.y, -v1.x, 0);
	n1 = glm::normalize(n1);

	return n1;
}



glm::vec2 PagRevolutionObject::CalculateNormal(glm::vec2 a) {
	glm::vec2 n1(a.y, -a.x);
	n1 = glm::normalize(n1);

	return n1;
}

void PagRevolutionObject::NormalsProfile() {

	glm::vec2 aux;

	if (has(PAG_BOTTOM_FAN)) {
		this->NormalsOfProfile.push_back(glm::vec2(0, -1));

	}


	for (unsigned int i = 1; i < SubdividedProfile->profile.size(); i++) {
		glm::vec2 a, b, c;
		glm::vec2 ni;
		glm::vec2 ni2;
		glm::vec2 vi;
		glm::vec2 vi2;



		//mirar que pasa si no hay tapa arriba y estamos en el ultimo punto
		if (!has(PAG_TOP_FAN) && i == SubdividedProfile->profile.size() - 1) {
			b = (SubdividedProfile->profile.at(i - 1));
			c = (SubdividedProfile->profile.at(i));
			vi = (c - b);
			ni = CalculateNormal(vi);
			this->NormalsOfProfile.push_back(ni);
		}
		else {


			a = (SubdividedProfile->profile.at(i - 1));
			b = (SubdividedProfile->profile.at(i));
			c = (SubdividedProfile->profile.at(i + 1));




			if (i == 1) {//Vemos si es la primera iteraccion del bucle

				vi = (b - a);//Calculo Los vectores vi y vi2
				vi2 = (c - b);
				aux = vi2;// para guardar el vi2 calculado para el siguiente calculo
			}
			else {

				vi = aux;
				vi2 = (c - b);
				aux = vi2;
			}

			if (has(PAG_BOTTOM_FAN) && i == 1) {
				ni = this->NormalsOfProfile.at(i - 1);//el caso de que haya tapa de arriba

			}
			else {
				ni = CalculateNormal(vi);
			}

			ni2 = CalculateNormal(vi2);

			if (has(PAG_TOP_FAN) && i + 1 == SubdividedProfile->profile.size() - 1) {

				ni2 = glm::vec2(0, 1);
				glm::vec2 v2((ni2 + ni) / 2.0f);
				glm::vec2 n = glm::normalize(v2);
				this->NormalsOfProfile.push_back(n);
				this->NormalsOfProfile.push_back(ni2);

				i = i + 1;
			}
			else {

				glm::vec2 v2((ni2 + ni) / 2.0f);

				if (has(PAG_BOTTOM_FAN) == false) {

					this->NormalsOfProfile.push_back(ni);
				}

				glm::vec2 n = glm::normalize(v2);
				this->NormalsOfProfile.push_back(n);

			}
		}

	}


}




vector<float> PagRevolutionObject::BodyTextures() {


	vector<float>aux;
	vector<glm::vec2> vectors;
	float TotalLength = 0.0;
	int n = SubdividedProfile->profile.size();
	if (has(PAG_TOP_FAN))n--;
	for (int i = 1; i < n; i++) {
		glm::vec2 a(SubdividedProfile->profile.at(i - 1));
		glm::vec2 b(SubdividedProfile->profile.at(i));
		glm::vec2 vi(b - a);
		vectors.push_back(vi);
		TotalLength += glm::length(vi);
	}
	aux.push_back(0);



	float total = 0.0;
	n = SubdividedProfile->profile.size();;
	if (has(PAG_TOP_FAN))n--;
	for (int i = 1; i < n; i++) {

		total += glm::length(vectors.at(i - 1));


		aux.push_back(total / TotalLength);



	}



	return aux;

}

void PagRevolutionObject::createGeometryBody(int slices, double delta)
{
	int i = 0;    int n = this->SubdividedProfile->profile.size();
	if (has(PAG_BOTTOM_FAN)) {

		i = 1;
	}

	if (has(PAG_TOP_FAN)) {
		n = n - 1;

	}
	else {
		n = this->SubdividedProfile->profile.size() - 1;
	}


	vector<float> v = BodyTextures();
	for (int p = i; p <= n; p++) {
		glm::vec3 p0((SubdividedProfile->profile.at(p).x), (SubdividedProfile->profile.at(p).y), 0.f);
		glm::vec3 n0(this->NormalsOfProfile.at(p).x, this->NormalsOfProfile.at(p).y, 0.f);
		PagPosNorm PagI;
		for (int s = 0; s <= slices; s++) {
			double a = s * delta;
			glm::vec3 pi((p0.x)*glm::cos(a), p0.y, -(p0.x)*glm::sin(a));
			glm::vec3 ni((n0.x)*glm::cos(a), n0.y, -(n0.x)*glm::sin(a));
			ni = glm::normalize(ni);

			//normales y posiciones
			PagI.position = pi;
			PagI.normal = ni;
			Body.PositionsAndNormals.push_back(PagI);

			//texturas
			float u = s * (1.0f / slices);
			if (p == 0) {
				glm::vec2 tc(u, v.at(p));
				Body.TextureCoords.push_back(tc);
			}
			else {

				if (has(PAG_BOTTOM_FAN)) {
					glm::vec2 tc(u, v.at(p - 1));
					Body.TextureCoords.push_back(tc);
				}
				else {
					if (p == n) {
						glm::vec2 tc(u, v.at(p - 1));
						Body.TextureCoords.push_back(tc);
					}
					else {
						glm::vec2 tc(u, v.at(p));
						Body.TextureCoords.push_back(tc);
					}
				}
			}

			/*		cout <<s<<"_:"<< u <<","<< v.at(p - 1) << endl;*/



					//tangentes
			glm::vec3 ti(-glm::sin(a), 0, -glm::cos(a));//formula normal
			Body.Tangents.push_back(ti);

			//lineas verticales para wireframe
			Body.Indices4Lines.push_back((p*(slices + 1)) + s);

		}


		//lineas verticales para wireframe
		Body.Indices4Lines.push_back(PAG_PRIMITIVE_RESTART);


	}

	//puntos para nube de puntos
	for (unsigned int s = 0; s < Body.PositionsAndNormals.size(); s++) {
		Body.Indices4PointCloud.push_back(s);

	}



	int m = this->SubdividedProfile->profile.size();
	if (has(PAG_BOTTOM_FAN)) {
		if (has(PAG_TOP_FAN)) {
			m = m - 2;
		}
		else {
			m = m - 1;
		}
	}


	////lineas horizontales para wireframe y malla triangulos
	for (int s = 0; s < slices; s++) {
		for (int r = 0; r < m; r++) {
			//wireframe horizontal
			Body.Indices4Lines.push_back((r*(slices + 1)) + s);


			//triangulos
			Body.Indices4TrianglesMesh.push_back((r*(slices + 1)) + s);
			Body.Indices4TrianglesMesh.push_back((r*(slices + 1)) + (s + 1));

		}

		Body.Indices4Lines.push_back(PAG_PRIMITIVE_RESTART);
		Body.Indices4TrianglesMesh.push_back(PAG_PRIMITIVE_RESTART);

	}






}

void PagRevolutionObject::createGeometryTopFace(int slices, double delta)
{
	int n = SubdividedProfile->profile.size();
	glm::vec3 pS(0.0, (SubdividedProfile->profile.at(n - 1).y), 0.0);//punto S+1
	glm::vec3 p0((SubdividedProfile->profile.at(n - 2).x), (SubdividedProfile->profile.at(n - 2).y), 0);//PUNTO S0
	glm::vec3 n0(this->NormalsOfProfile.at(n - 2).x, this->NormalsOfProfile.at(n - 2).y, 0);

	PagPosNorm PagI;

	for (int s = 0; s <= slices; s++) {
		double a = s * delta;


		//asigno posiciones y normales
		glm::vec3 pi((p0.x)*glm::cos(a), p0.y, -(p0.x)*glm::sin(a));
		glm::vec3 ni((n0.x)*glm::cos(a), n0.y, -(n0.x)*glm::sin(a));
		glm::vec3 z(0, 0, 1);
		ni = glm::normalize(ni);
		PagI.position = pi;
		PagI.normal = ni;
		TopFace.PositionsAndNormals.push_back(PagI);

		//texturas
		glm::vec2 tci((-glm::sin(a) / 2.0f) + 0.5f, (glm::cos(a) / 2.0f) + 0.5f);
		TopFace.TextureCoords.push_back(tci);


		//tangentes
		glm::vec3 ti;
		ti = glm::cross(ni, z);
		TopFace.Tangents.push_back(ti);







	}



	PagPosNorm Ps;
	Ps.position = pS;
	glm::vec3 a(0, 1, 0);//la normal es la calculada
	Ps.normal = { this->NormalsOfProfile.at(n - 1).x, this->NormalsOfProfile.at(n - 1).y, 0 };
	glm::vec3 t0(1, 0, 0);
	glm::vec2 ct(0.5, 0.5);


	TopFace.PositionsAndNormals.push_back(Ps);
	TopFace.TextureCoords.push_back(ct);
	TopFace.Tangents.push_back(t0);


	TopFace.Indices4TrianglesMesh.push_back(slices + 1);

	for (int s = 0; s <= slices; s++) {

		TopFace.Indices4TrianglesMesh.push_back(s);
	}

	TopFace.Indices4TrianglesMesh.push_back(PAG_PRIMITIVE_RESTART);






	for (unsigned int i = 0; i < TopFace.PositionsAndNormals.size(); i++) {
		TopFace.Indices4PointCloud.push_back(i);
	}
	TopFace.Indices4PointCloud.push_back(PAG_PRIMITIVE_RESTART);

	for (int s = 0; s < slices; s++) {
		//indices tipo wireframe
		TopFace.Indices4Lines.push_back(slices + 1);
		TopFace.Indices4Lines.push_back(s);
		TopFace.Indices4Lines.push_back(s + 1);
		TopFace.Indices4Lines.push_back(PAG_PRIMITIVE_RESTART);
	}
	TopFace.Indices4Lines.push_back(slices + 1);
	TopFace.Indices4Lines.push_back(slices);
	TopFace.Indices4Lines.push_back(0);
	TopFace.Indices4Lines.push_back(PAG_PRIMITIVE_RESTART);



}

void PagRevolutionObject::createGeometryBotFace(int slices, double delta)
{
	glm::vec3 pS(0, (SubdividedProfile->profile.at(0).y), 0);//punto S+1
	glm::vec3 p0((SubdividedProfile->profile.at(1).x), (SubdividedProfile->profile.at(1).y), 0);//PUNTO S0
	glm::vec3 n0(this->NormalsOfProfile.at(1).x, this->NormalsOfProfile.at(1).y, 0);//cojo la normal de la generatriz
	glm::vec3 z(0, 0, -1);
	PagPosNorm PagI;




	for (int s = 0; s <= slices; s++) {
		double a = s * delta;

		glm::vec3 pi((p0.x)*glm::cos(a), p0.y, -(p0.x)*glm::sin(a));
		glm::vec3 ni((n0.x)*glm::cos(a), n0.y, -(n0.x)*glm::sin(a));
		ni = glm::normalize(ni);

		glm::vec3 ti;

		//Asigno los valores de posiciones y normal
		PagI.position = pi;
		PagI.normal = ni;
		BotFace.PositionsAndNormals.push_back(PagI);


		//coordenada de textura
		glm::vec2 tci((glm::sin(a) / 2.0f) + 0.5f, (glm::cos(a) / 2.0f) + 0.5f);
		BotFace.TextureCoords.push_back(tci);

		//formula normal para la tangente
		ti = glm::cross(ni, z);
		BotFace.Tangents.push_back(ti);




		//indices tipo punto
		BotFace.Indices4PointCloud.push_back(s);





	}





	//el ultimo punto el s+1 es agregado ahora
	PagPosNorm Ps;
	Ps.position = pS;

	glm::vec3 a(0, -1, 0);
	Ps.normal = { this->NormalsOfProfile.at(0).x, this->NormalsOfProfile.at(0).y, 0 };
	glm::vec3 t0(0, 0, -1);
	glm::vec2 ct(0.5, 0.5);


	BotFace.PositionsAndNormals.push_back(Ps);
	BotFace.TextureCoords.push_back(ct);
	BotFace.Tangents.push_back(t0);


	BotFace.Indices4PointCloud.push_back(slices + 1);
	BotFace.Indices4PointCloud.push_back(PAG_PRIMITIVE_RESTART);


	for (int i = BotFace.PositionsAndNormals.size() - 1; i >= 0; i--)
		BotFace.Indices4TrianglesMesh.push_back(i);

	BotFace.Indices4TrianglesMesh.push_back(PAG_PRIMITIVE_RESTART);


	for (int s = 0; s < slices; s++) {
		//indices tipo wireframe
		BotFace.Indices4Lines.push_back(slices + 1);
		BotFace.Indices4Lines.push_back(s);
		BotFace.Indices4Lines.push_back(s + 1);
		BotFace.Indices4Lines.push_back(PAG_PRIMITIVE_RESTART);
	}
	BotFace.Indices4Lines.push_back(slices + 1);
	BotFace.Indices4Lines.push_back(slices);
	BotFace.Indices4Lines.push_back(0);
	BotFace.Indices4Lines.push_back(PAG_PRIMITIVE_RESTART);

}

void PagRevolutionObject::Revolution(PagRevObjParts part, unsigned int slices) {

	double delta = 360 / slices;
	delta = glm::radians(delta);

	if (part == PAG_BOTTOM_FAN) {

		this->createGeometryBotFace(slices, delta);
	}

	if (part == PAG_BODY) {

		this->createGeometryBody(slices, delta);
	}
	if (part == PAG_TOP_FAN) {

		this->createGeometryTopFace(slices, delta);


	}


}



PagRevolutionObject::PagRevolutionObject(OpenGLFunctions *_gl, std::vector<glm::vec2> points, unsigned int subdivisions, unsigned int slices) {

	gl = _gl;

	modelMatrix = glm::mat4(1);



	Original = new PagSubdivisionProfile(points);
	if (isValid() == true) {
		if (subdivisions > 0) {
			SubdividedProfile = new PagSubdivisionProfile(*Original);
			SubdividedProfile->subdivide(subdivisions);

			this->NormalsProfile();

		}
		else {

			Log::getInstancia()->warning("You put 0 subdivisions,so you are using the copy of the Original Profile");
			SubdividedProfile = new PagSubdivisionProfile(*Original);
			this->NormalsProfile();

		}
		//revolucionar y crear vaos,ibos y mas cosas
		if (has(PAG_BOTTOM_FAN)) {
			this->Revolution(PAG_BOTTOM_FAN, slices);
			this->VaoBotFace = new PagVAO(gl);
			this->VaoBotFace->iniciar(BotFace.PositionsAndNormals, BotFace.TextureCoords, BotFace.Tangents,
				BotFace.Indices4PointCloud, BotFace.Indices4Lines, BotFace.Indices4TrianglesMesh);

			/*
			Generacionn de archivos para meshlab
			WriteTxt(PAG_BOTTOM_FAN);

			*/


		}

		if (has(PAG_BODY)) {


			this->Revolution(PAG_BODY, slices);
			this->VaoBody = new PagVAO(gl);
			this->VaoBody->iniciar(Body.PositionsAndNormals, Body.TextureCoords, Body.Tangents,
				Body.Indices4PointCloud, Body.Indices4Lines, Body.Indices4TrianglesMesh);

			/*WriteTxt(PAG_BODY);*/



		}

		if (has(PAG_TOP_FAN)) {

			this->Revolution(PAG_TOP_FAN, slices);
			this->VaoTopFace = new PagVAO(gl);
			this->VaoTopFace->iniciar(TopFace.PositionsAndNormals, TopFace.TextureCoords, TopFace.Tangents,
				TopFace.Indices4PointCloud, TopFace.Indices4Lines, TopFace.Indices4TrianglesMesh);

			/*WriteTxt(PAG_TOP_FAN);*/


		}

		/*WriteTxt(test);*/
	}




}


PagRevolutionObject::~PagRevolutionObject() {
	delete Original;
	delete SubdividedProfile;
	delete  VaoBody;
	delete  VaoBotFace;
	delete VaoTopFace;
}


bool PagRevolutionObject::isValid() {

	return Original->CheckPoints();
}


bool PagRevolutionObject::has(PagRevObjParts part)
{
	switch (part) {

	case PAG_BODY:
		return SubdividedProfile->Body;
		break;

	case PAG_TOP_FAN:
		return SubdividedProfile->topFace;
		break;

	case PAG_BOTTOM_FAN:

		return SubdividedProfile->bottomFace;

		break;

	default:
		return false;
		break;
	}

}

void PagRevolutionObject::WriteTxt(PagRevObjParts part)
{
	std::vector<PagPosNorm> vertices;
	string name;
	if (part == PAG_BOTTOM_FAN) {
		vertices = BotFace.PositionsAndNormals;


	}
	if (part == PAG_TOP_FAN) {
		vertices = TopFace.PositionsAndNormals;

	}

	if (part == PAG_BODY) {
		vertices = Body.PositionsAndNormals;

	}

	if (part == test) {
		string log_file;
		log_file.assign("./MeshLab/profile3d.txt");
		/*this->log.open(log_file.c_str());*/
		std::ofstream file;
		file.open(log_file.c_str());
		for (unsigned int i = 0; i < this->SubdividedProfile->profile.size(); i++)
		{
			file << this->SubdividedProfile->profile.at(i).x << "," << this->SubdividedProfile->profile.at(i).y << "," << 0.0f << std::endl;
		}
		file.close();
	}

	string log_file;
	log_file.assign("./MeshLab/Geometry.txt");
	/*this->log.open(log_file.c_str());*/
	std::ofstream file;
	file.open(log_file.c_str(), ios::app);
	for (PagPosNorm vert : vertices)
	{
		file << vert.position.x << " " << vert.position.y << " " << vert.position.z << " "
			<< vert.normal.x << " " << vert.normal.y << " " << vert.normal.z << std::endl;
	}
	file.close();


}



unsigned int PagRevolutionObject::getNPoints(PagRevObjParts part)
{
	if (part == PAG_BOTTOM_FAN) {
		return BotFace.PositionsAndNormals.size();
	}
	if (part == PAG_TOP_FAN) {
		return TopFace.PositionsAndNormals.size();
	}
	if (part == PAG_BODY) {
		return Body.PositionsAndNormals.size();
	}


	return 0;
}


void PagRevolutionObject::setMatBody(NameMaterial nuevo)
{
	MatBody = nuevo;
	PagMaterial* aux;
	aux = MaterialLibrary::getInstance()->find(nuevo);
	if (aux == nullptr)Log::getInstancia()->error("pagrevolution: this material dont exists");
	else {

		std::pair<PagRevObjParts, PagMaterial*> uno(PAG_BODY, aux);
		material.insert(uno);

	}

}
//
void PagRevolutionObject::setMatTopFace(NameMaterial nuevo)
{
	MatTopFace = nuevo;
	PagMaterial* aux;
	aux = MaterialLibrary::getInstance()->find(nuevo);
	if (aux == nullptr)Log::getInstancia()->error("pagrevolution: this material dont exists");
	else {

		std::pair<PagRevObjParts, PagMaterial*> uno(PAG_TOP_FAN, aux);
		material.insert(uno);

	}

}



void PagRevolutionObject::setMatBotFace(NameMaterial nuevo)
{
	MatBotFace = nuevo;
	PagMaterial* aux;
	aux = MaterialLibrary::getInstance()->find(nuevo);
	if (aux == nullptr)Log::getInstancia()->error("pagrevolution: this material dont exists");
	else {

		std::pair<PagRevObjParts, PagMaterial*> uno(PAG_BOTTOM_FAN, aux);
		material.insert(uno);

	}

}


void PagRevolutionObject::setTexBody(NameTexture nuevo) {




	PagTexture* aux;
	aux = TextureLibrary::getInstance(gl)->find(nuevo);


	if (aux == nullptr)Log::getInstancia()->error("pagrevolution: this texture doesnt exist");
	else textureBody = aux;



}

void PagRevolutionObject::setTexTopFace(NameTexture nuevo) {




	PagTexture* aux;
	aux = TextureLibrary::getInstance(gl)->find(nuevo);

	if (aux == nullptr)Log::getInstancia()->error("pagrevolution: this texture doesnt exist");
	else textureTopFace = aux;




}

void PagRevolutionObject::setTexBotFace(NameTexture nuevo) {



	PagTexture* aux;
	aux = TextureLibrary::getInstance(gl)->find(nuevo);


	if (aux == nullptr)Log::getInstancia()->error("pagrevolution: this texture doesnt exist");
	else textureBotFace = aux;



}


void PagRevolutionObject::Aplicate(PagShaderProgram &shader, PagRevObjParts part, bool textures) {

	if (part == PAG_BOTTOM_FAN) {
		std::map<PagRevObjParts, PagMaterial* >::iterator it;
		it = material.find(PAG_BOTTOM_FAN);
		if (it != material.end())
			it->second->aplicateMaterial(shader, textures);
		else
			Log::getInstancia()->error("pagrevolution:aplicate material BotFace");

		if (textures) {

			


			if (textureBotFace != nullptr)textureBotFace->aplicateTexture(shader, "texture");
			else
				Log::getInstancia()->error("pagrevolution:aplicate texture BotFace");





		}
		

	}


	if (part == PAG_TOP_FAN) {
		std::map<PagRevObjParts, PagMaterial*>::iterator it;
		it = material.find(PAG_TOP_FAN);
		if (it != material.end())
			it->second->aplicateMaterial(shader, textures);
		else
			Log::getInstancia()->error("pagrevolution:aplicate material TopFace");

		if (textures) {
			


			if (textureTopFace != nullptr)textureTopFace->aplicateTexture(shader, "texture");
			else
				Log::getInstancia()->error("pagrevolution:aplicate texture TopFace");

		}
		

	}


	if (part == PAG_BODY) {
		std::map<PagRevObjParts, PagMaterial*>::iterator it;
		it = material.find(PAG_BODY);
		if (it != material.end())
			it->second->aplicateMaterial(shader, textures);
		else
			Log::getInstancia()->error("pagrevolution:aplicate material Body");

		if (textures) {
			


			if (textureBody != nullptr)textureBody->aplicateTexture(shader, "texture");
			else
				Log::getInstancia()->error("pagrevolution:aplicate texture Body");

		}

	}






}




void PagRevolutionObject::DrawAsPoints(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	//// - Activamos el shader program que se va a usar.
	/*shader.use();*/
	// - Asignamos los parámetros de tipo uniform del shader program.
	// Cada shader program tiene su propio conjunto de parámetros.
	/*shader.setUniform("pointSize", 7.0f);*/
	/*shader.setUniform("vColor", glm::vec3(1.0f, 0.0f, 0.0f));*/



	glm::mat4 matriz = this->modelMatrix * model;

	shader.setUniform("mModelViewProj", projection*view*matriz);

	/*cout << "Ha llegado a la parte de pintar en revolution para puntos" << endl;*/




	if (has(PAG_BOTTOM_FAN))VaoBotFace->drawAsPoints();
	if (has(PAG_TOP_FAN))VaoTopFace->drawAsPoints();
	if (has(PAG_BODY))VaoBody->drawAsPoints();

}

void PagRevolutionObject::DrawAsLines(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{

	// - Asignamos los parámetros de tipo uniform del shader program.
	// Cada shader program tiene su propio conjunto de parámetros.
	/*shader.setUniform("vColor", glm::vec3(0.0f, 0.0f, 1.0f));*/
	glm::mat4 matriz = modelMatrix * model;
	shader.setUniform("mModelViewProj", projection*view*matriz);

	/*cout << "Ha llegado a la parte de pintar en revolution para lineas" << endl;*/

	if (has(PAG_BOTTOM_FAN))VaoBotFace->drawAsLines();
	if (has(PAG_TOP_FAN))VaoTopFace->drawAsLines();
	if (has(PAG_BODY))VaoBody->drawAsLines();
}

void PagRevolutionObject::DrawAsTriangles(PagShaderProgram & shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	cout << "Ha llegado a la parte de pintar en revolution para materiales" << endl;
	glm::mat4 matriz = this->modelMatrix * model;
	//mModelViewProj
	shader.setUniform("mvpMatrix", projection*view*matriz);
	if (has(PAG_BOTTOM_FAN))VaoBotFace->drawAsTriangles();
	if (has(PAG_TOP_FAN))VaoTopFace->drawAsTriangles();
	if (has(PAG_BODY))VaoBody->drawAsTriangles2();
}

void PagRevolutionObject::DrawAsTrianglesWithLights(PagShaderProgram &shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection, bool textures)
{


	glm::mat4 matriz = this->modelMatrix * model;
	//mModelViewProj
	shader.setUniform("mvpMatrix", projection*view*matriz);
	shader.setUniform("mModelView", view*matriz);


	/*cout << "Ha llegado a la parte de pintar en revolution para texturas" << endl;*/
	if (has(PAG_BOTTOM_FAN)) {

		Aplicate(shader, PAG_BOTTOM_FAN, textures);

		VaoBotFace->drawAsTriangles();
	}
	if (has(PAG_TOP_FAN)) {


		Aplicate(shader, PAG_TOP_FAN, textures);
		VaoTopFace->drawAsTriangles();

	}
	if (has(PAG_BODY)) {

		Aplicate(shader, PAG_BODY, textures);
		VaoBody->drawAsTriangles2();

	}




}







void PagRevolutionObject::DrawFog(PagShaderProgram & shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	glm::mat4 matriz = this->modelMatrix * model;
	//mModelViewProj
	shader.setUniform("mvpMatrix", projection*view*matriz);
	shader.setUniform("mModelView", view*matriz);

	if (has(PAG_BOTTOM_FAN))VaoBotFace->drawAsTriangles();
	if (has(PAG_TOP_FAN))VaoTopFace->drawAsTriangles();
	if (has(PAG_BODY))VaoBody->drawAsTriangles2();
}



void PagRevolutionObject::translate(glm::vec3 move)
{
	modelMatrix = glm::translate(modelMatrix, move);
}



void PagRevolutionObject::rotateX(float angle)
{
	modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(1.f, 0.f, 0.f));


}

void PagRevolutionObject::rotateY(float angle)
{

	modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(0.f, 1.f, 0.f));
}

void PagRevolutionObject::rotateZ(float angle)
{
	modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(0.f, 0.f, 1.f));

}

void PagRevolutionObject::scale(float tam)
{
	modelMatrix = glm::scale(modelMatrix, glm::vec3(tam));
}















