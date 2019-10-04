#include "ParticleStiffSpring.h"

//application mouvement harmonique avec damping
void ParticleStiffSpring::updateForce(Particle* p_Particle, float p_Duration)
{
	// calcul acceleration resultante
	Vector3D l_accelResultante = p_Particle->getPosition().mulScalaireResult(-this->m_ConstantSpring) - p_Particle->getVelocity().mulScalaireResult(this->m_Damping);

	// masse x acceleration resultante
	l_accelResultante.mulScalaire(p_Particle->getMasse());

	// application de la force
	p_Particle->addForce(l_accelResultante);
}
