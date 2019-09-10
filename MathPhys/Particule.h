#pragma once
#include <cmath>
#include "Vecteur3D.h"

class Particule
{
public:
	Particule();
	virtual ~Particule();

	Particule(Particule& particule);
	void operator=(Particule& particule);

	void integrer(float frameTime);

	float getMasse();
	void setMasse(float newMasse);

	float getInverseMasse();
	void setInverseMasse(float newInverseMasse);

	float getDamping();
	void setDamping(float newDamping);

	Vecteur3D getPosition();
	void setPosition(Vecteur3D newPosition);

	Vecteur3D getVelocity();
	void setVelocity(Vecteur3D newVelocity);

	Vecteur3D getAcceleration();
	void setAcceleration(Vecteur3D newAcceleration);

protected:
	float Masse;
	float InverseMasse;
	float Damping;

	Vecteur3D Position;
	Vecteur3D Velocity;
	Vecteur3D Acceleration;

};

