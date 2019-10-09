#pragma once
#include "ParticleForceGenerator.h"
class ParticleBuoyancy :
	public ParticleForceGenerator
{
private:
	double m_MaxDepth;
	double m_ObjectVolume;
	double m_WaterHeight;
	double m_Density;

public:
	ParticleBuoyancy(double p_MaxDepth, double p_ObjectVolume, double p_WaterHeight, double p_Density);

	void updateForce(Particle* p_Particle, float p_Duration) override;
};

