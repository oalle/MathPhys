#include "GameWorld.h"

GameWorld::GameWorld() 
{
	
}

GameWorld::~GameWorld() 
{

}

void GameWorld::DeleteParticule(Particule p_Particule)
{
	std::vector<Particule>::iterator it = listParticules.begin;

	for (int i = 0; i <= listParticules.size; i++)
	{
		if (listParticules.at(i) == p_Particule)
			listParticules.erase(it);
		it++;
	}
}
