#pragma once
#include"ParticuleForceGenerator.h"
class GravityForce : public ParticleForceGenerator
{
private :
	Vecteur3D GravityVector;
public:
	GravityForce();
	~GravityForce();
	void updateForce(Particle * particule, float duration);
};

