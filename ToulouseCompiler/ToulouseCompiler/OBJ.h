#pragma once

#include "Math.h"

#include <map>
#include <vector>
#include <string>
#include "Metodos_especiales.h"
#include "Log.h"

class OBJ
{
public:

	//Para leer archivos tipo .obj


	OBJ(const std::string& obj, const std::string& mtl_basepath = "");
	~OBJ();



	struct Material {
		std::string Name;
		glm::vec3 Ka, Kd, Ks;
		float Ns{ 0 }, d{ 0 };
		struct {
			std::string Ka, Kd, Ks, Ns, d, bump;
		} map;
		unsigned int illum{ 0 };
	};

	struct FacePoint {
		unsigned int Index_v{ 0 };    // 0 = invalid value
		unsigned int Index_vt{ 0 };
		unsigned int Index_vn{ 0 };
	};

	struct Face {
		std::vector<FacePoint> Points;
	};

	struct Group {
		std::string Name;
		std::map<
			std::string,                                                            // material name
			std::map<unsigned int, std::vector<Face>>        // face arrays mapped to their number of points (sorted triangles, quads, etc ...)
		> Faces;
	};

	struct Object {
		std::string Name;
		std::map<std::string, Group> Groups;
	};

	std::map<std::string, Object> Objects;

	std::vector<glm::vec3> Positions;
	std::vector<glm::vec2> TexCoords;
	std::vector<glm::vec3> Normals;

	std::map<std::string, Material> MaterialLibrary;

private:

	std::string m_mtl_filename{ "" };
	std::string m_object_current{ "" };
	std::string m_group_current{ "" };
	std::string m_material_current{ "" };
	std::string m_errors{ "" };

	void ParseLine(std::stringstream& stream);

};

