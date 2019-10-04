#include "ParticleBuoyancy.h"

ParticleBuoyancy::ParticleBuoyancy(int p_MaxDepth, int p_ObjectVolume, int p_WaterHeight, int p_Density) 
{
	m_MaxDepth = p_MaxDepth;
	m_ObjectVolume = p_ObjectVolume;
	m_WaterHeight = p_WaterHeight;
	m_Density = p_Density;
}

void ParticleBuoyancy::updateForce(Particle* p_Particle, float p_Duration)
{
	double d = (p_Particle->getPosition() - m_WaterHeight - m_MaxDepth) / 2 * m_MaxDepth;

	if (d <= 0) {
		p_Particle->addForce(Vecteur3D(0,0,0));
	}
	else if (d >= 1)
	{
		p_Particle->addForce(m_ObjectVolume * m_Density);
	}
	else
	{
		p_Particle->addForce(d * m_ObjectVolume * m_Density);
	}
}
