#pragma once
#include <cmath>
#include "Veccteur3D.h"

class Particule
{
public:
	Particule();
	virtual ~Particule();

	Particule(const Particule &particule);
	void operator=(const Particule &particule);

	void integrer(float frameTime);

	float getMasse();
	void setMasse(float newMasse);

	float getInverseMasse();
	void setInverseMasse(float newInverseMasse);

	float getDamping();
	void setDamping(float newDamping);

	Veccteur3D getPosition();
	void setPosition(Veccteur3D newPosition);

	Veccteur3D getVelocity();
	void setVelocity(Veccteur3D newVelocity);

	Veccteur3D getAcceleration();
	void setAcceleration(Veccteur3D newAcceleration);
	
protected:
	float Masse;
	float InverseMasse;
	float Damping;

	Veccteur3D Position;
	Veccteur3D Velocity;
	Veccteur3D Acceleration;

};

