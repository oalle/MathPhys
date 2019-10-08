#include "GravityForce.h"

//Constructeur par defaut de la classe GravityForce
GravityForce::GravityForce()
{
	GravityVector = Vector3D(0.0, -9.81, 0.0);
}

//Destructeur par defaut de la classe GravityForce
GravityForce::~GravityForce()
{

}

//Fonction pour mettre a jour la force 
//Param : p_Particule : la particule sur la quelle on va mettre a jour la force
void GravityForce::updateForce(Particle* p_Particule, float p_Duration)
{
	if (p_Particule->getMasse() != 0)
	{
		p_Particule->addForce(GravityVector);
	}
}
