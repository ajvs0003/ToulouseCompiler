#version 400
in vec3 position;
in vec3 lDir;
in vec3 vDir;
in vec2 texCoord;
in vec3 lPosition;


uniform sampler2D TexSamplerColor;
uniform sampler2D TexSamplerBump;

uniform vec3 Ks;
uniform float shininess;

uniform float c1;
uniform float c2;
uniform float c3;
uniform vec3 Ia;
uniform vec3 Id;
uniform vec3 Is;

uniform vec3 lightDirection;
uniform float spotAngle;
uniform float cosGamma;


layout (location = 0) out vec4 fragColor;

subroutine vec3 selectTypeIlumination(vec4 textColor,vec4 normal);
subroutine uniform selectTypeIlumination diffuseSpecularUniform;

vec3 n(vec4 normal){
	vec3 n = normal.rgb;

	if(gl_FrontFacing){
		n = normalize(n);
	
	}else{
		n = normalize(-n);
	}
	return n;
}

subroutine(selectTypeIlumination)
vec3 ambient(vec4 textColor,vec4 normal){

	vec3 kad = textColor.rgb;

	vec3 ambient = (Ia * kad);
	return ambient;
}


subroutine(selectTypeIlumination)
vec3 diffuseAndSpecularPointLight(vec4 textColor,vec4 normal){

	vec3 kad = textColor.rgb;


	vec3 l = normalize( lDir );
	vec3 v = normalize( -vDir );
	vec3 r = reflect(-l,n(normal));

	
	vec3 diffuse = (Id * kad * max( dot(l,n(normal)),0.0));
	vec3 specular = (Is * Ks * pow( max(dot(r,v),0.0),shininess) );



	return diffuse + specular;

}

subroutine(selectTypeIlumination)
vec3 diffuseAndSpecularDirectionalLight(vec4 textColor,vec4 normal){
	vec3 kad = textColor.rgb;

	vec3 l = normalize( lDir );
	vec3 v = normalize( vDir );
	vec3 r = reflect(-l,n(normal));

	vec3 diffuse = (Id * kad * max( dot(l,n(normal)),0.0));
	vec3 specular = (Is * Ks * pow( max(dot(r,v),0.0),shininess) );



	return diffuse + specular;

}

subroutine(selectTypeIlumination)
vec3 diffuseAndSpecularSpotLight(vec4 textColor,vec4 normal){

	vec3 kad = textColor.rgb;

	vec3 l = normalize( lDir );

	vec3 d = lightDirection;

	float spotFactor = 1.0;


	if(dot(-l,d) < cosGamma){ spotFactor = 0.0; }

	
	vec3 v = normalize( vDir );
	vec3 r = reflect(-l,n(normal));

	vec3 diffuse = (Id * kad * max( dot(l,n(normal)),0.0));
	vec3 specular = (Is * Ks * pow( max(dot(r,v),0.0),shininess) );

	return spotFactor * (diffuse + specular);

}


void main(){

	vec4 textColor = texture(TexSamplerColor,texCoord);
	vec4 normal = (2.0 * texture(TexSamplerBump,texCoord)) - 1.0;
	fragColor = vec4(diffuseSpecularUniform(textColor,normal),textColor.w);

}