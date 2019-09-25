#pragma once
#include"Particule.h"
#include"ParticuleForceGenerator.h"
#include <vector>

class RegistreForces
{
	struct EnregistrementForce
	{
		Particule* particule;
		ParticuleForceGenerator* fg;

	};
		typedef std::vector<EnregistrementForce> Registre;

};

