#pragma once
#include"ParticuleForceGenerator.h"
class GravityForce : public ParticuleForceGenerator
{
private :
	Vecteur3D GravityVector;
public:
	GravityForce();
	~GravityForce();
	void updateForce(Particule * particule, float duration);
};

