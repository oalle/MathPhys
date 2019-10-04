#include "ParticleAnchoredSpring.h"

ParticleAnchoredSpring::ParticleAnchoredSpring(Vector3D p_AnchoredPoint, double p_WidthSpring, double p_ConstantSpring)
{
	m_AnchoredPoint = p_AnchoredPoint;
	m_WidthSpring = p_WidthSpring;
	m_ConstantSpring = p_ConstantSpring;
}

void ParticleAnchoredSpring::updateForce(Particle * p_Particle, float p_Duration) 
{
	//Calcul de ||d||
	Vector3D l_Distance = p_Particle->getPosition() - m_AnchoredPoint;
	double l_NormeDistance = l_Distance.norme();

	//Calcul de ^d
	Vector3D l_DistanceUnitaire = l_Distance;
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
