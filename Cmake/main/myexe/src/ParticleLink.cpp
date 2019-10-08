#include "ParticleLink.h"

ParticleLink::ParticleLink()
{
	this->m_Particle[0] = nullptr;
	this->m_Particle[1] = nullptr;
}

ParticleLink::ParticleLink(Particle* particle1, Particle* particle2)
{
	this->m_Particle[0] = particle1;
	this->m_Particle[1] = particle2;
}

ParticleLink::~ParticleLink()
{
}

float ParticleLink::currentLength() const
{
	float length = 0;
	Vector3D PosPartToOtherPart = m_Particle[1]->getPosition() - m_Particle[0]->getPosition();

	return PosPartToOtherPart.norme();
}
