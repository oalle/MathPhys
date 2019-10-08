#include "ParticleAnchoredSpring.h"


//Constructeur a trois arguments pour la classe PaticleAnchoredSpring
//Param : p_AnchoredPoint : La position du point d'ancrage du ressort
//Param : p_LengthSpring : La longueur au repos du ressort
//Param : p_ConstantSpring : Une constante propre au ressort
ParticleAnchoredSpring::ParticleAnchoredSpring(Vector3D p_AnchoredPoint, double p_LengthSpring, double p_ConstantSpring)
{
	m_AnchoredPoint = p_AnchoredPoint;
	m_LengthSpring = p_LengthSpring;
	m_ConstantSpring = p_ConstantSpring;
}

//Fonction pour mettre a jour la force
//Param : p_Particle : la particule sur la quelle on veut mettre a jour la force
void ParticleAnchoredSpring::updateForce(Particle * p_Particle, float p_Duration) 
{
	//Calcul de ||d||
	Vector3D l_Distance = p_Particle->getPosition() - m_AnchoredPoint;
	double l_NormeDistance = l_Distance.norme();

	//Calcul de ^d
	Vector3D l_DistanceUnitaire = l_Distance;
	l_DistanceUnitaire.normalisation();

	//Calcul de ||d|| - l0
	double temp = l_NormeDistance - m_LengthSpring;

	//Calcul de (||d|| - l0) * ^d
	l_DistanceUnitaire.mulScalaire(temp);

	//Calcul de -K * (||d|| - l0) * ^d
	l_DistanceUnitaire.mulScalaire(-m_ConstantSpring);

	//Add force to the particle
	p_Particle->addForce(l_DistanceUnitaire);
}
