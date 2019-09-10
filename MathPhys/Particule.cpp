#include "Particule.h"

Particule::Particule()
{
	Damping = 0;
	Masse = 0;
	InverseMasse = 0;

	this->Position = Vecteur3D(0, 0, 0);
}


Particule::~Particule()
{
}

Particule::Particule(Particule& particule)
{
	this->Acceleration = particule.Acceleration;
	this->Damping = particule.Damping;
	this->Masse = particule.Masse;
	this->InverseMasse = particule.InverseMasse;
	this->Position = particule.Position;
	this->Velocity = particule.Velocity;
}
void Particule::operator=(Particule& particule)
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

Vecteur3D Particule::getPosition()
{
	return this->Position;
}
void Particule::setPosition(Vecteur3D newPosition)
{
	this->Position = newPosition;
}

Vecteur3D Particule::getVelocity()
{
	return this->Velocity;
}
void Particule::setVelocity(Vecteur3D newVelocity)
{
	this->Velocity = newVelocity;
}

Vecteur3D Particule::getAcceleration()
{
	return this->Acceleration;
}
void Particule::setAcceleration(Vecteur3D newAcceleration)
{
	this->Acceleration = newAcceleration;
}


void Particule::integrer(float frameTime)
{
	this->InverseMasse = 1 / this->Masse;

	// update position
	Vecteur3D Temp = this->Velocity;
	Temp.mulScalaire(frameTime);
	this->Position = this->Position + Temp;

	// update velocity
	Vecteur3D VelocityTemp = this->Velocity;
	VelocityTemp.mulScalaire(pow(this->Damping, frameTime));

	Vecteur3D AccelerationTemp = this->Acceleration;
	AccelerationTemp.mulScalaire(frameTime);
	this->Velocity = VelocityTemp + AccelerationTemp;
}