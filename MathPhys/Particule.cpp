#include "Particule.h"

//Constructeur de la classe particule
Particule::Particule()
{
	Damping = 0;
	Masse = 0;
	InverseMasse = 0;

	this->Position = Vecteur3D(0, 0, 0);
	this->Velocity = Vecteur3D(0, 0, 0);

	// gravity
	this->Acceleration = Vecteur3D(0, -0.0098, 0);
}

//Destructeur de la classe particule
Particule::~Particule()
{
}

//Constructeur de recopie de la classe particule
//param : &particule : l'adresse de la particule qu'il faut recopier
Particule::Particule(Particule& particule)
{
	this->Acceleration = particule.Acceleration;
	this->Damping = particule.Damping;
	this->Masse = particule.Masse;
	this->InverseMasse = particule.InverseMasse;
	this->Position = particule.Position;
	this->Velocity = particule.Velocity;
}

//Surcharge de l'operateur d'assignation pour la classe particule
//param : &particule : l'adresse de la particule a assigner
void Particule::operator=(Particule& particule)
{
	this->Acceleration = particule.Acceleration;
	this->Damping = particule.Damping;
	this->Masse = particule.Masse;
	this->InverseMasse = particule.InverseMasse;
	this->Position = particule.Position;
	this->Velocity = particule.Velocity;
}

//Getteur pour l'attribut masse 
//return la valeur de la masse
float Particule::getMasse()
{
	return this->Masse;
}

//Setteur pour l'attribut masse
//param : newMasse : la nouvelle valeur de la masse
void Particule::setMasse(float newMasse)
{
	this->Masse = newMasse;
}

//Getteur pour l'attribut InverseMasse
//return la valeur de la masse inverse
float Particule::getInverseMasse()
{
	return this->InverseMasse;
}

//Setteur pour l'attribut InverseMasse
//param : newInverseMasse : la nouvelle valeur de la masse inverse
void Particule::setInverseMasse(float newInverseMasse)
{
	this->InverseMasse = newInverseMasse;
}

//Getteur pour l'attribut Damping
//return la valeur du damping
float Particule::getDamping()
{
	return this->Damping;
}

//Setteur pour l'attribut Damping
//param : newDamping : la nouvelle valeur du damping
void Particule::setDamping(float newDamping)
{
	this->Damping = newDamping;
}

//Getteur pour l'attribut Position
//return le vecteur de la position
Vecteur3D Particule::getPosition()
{
	return this->Position;
}

//Setteur pour l'attribut Position
//param : newPosition : la nouvelle valeur de la position
void Particule::setPosition(Vecteur3D newPosition)
{
	this->Position = newPosition;
}

//Getteur pour l'attribut Velocity
//return le vecteur de la velocite
Vecteur3D Particule::getVelocity()
{
	return this->Velocity;
}

//Setteur pour l'attribut Velocity
//param : newVelociy : la nouvelle valeur pour la velocite
void Particule::setVelocity(Vecteur3D newVelocity)
{
	this->Velocity = newVelocity;
}

//Getteur pour l'attribut Acceleration
//return le vecteur de l'acceleration
Vecteur3D Particule::getAcceleration()
{
	return this->Acceleration;
}

//Setteur pour l'attribut Acceleration
//param : newAcceleration : nouvelle valeur de l'acceleration
void Particule::setAcceleration(Vecteur3D newAcceleration)
{
	this->Acceleration = newAcceleration;
}

//Fonction pour l'integrateur pour les particules
//param : frameTime : le temps d'une frame
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