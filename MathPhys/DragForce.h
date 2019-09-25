#pragma once
#include"ParticuleForceGenerator.h";

class DragForce : public ParticuleForceGenerator
{
private :
	float coeffDrag1;
	float coeffDrag2;

public:
	DragForce();
	DragForce(float coeffDrag1, float coeffDrag2);
	~DragForce();
	void updateForce(Particule* particule, float duration);

};

