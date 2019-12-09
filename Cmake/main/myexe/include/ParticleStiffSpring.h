#pragma once
#include "ParticleForceGenerator.h"

class ParticleStiffSpring : public ParticleForceGenerator
{
private:
    Vector3D m_AnchoredPoint;
    double m_Damping;
    double m_ConstantSpring;

private:
    // Constructeur a trois arguments pour la classe ParticleStiffSpring
    // Param : p_AnchoredPoint : Le point d'ancrage du ressort
    // Param : p_Damping : Le damping
    // Param : p_ConstantSpring : La constante propre au ressort
    ParticleStiffSpring(Vector3D p_AnchoredPoint, double p_Damping, double p_ConstantSrping);

    // Fonction pour mettre a jour la force du mouvement harmonique avec damping
    // Param : p_Particle : La particule sur la quelle on souhaite mettre a jour la force
    void updateForce(Particle* p_Particle, float p_Duration) override;
};
