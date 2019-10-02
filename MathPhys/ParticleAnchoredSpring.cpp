#include "ParticleAnchoredSpring.h"

ParticleAnchoredSpring::ParticleAnchoredSpring(Vecteur3D p_AnchoredPoint, int p_WidthSpring, int p_ConstantSpring)
{
	m_AnchoredPoint = p_AnchoredPoint;
	m_WidthSpring = p_WidthSpring;
	m_ConstantSpring = p_ConstantSpring;
}

void ParticleAnchoredSpring::updateForce(Particle * p_Particule, float p_Duration) 
{
	//Calcul de ||d||
	Vecteur3D l_Distance = p_Particule->getPosition() - m_AnchoredPoint;
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
	p_Particule->addForce(l_DistanceUnitaire);
}
