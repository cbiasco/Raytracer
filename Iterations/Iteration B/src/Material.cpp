//
// Material.cpp
//
// Code by Caleb Biasco (biasc007) for Assignment-1B of CSCI5607

/*
 * The Material class holds color values that correspond specifically to
 * materials for objects in a scene.
 */

#include "Material.h"

Material::Material()
{
	m_dr = 0;
	m_dg = 0;
	m_db = 0;
	m_sr = 0;
	m_sg = 0;
	m_sb = 0;
	m_ka = 0;
	m_kd = 0;
	m_ks = 0;
	m_n = 0;
}

Material::Material(double dr, double dg, double db, double sr, double sg, double sb,
			double ka, double kd, double ks, double n)
{
	m_dr = dr;
	m_dg = dg;
	m_db = db;
	m_sr = sr;
	m_sg = sg;
	m_sb = sb;
	m_ka = ka;
	m_kd = kd;
	m_ks = ks;
	m_n = n;
}

Material::~Material() {}

Color Material::getAmbient()
{
	return Color(m_dr*m_ka, m_dg*m_ka, m_db*m_ka);
}

Color Material::getDiffuse()
{
	return Color(m_dr, m_dg, m_db);
}

Color Material::getSpecular()
{
	return Color(m_sr, m_sg, m_sb);
}

bool Material::outOfBounds()
{
	return m_dr < 0 || m_dr > 1 || m_dg < 0 ||
		m_dg > 1 || m_db < 0 || m_db > 1 || m_sr < 0 || m_sr > 1 || m_sg < 0 ||
		m_sg > 1 || m_sb < 0 || m_sb > 1;
}