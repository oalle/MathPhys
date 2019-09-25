#include"GravityForce.h";

GravityForce::GravityForce()
{
	GravityVector = Vecteur3D(0.0, -9.81, 0.0);
}

GravityForce::~GravityForce()
{

}

void GravityForce::updateForce(Particule* particule, float duration)
{
	particule->integrate(duration);
}