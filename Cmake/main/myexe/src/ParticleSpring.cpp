#include "ParticleSpring.h"

// Constructeur a trois arguments pour la classe ParticleSpring
// Param : p_OtherParticle : L'autre particule reliee au ressort
// Param : p_WidthSpring : La longueur du ressort
// Param : p_ConstantSpring : la constrante propre au ressort
ParticleSpring::ParticleSpring(Particle p_OtherParticle, double p_WidthSpring,
                               double p_ConstantSpring)
{
    m_OtherParticle = p_OtherParticle;
    m_WidthSpring = p_WidthSpring;
    m_ConstantSpring = p_ConstantSpring;
}

// Fonction pour mettre a jour la force sur la particule
// Param : p_Particle : La particule sur la quelle on veut mettre a jour la force
void ParticleSpring::updateForce(Particle* p_Particle, float p_Duration)
{
    // Calcul de ||d||
    Vector3D l_Distance = p_Particle->getPosition() - m_OtherParticle.getPosition();
    double l_NormeDistance = l_Distance.norme();

    // Calcul de ^d
    Vector3D l_DistanceUnitaire = l_Distance;
    l_DistanceUnitaire.normalisation();

    // Calcul de ||d|| - l0
    double temp = l_NormeDistance - m_WidthSpring;

    // Calcul de (||d|| - l0) * ^d
    l_DistanceUnitaire.mulScalaire(temp);

    // Calcul de -K * (||d|| - l0) * ^d
    l_DistanceUnitaire.mulScalaire(-m_ConstantSpring);

    // Add force to the particle
    p_Particle->addForce(l_DistanceUnitaire);
}
