#include "ParticleLink.h"

ParticleLink::ParticleLink()
{
	this->particle[0] = nullptr;
	this->particle[1] = nullptr;
}

ParticleLink::ParticleLink(Particle* particle1, Particle* particle2)
{
	this->particle[0] = particle1;
	this->particle[1] = particle2;
}

ParticleLink::~ParticleLink()
{
}

float ParticleLink::currentLength() const
{
	float length = 0;
	Vector3D PosPartToOtherPart = particle[1]->getPosition() - particle[0]->getPosition();

	return PosPartToOtherPart.norme();
}
