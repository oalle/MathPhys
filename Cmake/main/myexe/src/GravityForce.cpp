#include "GravityForce.h"

GravityForce::GravityForce()
{
	GravityVector = Vector3D(0.0, -9.81, 0.0);
}

GravityForce::~GravityForce()
{

}

void GravityForce::updateForce(Particle* particule, float duration)
{
	if (particule->getMasse() != 0)
	{
		particule->addForce(GravityVector);
	}
}
