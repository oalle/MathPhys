/*#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>*/
#include <iostream>
#include "Particle.h"
#include "GameWorld.h"
#include "Vector3D.h"

using namespace std;


int main(int argc, char* argv[]) 
{
	GameWorld gw;
	gw.Setup(argc, argv);
	return 0;
}