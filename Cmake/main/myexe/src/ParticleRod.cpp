#include "ParticleRod.h"

// Constructeur a trois arguments pour la classe ParticleRod
// Param : p_Particle1 : La premiere particule liee au contact
// Param : p_Particle2 : La deuxieme particule liee au contact
// Param : p_Length : La longueur fixe de la tige entre les deux particules
ParticleRod::ParticleRod(Particle* p_Particle1, Particle* p_Particle2, float p_Length)
    : ParticleLink(p_Particle1, p_Particle2)
{
    m_Length = p_Length;
}

// Fonction qui cree un contact et qui l'ajoute au registre des contacts
void ParticleRod::addContact()
{
    Vector3D l_Temp = m_Particle[0]->getPosition() - m_Particle[1]->getPosition();
    l_Temp.normalisation();
    ParticleContact l_Contact = ParticleContact(m_Particle, 0, l_Temp, 0);
    ParticleContactResolver::AddContact(&l_Contact);
}
