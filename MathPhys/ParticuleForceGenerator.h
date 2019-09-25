#pragma once
#include "Particule.h"
class ParticuleForceGenerator
{

public :
	virtual void updateForce(Particule particule, float duration)=0;
};

