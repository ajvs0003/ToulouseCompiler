#version 400



in vec3 position;

uniform vec3 fontColor;
uniform float FogMax;
uniform float FogMin;


layout (location = 0) out vec4 fColor;

float getFogFactor(float d)
{
   

    if (d>FogMax) return 1;
    if (d<FogMin) return 0;

    return (d-FogMin) / (FogMax - FogMin);
}





void main() {
	float d = abs(position.z);
    float alpha = getFogFactor(d);
	fColor  = vec4(fontColor, alpha);








}

