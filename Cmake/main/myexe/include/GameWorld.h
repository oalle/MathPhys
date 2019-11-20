#pragma once
#include "Particle.h"
#include "../../../external/freeglut/include/GL/freeglut_std.h"
#include <iostream>
#include <vector>
#include "RegistreForces.h"
#include "ParticleSpring.h"
#include "GravityForce.h"
#include "ParticleContactResolver.h"
#include "RigidBody.h"

class GameWorld
{
private :
    static std::vector<Particle> listParticules;
    static RegistreForces registreForces;
    static ParticleContactResolver particleContactResolver;
	static RigidBody m_RigidBody;

public :
	GameWorld(std::vector<Particle> p_listParticules) { listParticules = p_listParticules; }
	GameWorld();
	~GameWorld();
	void GameSetup();
	void GlutSetup(int argc, char* argv[]);
	void Setup(int argc, char* argv[]);
    static RigidBody getRigidBody() { return m_RigidBody; };
	static void setRigidBody(RigidBody p_RigidBody) { m_RigidBody = p_RigidBody; };
    static void def_carre(void);
	static void def_cube(void);
        
	
	static std::vector<Particle> GetListParticules() { return listParticules; }
	static void AddParticule(Particle p_Particule) { listParticules.push_back(p_Particule); }
	static void AddForce(Particle* p_Particule, ParticleForceGenerator* fg);
	static void DeleteParticule(Particle p_Particule);

	static void initSphereObjWrapper(float x);
	static void translationWrapper(Vector3D vec1);
	static void displayLoopWrapper(void);
	static void key_pressedWrapper(unsigned char key, int x, int y);
	static void reshapeLoopWrapper(int width, int height);
};

