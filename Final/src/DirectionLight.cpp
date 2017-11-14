//
// DirectionLight.cpp
//
// Code by Caleb Biasco (biasc007) for Assignment-1 of CSCI5607

/*
 * The DirectionLight class is a Light subclass that holds the behavior
 * of a direction light.
 */

#include "DirectionLight.h"
#include <algorithm>

using std::max;

DirectionLight::DirectionLight(double x, double y, double z) : Light()
{
	m_dir = Vec3(x, y, z);
	m_dir.normalize();
}

DirectionLight::DirectionLight(double x, double y, double z, Color c) : Light(c)
{
	m_dir = Vec3(x, y, z);
	m_dir.normalize();
}

DirectionLight::DirectionLight(Vec3 v) : Light()
{
	m_dir = v;
	m_dir.normalize();
}

DirectionLight::DirectionLight(Vec3 v, Color c) : Light(c)
{
	m_dir = v;
	m_dir.normalize();
}

DirectionLight::DirectionLight(double l[7]) : Light(Color(l[4], l[5], l[6]))
{
	m_dir = Vec3(l[0], l[1], l[2]);
	m_dir.normalize();
}

DirectionLight::~DirectionLight() {}

Vec3 DirectionLight::getL(Vec3 &intersectionPoint)
{
	return m_dir*(-1);
}

double DirectionLight::shadow(Vec3 &intersectionPoint, Scene &scene, RayPayload &payload)
{
	double shadow;
	RayPayload sPayload;
	Vec3 L = getL(intersectionPoint);
	
	shadow = 1;
	
	for (int i = 0; i < scene.objects.size() && shadow > 0; i++)
	{
		sPayload.distance = -1;
		scene.objects[i]->intersection(L, intersectionPoint, sPayload);
		
		// Block if the obstruction is not the object itself and lies in the direction
		// of the light away from the object surface.
		if (i != payload.object && sPayload.distance > 0)
		{
			shadow -= scene.materials[sPayload.material]->m_alpha;
		}
	}
	
	return max(0.0, shadow);
}
