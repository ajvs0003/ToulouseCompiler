#pragma once





enum PagRevObjParts : int {
	PAG_BODY = 0,
	PAG_TOP_FAN = 1,
	PAG_BOTTOM_FAN = 2,
	PAG_ALL_PARTS = 3,
	test = 99,//Ha sido añadido para poder escribir el perfil de subdivision para meshlab
};

enum PagShaderDebugOption : int {
	PAG_DEBUG_NORMALS = 0,
	PAG_DEBUG_TEX_COORDS = 1,
	PAG_DEBUG_TANGENTS = 2,
	PAG_DEBUG_MAGIC = 3
};

enum PagLightType : int {
	PAG_POINT_LIGHT = 0,
	PAG_SPOT_LIGHT = 1,
	PAG_DIRECTIONAL_LIGHT = 2,
	PAG_AMBIENT_LIGHT = 3
};




enum NameMaterial : int {
	WOOD_LIGHT = 0
	
};
enum NameTexture : int {//para las texturas
	TEXT ,TEXT2,TEXT3
	
};



#define PAG_PRIMITIVE_RESTART 0xFFFFFFFF
#define PAG_TEXTURE_FOLDER (std::string) "Textures/"
#define PAG_COVERS_FOLDER (std::string) "Covers/"
