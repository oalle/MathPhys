#include "ParticleLink.h"

//Constructeur par defaut de la classe ParticleLink
ParticleLink::ParticleLink()
{
	this->m_Particle[0] = nullptr;
	this->m_Particle[1] = nullptr;
}

//Constructeur a deux arguments pour la classe ParticleLink
//Param : particle1 : La premiere particule liee au contact
//Param : particle2 : La deuxieme particule liee au contact
ParticleLink::ParticleLink(Particle* particle1, Particle* particle2)
{
	this->m_Particle[0] = particle1;
	this->m_Particle[1] = particle2;
}

//Destructeur par defaut de la classe ParticleLink
ParticleLink::~ParticleLink()
{
}

//Fonction qui calcul la longueur actuelle entre les deux particules
float ParticleLink::currentLength() const
{
	float length = 0;
	Vector3D PosPartToOtherPart = m_Particle[1]->getPosition() - m_Particle[0]->getPosition();

	return PosPartToOtherPart.norme();
}
