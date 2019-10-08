#pragma once
#include "ParticleLink.h"
class ParticleRod : public ParticleLink
{
private :
	float m_Length;

public :
	ParticleRod(Particle* p_Particle1, Particle* p_Particle2, float p_Length);
	void addContact();
};

