#version 400
layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vNormal;
layout(location = 2) in vec2 vTexCoord;
layout(location = 3) in vec3 vTangent;

uniform mat4 mvpMatrix;
uniform int debugOption;


out vec4 position;
out vec3 normal;
out vec2 texCoord;
out vec3 tangent;
out vec4 destinationColor;

void main()
{
	position=vec4(vPosition, 1.0);
	normal=vNormal;
	texCoord=vTexCoord;
	tangent=vTangent;

	if(debugOption==0){
		destinationColor= vec4(normal, 1.0);

		}
	if(debugOption==1){
		destinationColor= vec4(texCoord,0.0, 1.0);

	}

	if(debugOption==2){
		destinationColor= vec4(vTangent, 1.0);

	}

	gl_Position = mvpMatrix * vec4(vPosition, 1.0);
}