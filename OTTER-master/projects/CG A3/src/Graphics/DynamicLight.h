#pragma once
#include <Scene.h>
#include <PointLight.h>
#include <Transform.h>
#include <Application.h>

class DynamicLight
{
	public:

	DynamicLight(GameObject);

	glm::vec4 getLocation(){return Pointlight._lightPos;}
	glm::vec4 getColor(){return Pointlight._lightCol;}
	GameObject getMesh(){return Mesh;}
	float getAmbientPow(){return Pointlight._ambientPow;}

	void setMeshScale();
	void setMeshLocation();
	void setLightPosition(glm::vec3 p);
	

	private:

	PointLight Pointlight;
	GameObject Mesh = Application::Instance().ActiveScene->CreateEntity("temp");;
};

