#pragma once
#include "ParticleForceGenerator.h"
class ParticleSpring : public ParticleForceGenerator
{

private:
    Particle m_OtherParticle;
    double m_WidthSpring;
    double m_ConstantSpring;

public:
    // Constructeur a trois arguments pour la classe ParticleSpring
    // Param : p_OtherParticle : L'autre particule reliee au ressort
    // Param : p_WidthSpring : La longueur du ressort
    // Param : p_ConstantSpring : la constrante propre au ressort
    ParticleSpring(Particle p_OtherParticle, double p_WidthSpring, double p_ConstantSrping);

    // Fonction pour mettre a jour la force sur la particule
    // Param : p_Particle : La particule sur la quelle on veut mettre a jour la force
    void updateForce(Particle* p_Particle, float p_Duration) override;
};
