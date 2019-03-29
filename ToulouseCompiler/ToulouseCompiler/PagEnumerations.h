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

enum PagCameraOrbitType : int {
	PAG_ORBIT_HORIZONTAL = 0,
	PAG_ORBIT_VERTICAL = 1
};

enum PagMaterialName : int {
	PAG_RED_MAT = 0,
	PAG_BLUE_MAT = 1,
	PAG_GREEN_MAT = 2,
	PAG_GREY_MAT = 3,
	PAG_WHITE_MAT = 4,
	PAG_JARRONES_MANOLO_MAT = 5,
	PAG_CBBLE_MAT = 6,
	PAG_METAL_MAT = 7,
	PAG_LUXO_BALL_MAT = 8,
	PAG_LUXO_BALL_COVER_MAT = 9,
	PAG_RING_MAT = 10,
	PAG_ROCK_MAT = 11,
	PAG_WOOD_MAT = 12
};
enum NameMaterial : int {
	WOOD_LIGHT = 0,
	WOOD_DARK = 1,
	BLUE_DARK = 2,
	MATERIAL_GLASS = 3,
	MATERIAL_WALL = 4,
};
enum NameTexture : int {//para las texturas
	PAWN = 0,
	TABLE = 1,
	TEXT = 2,
	TEXT2 = 3,
	TEXT3 = 4,
	PLASTIC = 5,
	PLASTIC1 = 6,
	FCONDE = 7,
	GLASS = 8,
	JOY = 9,
	BLACK = 10,
	GRAY = 11,
	COPYRIGHT = 12,
	NCOPYRIGHT = 13,
};
#define PAG_PRIMITIVE_RESTART 0xFFFFFFFF
#define PAG_TEXTURE_FOLDER (std::string) "Textures/"
#define PAG_COVERS_FOLDER (std::string) "Covers/"
