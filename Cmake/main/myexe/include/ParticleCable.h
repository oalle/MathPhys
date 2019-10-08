#pragma once
#include"ParticleLink.h"
class ParticleCable : ParticleLink
{
private :
	float maxLength;
	float restitution;

public:
	void addContact();
};

