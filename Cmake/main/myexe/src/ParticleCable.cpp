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
		Vector3D l_Temp = m_Particle[0]->getPosition() - m_Particle[1]->getPosition();
		l_Temp.normalisation();
		ParticleContact contact = ParticleContact(m_Particle, restitution, l_Temp , 0);
        ParticleContactResolver::AddContact(contact);
	}
}
