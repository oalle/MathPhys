#pragma once
#include "ParticleLink.h"
class ParticleRod : public ParticleLink
{
private:
    float m_Length;

public:
    // Constructeur a trois arguments pour la classe ParticleRod
    // Param : p_Particle1 : La premiere particule liee au contact
    // Param : p_Particle2 : La deuxieme particule liee au contact
    // Param : p_Length : La longueur fixe de la tige entre les deux particules
    ParticleRod(Particle* p_Particle1, Particle* p_Particle2, float p_Length);

    // Fonction qui cree un contact et qui l'ajoute au registre des contacts
    void addContact();
};
