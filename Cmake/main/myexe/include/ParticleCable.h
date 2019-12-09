#pragma once
#include "ParticleLink.h"
class ParticleCable : public ParticleLink
{
private:
    float maxLength;
    float restitution;

public:
    // Constructeur a quatre arguments de la classe ParticleCable
    // Param : particle1 : La premiere particule liee au contact
    // Param : particle2 : La deuxieme particule liee au contact
    // Param : maxLength : La longueur maximale du cable entre les deux particules
    // Param : restitution : Le coefficient de restitution
    ParticleCable(Particle* particle1, Particle* particle2, float maxLength, float restitution);

    // Destructeur par defaut de la classe ParticleCable
    ~ParticleCable();

    // Fonction qui ajoute le contact dans le registre des contacts pour le resoudre
    void addContact();
};
