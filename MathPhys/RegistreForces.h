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

private:
	Registre registreForces;

public:
	Registre GetListEnregistrementForce() { return registreForces; }
	void AddEnregistrementForce(EnregistrementForce p_EnregistrementForce) { registreForces.push_back(p_EnregistrementForce); }
	void DeleteEnregistrementForce(EnregistrementForce p_EnregistrementForce);
};

