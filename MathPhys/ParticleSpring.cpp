#include "ParticleSpring.h"

void ParticleSpring::updateForce(Particle* p_Particle, float p_Duration)
{
	//Calcul de ||d||
	Vecteur3D l_Distance = p_Particle->getPosition() - m_OtherParticle.getPosition();
	double l_NormeDistance = l_Distance.norme();

	//Calcul de ^d
	Vecteur3D l_DistanceUnitaire = l_Distance;
	l_DistanceUnitaire.mulScalaire(1 / l_NormeDistance);

	//Calcul de ||d|| - l0
	double temp = l_NormeDistance - m_WidthSpring;

	//Calcul de (||d|| - l0) * ^d
	l_DistanceUnitaire.mulScalaire(temp);

	//Calcul de -K * (||d|| - l0) * ^d
	l_DistanceUnitaire.mulScalaire(-m_ConstantSpring);

	//Add force to the particle
	p_Particle->addForce(l_DistanceUnitaire);
}
