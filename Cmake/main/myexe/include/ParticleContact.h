#pragma once

#include "Particle.h"
#include "Vector3D.h"

class ParticleContact
{

private:
    Particle* m_Particles[2];
    double m_CoefficientRestitution;
    Vector3D m_ContactNormale;
    double m_Penetration;

public:
    // Constructeur a quatre arguments de la classe ParticleContact
    // Param : p_Particles[2] : Le tableau des deux particules liees au contact
    // Param : p_CoefficientRestitution : Le coefficient de restitution du contact
    // Param : p_ContactNormale : Le vecteur de la normale au contact
    // Param : p_Penetration : Le coefficient de penetration entre less deux particules
    ParticleContact(Particle* p_Particles[2], double p_CoefficientRestitution,
                    Vector3D p_ContactNormale, double m_Penetration);

    // Fonction pour resoudre un contact entre deux particules
    void Resolve(float p_Duration);

    // Fonction qui calcul la velocite d'approche des deux particules
    double CalculVS() const;

    // Fonction qui resoud la velocite que less deux particule doivent avoir pour resoudre le
    // contact
    void ResolveVelocity(float p_Duration);

    // Fonction qui resoud les cas d'interpenetration entre deux particules
    void ResolveInterpenetration();
};
