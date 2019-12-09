
#pragma once
#include "Particle.h"
#include "ParticleContactGenerator.h"
class ParticleLink : public ParticleContactGenerator
{
protected:
    Particle* m_Particle[2];

public:
    // Constructeur par defaut de la classe ParticleLink
    ParticleLink();

    // Constructeur a deux arguments pour la classe ParticleLink
    // Param : particle1 : La premiere particule liee au contact
    // Param : particle2 : La deuxieme particule liee au contact
    ParticleLink(Particle* particle1, Particle* particle2);

    // Destructeur par defaut de la classe ParticleLink
    ~ParticleLink();

    // Fonction qui calcul la longueur actuelle entre les deux particules
    float currentLength() const;
};
