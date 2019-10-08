
#pragma once
#include "ParticleContactGenerator.h"
#include "Particle.h"
class ParticleLink : public ParticleContactGenerator
{
protected :
	Particle* particle[2];

public :
	ParticleLink();
	ParticleLink(Particle * particle1, Particle * particle2);
	~ParticleLink();
	float currentLength() const;
};

