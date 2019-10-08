#include "ParticleContactResolver.h"

ParticleContactResolver::ParticleContactResolver(double p_IterationMax=5) 
{
    this->m_Iteration = 0;
    this->m_IterationMax = p_IterationMax;
}

void ParticleContactResolver::resolveContact()
{
    m_Iteration = 0;

    while (m_Iteration < m_IterationMax && m_Iteration < registreContacts.size()) {
		registreContacts[m_Iteration].Resolve();
        m_Iteration++;
	}
}