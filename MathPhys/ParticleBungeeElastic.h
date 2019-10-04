#pragma once
#include "Vector3D.h"
#include "Particle.h"
class ParticleBungeeElastic
{
private:
	Vector3D ancragePoint;
	float k;
	float restLength;

public:
	ParticleBungeeElastic();
	ParticleBungeeElastic(Vector3D ancragePoint, float k, float restLength);
	~ParticleBungeeElastic();
	void updateForce(Particle* particule, float duration);

};


