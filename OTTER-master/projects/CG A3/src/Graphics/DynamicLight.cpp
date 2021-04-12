#include "DynamicLight.h"
#include <Utilities/Util.cpp>


DynamicLight::DynamicLight(GameObject m)
{
	Mesh = m;

	int r1 = rand() % 255 + 0;
	int r2 = rand() % 255 + 0;
	int r3 = rand() % 255 + 0;

	Pointlight._lightCol = glm::vec4(r1, r2, r3, 0.0);

	r1 = rand() % 14 - 14;
	r2= rand() % 14 - 14;
	r3 = rand() % 5;

	setLightPosition(glm::vec4(r1, r2, r3, 0.0));

	setMeshScale();
}

void DynamicLight::setMeshScale()
{
	float constantVar = 1.0, linearVar = 0.7, quadraticVar = 1.8, lightMax, radius;

	lightMax = std::fmaxf(std::fmaxf(Pointlight._lightCol.r, Pointlight._lightCol.g), Pointlight._lightCol.b);

	radius = (-linearVar + std::sqrtf(linearVar * linearVar - 4 * quadraticVar * (constantVar - (256.0 / 5.0) * lightMax))) / (2 * quadraticVar);

	Mesh.get<Transform>().SetLocalScale(radius, radius, radius);

}

void DynamicLight::setMeshLocation()
{
	Mesh.get<Transform>().SetLocalPosition(getLocation().x, getLocation().y, getLocation().z);
}

void DynamicLight::setLightPosition(glm::vec3 p)
{
	Pointlight._lightPos = glm::vec4(p.x, p.y, p.z, 0.0);
	setMeshLocation();
}
