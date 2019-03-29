#version 400
layout(location = 0) in vec3 vPosition;
uniform mat4 mModelViewProj;
uniform vec3 vColor;
uniform float pointSize;
out vec4 destinationColor;
void main() {
	gl_PointSize = pointSize;
	destinationColor = vec4(vColor, 1.0);
	gl_Position = mModelViewProj * vec4(vPosition, 1.0);
}