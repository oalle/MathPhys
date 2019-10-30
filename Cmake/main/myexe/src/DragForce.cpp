#include "DragForce.h"

//Constructeur par defaut de la classe DragForce
DragForce::DragForce()
{
	coeffDrag1 = 0;
	coeffDrag2 = 0;
}

//Constructeur a deux arguments de la classe DragForce
//Param : p_CoeffDrag1 : Le premier coefficient de drag
//Param : p_CoeffDrag2 : Le deuxieme coefficient de drag
DragForce::DragForce(float p_CoeffDrag1, float p_CoeffDrag2)
{
	this->coeffDrag1 = p_CoeffDrag1;
	this->coeffDrag2 = p_CoeffDrag2;
}

//Destructeur par defaut de la classe DragForce
DragForce::~DragForce()
{

}

//Fonction pour mettre a jour les forces
//Param : p_Particule : La particule sur la quelle on veut mettre a jour la force
//Param : p_Duration
void DragForce::updateForce(Particle* p_Particule, float p_Duration)
{
	Vector3D velocitypart = p_Particule->getVelocity();
	Vector3D force = Vector3D(velocitypart.getx(), velocitypart.gety(), velocitypart.getz());
	force.normalisation();
	force.mulScalaire((coeffDrag1 * velocitypart.norme() + coeffDrag2 * velocitypart.normecarre()) * -1);
	p_Particule->addForce(force);
}