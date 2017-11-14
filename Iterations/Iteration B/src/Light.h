#pragma once
//
// Light.h
//
// Code by Caleb Biasco (biasc007) for Assignment-1B of CSCI5607

/*
 * The Light class is a superclass of all lighting objects for
 * the scene. Any general lighting functions should be specified
 * here.
 */

#include <vector>
#include "Color.h"
#include "Vec3.h"
class Object;

using std::vector;

class Light
{
public:
	Light();
	Light(Color c);
	virtual ~Light();
	
	// Pure virtual function for calculating the L vector from the light.
	virtual Vec3 getL(Vec3 intersectionPoint) = 0;
	
	// Pure virtual function for calculating shadows cast onto the object.
	virtual double shadow(vector<Object*> objects, Vec3 intersectionPoint, int index) = 0;

	Color m_c; // the color of the light
};

