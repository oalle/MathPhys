#include "ParticleContactResolver.h"

typedef std::vector<ParticleContact> RegistreContacts;
RegistreContacts ParticleContactResolver::registreContacts;
int ParticleContactResolver::m_Iteration;
int ParticleContactResolver::m_IterationMax;

//Constructeur par defaut de la classe ParticleContactResolver
ParticleContactResolver::ParticleContactResolver()
{
    this->m_Iteration = 0;
    this->m_IterationMax = 5;
}

//Constructeur a un argument de la classe ParticleContactResolver
//Param : p_IterationMax : le nombre d'iteration maximum que l'ont effectuera
ParticleContactResolver::ParticleContactResolver(int p_IterationMax)
{
    this->m_Iteration = 0;
    this->m_IterationMax = p_IterationMax;
}

//Fonction qui resoud les contacts se trouvant dans le registre des contacts 
void ParticleContactResolver::resolveContact(float p_Duration)
{
    m_Iteration = 0;
	m_IterationMax = 5;

    while (m_Iteration < m_IterationMax && m_Iteration < registreContacts.size()) {
        registreContacts[m_Iteration].Resolve(p_Duration);
        m_Iteration++;
	}
}