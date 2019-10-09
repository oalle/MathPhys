#pragma once
#include"ParticleForceGenerator.h"
class GravityForce : public ParticleForceGenerator
{
private :
	Vector3D GravityVector;
public:
	GravityForce();
	~GravityForce();
	virtual void updateForce(Particle* particule, float p_Duration) override;
};

