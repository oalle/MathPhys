#include "ParticleCable.h"

//Constructeur a quatre arguments de la classe ParticleCable
//Param : particle1 : La premiere particule liee au contact
//Param : particle2 : La deuxieme particule liee au contact
//Param : maxLength : La longueur maximale du cable entre les deux particules
//Param : restitution : Le coefficient de restitution
ParticleCable::ParticleCable(Particle* particle1, Particle* particle2, float maxLength,
                             float restitution)
    : ParticleLink(particle1, particle2)
{
    this->maxLength = maxLength;
    this->restitution = restitution;
}

//Fonction qui ajoute le contact dans le registre des contacts pour le resoudre
void ParticleCable::addContact()
{
    if (this->currentLength() >= this->maxLength) { 
		Vector3D l_Temp = m_Particle[0]->getPosition() - m_Particle[1]->getPosition();
		l_Temp.normalisation();
		ParticleContact contact = ParticleContact(m_Particle, restitution, l_Temp , 0);
        ParticleContactResolver::AddContact(contact);
	}
}
