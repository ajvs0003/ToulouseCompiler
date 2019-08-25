#include "PagSubdivisionProfile.h"




bool PagSubdivisionProfile::line(std::vector<glm::vec2> points) {

	if (points.at(0).x >= 0.0f && points.at(1).x >= 0.0f) {

		this->profile.push_back(points.at(0));
		this->profile.push_back(points.at(1));

		if (points.at(0).x == 0.0f)bottomFace = true;
		else if(points.at(1).x == 0.0f)topFace = true;
		else Body = true;

		return true;

	}
	else {


		return false;
	}





}


bool PagSubdivisionProfile::CheckPoints(){

	if (Pure.size() > 1) {

		if (Pure.size() == 2) {

			if (line(Pure)) {

				Log::getInstancia()->success("Profile  accepted");
				return true;

			}else {
				Log::getInstancia()->error("Profile not accepted");
				return false;
			}

			

		}else {
			for (unsigned int i = 0; i < Pure.size(); i++) {
				

					if (Pure.at(i).x >= 0.0f) {

						if (i == 0) {
							if (Pure.at(i).x == 0.0f) bottomFace = true;
							
						}else if(i == Pure.size()-1){
							if (Pure.at(i).x == 0.0f) topFace = true;
						}else {
							Body = true;	
						}

						profile.push_back(Pure.at(i));
					}else {
						Log::getInstancia()->warning(" Point of Profile (" + to_string((Pure.at(i).x)) + " , " + to_string((Pure.at(i).y)) + ") not accepted");
					}
				}
			/*Log::getInstancia()->success("Profile  accepted");*/
			return true;

			}
		
	}else {
		Log::getInstancia()->error("  Profile not accepted");
		return false;
	}






}

PagSubdivisionProfile::PagSubdivisionProfile( std::vector<glm::vec2> points)
{
	
	this->topFace = false;
	this->bottomFace = false;
	this->Body = false;
	this->Pure = points;

}

PagSubdivisionProfile::~PagSubdivisionProfile()
{
}


PagSubdivisionProfile PagSubdivisionProfile::subdivide(unsigned int times)
{
		std::vector <glm::vec2> aux;
		aux.push_back(profile.at(0));

		for (unsigned int i = 1; i <= profile.size() - 2; i++) {
			glm::vec2 h1 = (profile.at(i - 1) + profile.at(i)) / 2.0f;
			aux.push_back(h1);
			glm::vec2 h2 = ((3.0f * profile.at(i)) / 4.0f) + ((profile.at(i - 1) / 8.0f)) + ((profile.at(i + 1) / 8.0f));
			aux.push_back(h2);
		}

		glm::vec2 h3 = ((profile.at(profile.size()-2) + profile.at(profile.size() - 1)) /2.0f);
		glm::vec2 h4 = (profile.at(profile.size() - 1));
		aux.push_back(h3);
		aux.push_back(h4);

		this->profile=aux;

		
	 if(times == 1)return *this;
	 else return this->subdivide(times - 1);
}
