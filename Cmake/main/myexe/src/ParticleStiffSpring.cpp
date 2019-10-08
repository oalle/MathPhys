#include "ParticleStiffSpring.h"

//Constructeur a trois arguments pour la classe ParticleStiffSpring
//Param : p_AnchoredPoint : Le point d'ancrage du ressort
//Param : p_Damping : Le damping
//Param : p_ConstantSpring : La constante propre au ressort
ParticleStiffSpring::ParticleStiffSpring(Vector3D p_AnchoredPoint, double p_Damping, double p_ConstantSpring)
{
	m_AnchoredPoint = p_AnchoredPoint;
	m_ConstantSpring = p_ConstantSpring;
	m_Damping = p_Damping;
}

//Fonction pour mettre a jour la force du mouvement harmonique avec damping
//Param : p_Particle : La particule sur la quelle on souhaite mettre a jour la force
void ParticleStiffSpring::updateForce(Particle* p_Particle, float p_Duration)
{
	// calcul acceleration resultante
	Vector3D l_accelResultante = p_Particle->getPosition().mulScalaireResult(-this->m_ConstantSpring) - p_Particle->getVelocity().mulScalaireResult(this->m_Damping);

	// masse x acceleration resultante
	l_accelResultante.mulScalaire(p_Particle->getMasse());

	// application de la force
	p_Particle->addForce(l_accelResultante);
}
