#pragma once
#include "Particle.h"
class ParticleForceGenerator
{

public :
	virtual void updateForce(Particle* p_Particule, float duration)=0;
};

