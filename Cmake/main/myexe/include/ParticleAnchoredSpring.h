#pragma once

#include "Particle.h"
#include "ParticleForceGenerator.h"
#include "Vector3D.h"
class ParticleAnchoredSpring : public ParticleForceGenerator
{
private:
    Vector3D m_AnchoredPoint;
    double m_LengthSpring;
    double m_ConstantSpring;

public:
    // Constructeur a trois arguments pour la classe PaticleAnchoredSpring
    // Param : p_AnchoredPoint : La position du point d'ancrage du ressort
    // Param : p_LengthSpring : La longueur au repos du ressort
    // Param : p_ConstantSpring : Une constante propre au ressort
    ParticleAnchoredSpring(Vector3D p_AnchoredPoint, double p_LengthSpring,
                           double p_ConstantSrping);

    // Fonction pour mettre a jour la force
    // Param : p_Particle : la particule sur la quelle on veut mettre a jour la force
    void updateForce(Particle* p_Particle, float p_Duration) override;
};
