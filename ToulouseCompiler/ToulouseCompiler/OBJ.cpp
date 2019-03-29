#include "OBJ.h"
#include <iostream>
#include <fstream>
#include <sstream>


OBJ::OBJ(const std::string& obj, const std::string& mtl_basepath)
{
	// open .obj file
	std::fstream f(obj, std::ios::in);
	if (!f.good())
	{
		Log::getInstancia()->error("cannot open obj data file: " + obj + "\n");
		return;
	}

	// read .obj file
	while (f.good())
	{
		std::string line;
		std::getline(f, line);
		std::stringstream nuevo(line);
		ParseLine(nuevo);
	}

	f.close();

	// check if all indices are valid:
	for (auto& objectdata : Objects)
	{
		for (auto& groupdata : objectdata.second.Groups)
		{
			for (auto& facedata : groupdata.second.Faces)
			{
				for (auto& facemap : facedata.second)
				{
					for (auto& face : facemap.second)
					{
						for (auto& point : face.Points)
						{
							if (point.Index_v == 0 || point.Index_v > Positions.size())
								Log::getInstancia()->error("error face index_v out of range\n");
							if (point.Index_vt > TexCoords.size())
								Log::getInstancia()->error("error face index_vt out of range\n");
							if (point.Index_vn > Normals.size())
								Log::getInstancia()->error("error face index_vn out of range\n");
						}
					}
				}
			}
		}
	}


	// open .mtl file
	std::string filename = mtl_basepath + m_mtl_filename;
	f.open(filename, std::ios::in);
	if (!f.good())
	{
		Log::getInstancia()->error("cannot open material library file: " + filename + "\n");
		return;
	}

	// read .mtl file
	m_material_current = "";
	while (f.good())
	{
		std::string line;
		std::getline(f, line);
		std::stringstream nuevo(line);
		ParseLine(nuevo);
	}

	f.close();

	// check for missing materials:
	for (auto& objectdata : Objects)
	{
		for (auto& groupdata : objectdata.second.Groups)
		{
			for (auto& facedata : groupdata.second.Faces)
			{
				auto it = MaterialLibrary.find(facedata.first);
				if (it == MaterialLibrary.end())
					Log::getInstancia()->error("missing material data: " + facedata.first + "\n");
			}
		}
	}

}


OBJ::~OBJ()
{}


void OBJ::ParseLine(std::stringstream& stream)
{
	std::string token;
	stream >> token;

	if (token.empty()) return;
	if (token[0] == '#') return;

	if (token == "o")
	{
		stream >> m_object_current;
		Objects[m_object_current].Name = m_object_current;
	}
	else if (token == "g")
	{
		stream >> m_group_current;
		Objects[m_object_current].Groups[m_group_current].Name = m_object_current;
	}
	else if (token == "v")
	{
		glm::vec3 pos;
		stream >> pos.x >> pos.y >> pos.z;
		Positions.push_back(pos);
	}
	else if (token == "vt")
	{
		glm::vec2 tex;
		stream >> tex.x >> tex.y;
		TexCoords.push_back(tex);
	}
	else if (token == "vn")
	{
		glm::vec3 nor;
		stream >> nor.x >> nor.y >> nor.z;
		Normals.push_back(nor);
	}
	else if (token == "f")
	{
		Face face;
		while (stream >> token)
		{
			FacePoint point;

			std::size_t l1 = token.find('\/');
			if (l1 == std::string::npos)
			{
				// only position
				point.Index_v = std::stoi(token);
				//point.Index_vt = 0;
				//point.Index_vn = 0;
				face.Points.push_back(point);
			}
			else
			{
				std::size_t l2 = token.find_first_of('\/', l1 + 1);
				if (l2 == std::string::npos)
				{
					// position + texcoords
					point.Index_v = std::stoi(token.substr(0, l1));
					point.Index_vt = std::stoi(token.substr(l1 + 1, token.size() - l1 - 1));
					//point.Index_vn = 0;
					face.Points.push_back(point);
				}
				else if (l2 - l1 == 1)
				{
					// position + NO texcoords + normal
					point.Index_v = std::stoi(token.substr(0, l1));
					//point.Index_vt = 0;
					point.Index_vn = std::stoi(token.substr(l2 + 1, token.size() - l2 - 1));
					face.Points.push_back(point);
				}
				else
				{
					// position + texcoords + normal
					point.Index_v = std::stoi(token.substr(0, l1));
					point.Index_vt = std::stoi(token.substr(l1 + 1, l2 - l1 - 1));
					point.Index_vn = std::stoi(token.substr(l2 + 1, token.size() - l2 - 1));
					face.Points.push_back(point);
				}
			}

		}
		Objects[m_object_current].Groups[m_group_current].Faces[m_material_current][face.Points.size()].push_back(face);
	}
	else if (token == "usemtl")
	{
		stream >> m_material_current;
	}
	else if (token == "mtllib")
	{
		stream >> m_mtl_filename;
	}
	else if (token == "newmtl")
	{
		stream >> m_material_current;
		MaterialLibrary[m_material_current].Name = m_material_current;
	}
	else if (token == "Ka")
	{
		glm::vec3 Ka;
		stream >> Ka.x >> Ka.y >> Ka.z;
		MaterialLibrary[m_material_current].Ka = Ka;
	}
	else if (token == "Kd")
	{
		glm::vec3 Kd;
		stream >> Kd.x >> Kd.y >> Kd.z;
		MaterialLibrary[m_material_current].Kd = Kd;
	}
	else if (token == "Ks")
	{
		glm::vec3 Ks;
		stream >> Ks.x >> Ks.y >> Ks.z;
		MaterialLibrary[m_material_current].Ks = Ks;
	}
	else if (token == "Ns")
	{
		stream >> MaterialLibrary[m_material_current].Ns;
	}
	else if (token == "d")
	{
		stream >> MaterialLibrary[m_material_current].d;
	}
	else if (token == "Tr")
	{
		float Tr = 0;
		stream >> Tr;
		MaterialLibrary[m_material_current].d = 1 - Tr;
	}
	else if (token == "map_Ka")
	{
		stream >> MaterialLibrary[m_material_current].map.Ka;
	}
	else if (token == "map_Kd")
	{
		stream >> MaterialLibrary[m_material_current].map.Kd;
	}
	else if (token == "map_Ks")
	{
		stream >> MaterialLibrary[m_material_current].map.Ks;
	}
	else if (token == "map_Ns")
	{
		stream >> MaterialLibrary[m_material_current].map.Ns;
	}
	else if (token == "map_d")
	{
		stream >> MaterialLibrary[m_material_current].map.d;
	}
	else if (token == "map_bump" || token == "bump")
	{
		stream >> MaterialLibrary[m_material_current].map.bump;
	}
	else if (token == "illum")
	{
		stream >> MaterialLibrary[m_material_current].illum;
	}

}


