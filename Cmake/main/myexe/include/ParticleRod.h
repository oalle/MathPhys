#pragma once
#include "ParticleLink.h"
class ParticleRod : public ParticleLink
{
private :
	float length;

public :
	void addContact();
};

