#version 400
in vec3 position;
in vec3 normal;

uniform vec3 Ka;
uniform vec3 Kd;
uniform vec3 Ks;
uniform float shininess;

uniform float c1;
uniform float c2;
uniform float c3;
uniform vec3 Ia;
uniform vec3 Id;
uniform vec3 Is;
uniform vec3 lightPosition;
uniform vec3 lightDirection;
uniform float spotAngle;
uniform float cosGamma;


layout (location = 0) out vec4 fragColor;

subroutine vec3 selectTypeIlumination();
subroutine uniform selectTypeIlumination diffuseSpecularUniform;

vec3 n(){
	vec3 n;

	if(gl_FrontFacing){
		n = normalize(normal);
	
	}else{
		n = normalize(-normal);
	}
	return n;
}

subroutine(selectTypeIlumination)
vec3 ambient(){

	vec3 ambient = (Ia * Ka);
	return ambient;
}


subroutine(selectTypeIlumination)
vec3 diffuseAndSpecularPointLight(){

	vec3 l = normalize(lightPosition-position);
	vec3 v = normalize(-position);
	vec3 r = reflect(-l,n());

	
	vec3 diffuse = (Id * Kd * max( dot(l,n()),0.0));
	vec3 specular = (Is * Ks * pow( max(dot(r,v),0.0),shininess) );

	float distance = distance(lightPosition,position);
	float total = c1+(c2*distance)+(c3*pow(distance,2));
	float factor = min(1/total,1);

	return factor*(diffuse + specular);

}

subroutine(selectTypeIlumination)
vec3 diffuseAndSpecularDirectionalLight(){

	vec3 l = -lightDirection;
	vec3 v = normalize(-position);
	vec3 r = reflect(-l,n());

	vec3 diffuse = (Id * Kd * max( dot(l,n()),0.0));
	vec3 specular = (Is * Ks * pow( max(dot(r,v),0.0),shininess) );

	float distance = distance(lightPosition,position);
	float total = c1+(c2*distance)+(c3*pow(distance,2));
	float factor = min(1/total,1);

	return factor*(diffuse + specular);

}

subroutine(selectTypeIlumination)
vec3 diffuseAndSpecularSpotLight(){

	

	vec3 l = normalize(lightPosition-position);
	vec3 d = lightDirection;
	float spotFactor = 1.0;


	if(dot(-l,d) < cosGamma){ spotFactor = 0.0; }

	
	vec3 v = normalize(-position);
	vec3 r = reflect(-l,n());

	vec3 diffuse = (Id * Kd * max( dot(l,n()),0.0));
	vec3 specular = (Is * Ks * pow( max(dot(r,v),0.0),shininess) );

	return spotFactor * (diffuse + specular);

}


void main(){

	fragColor = vec4(diffuseSpecularUniform(),1.0);

}