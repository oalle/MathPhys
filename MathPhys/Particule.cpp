#include "Particule.h"

Particule::Particule()
{
}


Particule::~Particule()
{
}

Particule::Particule(const Particule &particule)
{
	this->Acceleration = particule.Acceleration;
	this->Damping = particule.Damping;
	this->Masse = particule.Masse;
	this->InverseMasse = particule.InverseMasse;
	this->Position = particule.Position;
	this->Velocity = particule.Velocity;
}
void Particule::operator=(const Particule &particule)
{
	this->Acceleration = particule.Acceleration;
	this->Damping = particule.Damping;
	this->Masse = particule.Masse;
	this->InverseMasse = particule.InverseMasse;
	this->Position = particule.Position;
	this->Velocity = particule.Velocity;
}

float Particule::getMasse()
{
	return this->Masse;
}
void Particule::setMasse(float newMasse)
{
	this->Masse = newMasse;
}

float Particule::getInverseMasse()
{
	return this->InverseMasse;
}
void Particule::setInverseMasse(float newInverseMasse)
{
	this->InverseMasse = newInverseMasse;
}

float Particule::getDamping()
{
	return this->Damping;
}
void Particule::setDamping(float newDamping)
{
	this->Damping = newDamping;
}

Veccteur3D Particule::getPosition()
{
	return this->Position;
}
void Particule::setPosition(Veccteur3D newPosition)
{
	this->Position = newPosition;
}

Veccteur3D Particule::getVelocity()
{
	return this->Velocity;
}
void Particule::setVelocity(Veccteur3D newVelocity)
{
	this->Velocity = newVelocity;
}

Veccteur3D Particule::getAcceleration()
{
	return this->Acceleration;
}
void Particule::setAcceleration(Veccteur3D newAcceleration)
{
	this->Acceleration = newAcceleration;
}


void Particule::integrer(float frameTime)
{
	this->InverseMasse = 1 / this->Masse;

	// update position
	this->Position = this->Position + this->Velocity.mulScalaire(frameTime);

	// update velocity
	this->Velocity = this->Velocity.mulScalaire(pow(this->Damping, frameTime)) + this->Acceleration.mulScalaire(frameTime);
}