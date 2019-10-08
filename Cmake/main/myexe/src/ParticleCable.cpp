#include "ParticleCable.h"

ParticleCable::ParticleCable(Particle* particle1, Particle* particle2, float maxLength,
                             float restitution)
    : ParticleLink(particle1, particle2)
{
    this->maxLength = maxLength;
    this->restitution = restitution;
}

void ParticleCable::addContact()
{
    if (this->currentLength() >= this->maxLength) { 
		ParticleContact contact = ParticleContact();
	}
}
