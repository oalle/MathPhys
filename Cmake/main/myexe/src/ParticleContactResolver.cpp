#include "ParticleContactResolver.h"

ParticleContactResolver::ParticleContactResolver()
{
    this->m_Iteration = 0;
    this->m_IterationMax = 5;
}

ParticleContactResolver::ParticleContactResolver(double p_IterationMax)
{
    this->m_Iteration = 0;
    this->m_IterationMax = p_IterationMax;
}

void ParticleContactResolver::resolveContact(float p_Duration)
{
    m_Iteration = 0;

    while (m_Iteration < m_IterationMax && m_Iteration < registreContacts.size()) {
        registreContacts[m_Iteration].Resolve(p_Duration);
        m_Iteration++;
	}
}