#include "GameWorld.h"

GameWorld::GameWorld() 
{
	
}

GameWorld::~GameWorld() 
{

}

void GameWorld::DeleteParticule(Particle p_Particule)
{
	listParticules.erase(std::find(listParticules.begin(), listParticules.end(), p_Particule));
}
