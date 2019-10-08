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

void DragForce::updateForce(Particle* particule, float duration)
{
	Vector3D velocitypart = particule->getVelocity();
	Vector3D force = Vector3D(velocitypart.getx(), velocitypart.gety(), velocitypart.getz());
	force.normalisation();
	force.mulScalaire((coeffDrag1 * velocitypart.norme() + coeffDrag2 * velocitypart.normecarre()) * -1);
	particule->addForce(force);
}
