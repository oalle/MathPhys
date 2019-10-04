#pragma once
#include "Vector3D.h"
#include "Particle.h"
class ParticleBungeeElastic
{
private:
	Vector3D ancragePoint;
	double k;
	double restLength;

public:
	ParticleBungeeElastic();
	ParticleBungeeElastic(Vector3D ancragePoint, double k, double restLength);
	~ParticleBungeeElastic();
	void updateForce(Particle* particule, float duration);

};


