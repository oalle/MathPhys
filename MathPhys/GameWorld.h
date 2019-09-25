#pragma once
#include "Particule.h"
#include <vector>
class GameWorld
{
private :
	std::vector<Particule> listParticules;

public :
	GameWorld(std::vector<Particule> p_listParticules) { listParticules = p_listParticules; }
	GameWorld();
	~GameWorld();

	std::vector<Particule> GetListParticules() { return listParticules; }
	void AddParticule(Particule p_Particule) { listParticules.push_back(p_Particule); }
	void DeleteParticule(Particule p_Particule);
};

