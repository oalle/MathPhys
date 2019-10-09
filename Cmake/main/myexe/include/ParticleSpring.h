#pragma once
#include "ParticleForceGenerator.h"
class ParticleSpring :
	public ParticleForceGenerator
{

private: 
	Particle m_OtherParticle;
	double m_WidthSpring;
	double m_ConstantSpring;

public:
	ParticleSpring(Particle p_OtherParticle, double p_WidthSpring, double p_ConstantSrping);
	void updateForce(Particle* p_Particle, float p_Duration);
};

