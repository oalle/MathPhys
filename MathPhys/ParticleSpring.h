#pragma once
#include "ParticleForceGenerator.h"
class ParticleSpring :
	public ParticleForceGenerator
{

private: 
	Particle m_OtherParticle;
	int m_WidthSpring;
	int m_ConstantSpring;

private:
	ParticleSpring(Particle p_OtherParticle, int p_WidthSpring, int p_ConstantSrping);

	void updateForce(Particle* p_Particle, float p_Duration);
};

