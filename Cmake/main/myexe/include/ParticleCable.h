#pragma once
#include "ParticleLink.h"
class ParticleCable :  public ParticleLink
{
private :
	float maxLength;
	float restitution;

public:
    ParticleCable(Particle * particle1, Particle * particle2, float maxLength, float restitution);
    ~ParticleCable();
	void addContact();
};

