#version 400
layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vNormal;
layout(location = 2) in vec2 vTexCoord;
layout(location = 3) in vec3 vTangent;

uniform vec3 lightPosition;
uniform mat4 mvpMatrix;
uniform mat4 mModelView;

out vec3 position;
out vec3 lDir;
out vec3 vDir;
out vec2 texCoord;
out vec3 lPosition;


void main(){

lPosition = lightPosition;

position = vec3( mModelView * vec4(vPosition,1.0) );
vec3 normal = vec3( mModelView*vec4(vNormal,0.0) );
vec3 tangent = vec3( mModelView*vec4(vTangent,0.0) );
vec3 binormal = normalize( cross(normal,tangent) );
mat3 TBN = transpose( mat3(tangent,binormal,normal) );
lDir = normalize(TBN * (lightPosition - position));
vDir = normalize (TBN *(-position) );



texCoord = vTexCoord;
gl_Position = mvpMatrix * vec4(vPosition,1.0);


}
