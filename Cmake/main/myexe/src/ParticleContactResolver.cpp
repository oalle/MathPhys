#include "ParticleContactResolver.h"

RegistreContacts ParticleContactResolver::registreContacts;
int ParticleContactResolver::m_Iteration;
int ParticleContactResolver::m_IterationMax;

// Constructeur par defaut de la classe ParticleContactResolver
ParticleContactResolver::ParticleContactResolver()
{
    this->m_Iteration = 0;
    this->m_IterationMax = 5;
}

// Constructeur a un argument de la classe ParticleContactResolver
// Param : p_IterationMax : le nombre d'iteration maximum que l'ont effectuera
ParticleContactResolver::ParticleContactResolver(int p_IterationMax)
{
    this->m_Iteration = 0;
    this->m_IterationMax = p_IterationMax;
}

// Fonction qui resoud les contacts se trouvant dans le registre des contacts
void ParticleContactResolver::resolveContact(float p_Duration)
{
    m_Iteration = 0;
    m_IterationMax = 5;

    RegistreContacts::Registre rc = registreContacts.GetListEnregistrementContact();

    while (m_Iteration < m_IterationMax && m_Iteration < rc.size())
    {
        rc[m_Iteration].contact->Resolve(p_Duration);
        m_Iteration++;
    }
}

// Methode qui ajoute un contact au registre des contacts
// Param : le contact a ajouter
void ParticleContactResolver::AddContact(ParticleContact* p_Contact)
{
    RegistreContacts::EnregistrementContact p;
    p.contact = p_Contact;
    registreContacts.AddEnregistrementContact(&p);
}