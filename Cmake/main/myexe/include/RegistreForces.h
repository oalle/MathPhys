#pragma once
#include "Particle.h"
#include "ParticleForceGenerator.h"
#include <vector>

class RegistreForces
{
public:
	struct EnregistrementForce
	{
		Particle* particule;
		ParticleForceGenerator* fg;

	};
		typedef std::vector<EnregistrementForce> Registre;

private:
	Registre registreForces;

public:
	Registre GetListEnregistrementForce() { return registreForces; }
	void AddEnregistrementForce(EnregistrementForce *p_EnregistrementForce) { registreForces.push_back(*p_EnregistrementForce); }
	void DeleteEnregistrementForce(int p_Index);
};

