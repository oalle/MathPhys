#pragma once
#include "Particle.h"
class ParticleForceGenerator
{

public :
	virtual void updateForce(Particle particule, float duration)=0;
};

