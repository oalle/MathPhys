#pragma once
#include "ParticleForceGenerator.h"
class ParticleSpring :
	public ParticleForceGenerator
{

private: 
	Particle otherParticle;
	const double k;
	double restLength;

public:
	ParticleSpring();
	void updateForce(Particle* particule, float duration);
};

