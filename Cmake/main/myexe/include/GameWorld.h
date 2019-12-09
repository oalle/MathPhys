#pragma once
#include "../../../external/freeglut/include/GL/glut.h"
#include "Cube.h"
#include "GravityForce.h"
#include "Particle.h"
#include "ParticleContactResolver.h"
#include "ParticleSpring.h"
#include "RegistreForces.h"
#include <iostream>
#include <vector>
#include "RegistreForces.h"
#include "ParticleSpring.h"
#include "GravityForce.h"
#include "ParticleContactResolver.h"
#include "RigidBody.h"
#include "Cube.h"
#include "Primitive.h"
#include "CollisionData.h"
#include "Contact.h"
#include "Plane.h"
#include "BVH.h"

class GameWorld
{
private:
    static std::vector<Particle> listParticules;
    static RegistreForces registreForces;
    static ParticleContactResolver particleContactResolver;
	static Cube m_Cube;
    static Plane m_mur1;
	static Plane m_mur2;
	static Plane m_mur3;
    static BVH m_tree;
    static CollisionData m_collisiondata;

public :
	GameWorld(std::vector<Particle> p_listParticules) { listParticules = p_listParticules; }
	GameWorld();
	~GameWorld();
	void GameSetup();
	void GlutSetup(int argc, char* argv[]);
	void Setup(int argc, char* argv[]);
	static void def_cube(void);
    static void def_room(void);
	
	static std::vector<Particle> GetListParticules() { return listParticules; }
	static void AddParticule(Particle p_Particule) { listParticules.push_back(p_Particule); }
	static void AddForce(Particle* p_Particule, ParticleForceGenerator* fg);
	static void DeleteParticule(Particle p_Particule);
	//a faire
	static void generateContacts(Primitive* prim1, Primitive* prim2, CollisionData * data);
	//a faire
	static int isInCollisions(BVH * tree1, BVH * tree2);
	//generate collision ne sera pas très éfficace sachant que les murs sont cencés être des plan leur volume englobant sour forme de sphere est infini également
    static void generateCollisions(BVH tree);
    static void initSphereObjWrapper(float x);
    static void translationWrapper(Vector3D vec1);
    static void displayLoopWrapper(void);
    static void key_pressedWrapper(unsigned char key, int x, int y);
    static void reshapeLoopWrapper(int width, int height);
};
