#pragma once
#include"ParticuleForceGenerator.h";

class DragForce : public ParticleForceGenerator
{
private :
	float coeffDrag1;
	float coeffDrag2;

public:
	DragForce();
	DragForce(float coeffDrag1, float coeffDrag2);
	~DragForce();
	void updateForce(Particle* particule, float duration);

};

