#pragma once
#include"ParticleForceGenerator.h"
class GravityForce : public ParticleForceGenerator
{
private :
	Vector3D GravityVector;
public:
	GravityForce();
	~GravityForce();
	void updateForce(Particle * particule, float duration);
};

