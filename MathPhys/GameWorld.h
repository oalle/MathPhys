#pragma once
#include "Particle.h"
#include <vector>
#include "RegistreForces.h"
class GameWorld
{
private :
	std::vector<Particle> listParticules;
	RegistreForces registreForces;

public :
	GameWorld(std::vector<Particle> p_listParticules) { listParticules = p_listParticules; }
	GameWorld();
	~GameWorld();

	std::vector<Particle> GetListParticules() { return listParticules; }
	void AddParticule(Particle p_Particule) { listParticules.push_back(p_Particule); }
	void DeleteParticule(Particle p_Particule);
};

