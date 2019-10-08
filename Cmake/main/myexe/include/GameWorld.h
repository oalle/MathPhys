#pragma once
#include "Particle.h"
/*#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>*/
#include <iostream>
#include <vector>
#include "RegistreForces.h"
#include "../../../external/freeglut/include/GL/freeglut_std.h"
class GameWorld
{
private :
	std::vector<Particle> listParticules;
	RegistreForces registreForces;

protected :

	static GameWorld* instance;

public :
	GameWorld(std::vector<Particle> p_listParticules) { listParticules = p_listParticules; }
	GameWorld();
	~GameWorld();
	void Setup(int argc, char* argv[]);
	std::vector<Particle> GetListParticules() { return listParticules; }
	void AddParticule(Particle p_Particule) { listParticules.push_back(p_Particule); }
	void AddForce(Particle* p_Particule, ParticleForceGenerator *fg);
	void DeleteParticule(Particle p_Particule);
	static void initSphereObjWrapper(float x);
	static void translationWrapper(Vector3D vec1);
	static void displayLoopWrapper(void);
	static void key_pressedWrapper(unsigned char key, int x, int y);
	static void reshapeLoopWrapper(int width, int height);

	virtual void initSphereObj(float x);
	virtual void translation(Vector3D vec1);
	virtual void displayLoop(void);
	virtual void key_pressed(unsigned char key, int x, int y);
	virtual void reshapeLoop(int width, int height);
};

