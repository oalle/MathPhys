#include "DragForce.h"

DragForce::DragForce()
{
	coeffDrag1 = 0;
	coeffDrag2 = 0;
}

DragForce::DragForce(float coeffDrag1, float coeffDrag2)
{
	this->coeffDrag1 = coeffDrag1;
	this->coeffDrag2 = coeffDrag2;

}

DragForce::~DragForce()
{
}

void DragForce::updateForce(Particule* particule, float duration)
{
	Vecteur3D Force = Vecteur3D();
	Vecteur3D velocitypart = particule->getVelocity();
	Force = velocitypart.normalisation.mulScalaire((coeffDrag1 * velocitypart.norme() + coeffDrag2 * velocitypart.normecarre()) * -1);
	particule->addForce(Force);

}
