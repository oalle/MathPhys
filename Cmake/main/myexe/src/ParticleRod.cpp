#include "ParticleRod.h"

ParticleRod::ParticleRod(Particle * p_Particle1, Particle * p_Particle2, float p_Length) : ParticleLink(p_Particle1, p_Particle2)
{
	m_Length = p_Length;
}

void ParticleRod::addContact()
{
	Vector3D l_Temp = m_Particle[0]->getPosition() - m_Particle[1]->getPosition();
	l_Temp.normalisation();
	ParticleContact contact = ParticleContact(this->m_Particle, 0, l_Temp, 0);
	ParticleContactResolver::AddContact(contact);

	
}
