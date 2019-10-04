#include "ParticleStiffSpring.h"

//application mouvement harmonique avec damping
void ParticleStiffSpring::updateForce(Particle* p_Particle, float p_Duration)
{
	Vector3D l_accelResultante = Vector3D(p_Particle->getPosition());

	l_accelResultante.mulScalaire(-this->m_ConstantSpring);


	// masse x acceleration resultante
	l_accelResultante.mulScalaire(p_Particle->getMasse());

	// application de la force
	p_Particle->addForce(l_accelResultante);
}
