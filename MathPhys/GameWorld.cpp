#include "GameWorld.h"

GameWorld::GameWorld() 
{
	
}

GameWorld::~GameWorld() 
{

}

void GameWorld::DeleteParticule(Particule p_Particule)
{
	listParticules.erase(std::find(listParticules.begin, listParticules.end, p_Particule));
}
