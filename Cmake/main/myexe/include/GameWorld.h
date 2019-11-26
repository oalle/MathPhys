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

class GameWorld
{
private:
    static std::vector<Particle> listParticules;
    static RegistreForces registreForces;
    static ParticleContactResolver particleContactResolver;
    static Cube m_Cube;

public:
    GameWorld(std::vector<Particle> p_listParticules) { listParticules = p_listParticules; }
    GameWorld();
    ~GameWorld();
    void GameSetup();
    void GlutSetup(int argc, char* argv[]);
    void Setup(int argc, char* argv[]);
    static Cube getCube() { return m_Cube; };
    static void setCube(Cube p_Cube) { m_Cube = p_Cube; };
    static void drawCube(void);

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
