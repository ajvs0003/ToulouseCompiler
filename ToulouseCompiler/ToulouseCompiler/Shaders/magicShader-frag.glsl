#version 400

in vec4 position;
in vec3 normal;
in vec2 texCoord;
in vec3 tangent;
in vec4 destinationColor;

layout (location = 0) out vec4 fColor;

void main(){

fColor=destinationColor;
	
}