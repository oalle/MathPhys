#pragma once
#include "ParticleForceGenerator.h"
class ParticleBuoyancy :
	public ParticleForceGenerator
{
private:
	int m_MaxDepth;
	int m_ObjectVolume;
	int m_WaterHeight;
	int m_Density;

public:
	ParticleBuoyancy(int p_MaxDepth, int p_ObjectVolume, int p_WaterHeight, int p_Density);

	void updateForce(Particle * p_Particle, float p_Duration);
};

