#include "GameWorld.h"

std::vector<Particle> GameWorld::listParticules;

GameWorld::GameWorld() {}

double frameTime = 0.0033f;

float MatSpec[4] = {0.1f, 0.1f, 0.5f, 1.0f};
float MatDif[4] = {0.057f, 0.447f, 0.361f, 1.0f};
float MatAmb[4] = {0.3f, 0.3f, 0.3f, 1.0f};
float Light1Pos[4] = {0.0f, 0.0f, 20.0f, 1.0f};
float Light1Dif[4] = {0.0f, 0.0f, 0.0f, 1.0f};
float Light1Spec[4] = {0.0f, 1.0f, 1.0f, 1.0f};
float Light1Amb[4] = {0.5f, 0.5f, 0.5f, 1.0f};
float Spot1Dir[3] = {0.0f, 0.0f, -1.0f};
GLfloat position1[4] = {-5.0, 0.0, 3.0, 0.0};
GLfloat shine[1] = {50.0};
GLfloat Lnoire[4] = {0.0, 0.0, 0.0, 1.0};

void GameWorld::GameSetup()
{
    registreForces = RegistreForces();
    listParticules = std::vector<Particle>();

    Particle l_Particle1G1(10, Vector3D(0,0,1));
    Particle l_Particle2G1(10, Vector3D(0, 0, 2));
    Particle l_Particle3G1(10, Vector3D(0, 0, 3));
    Particle l_Particle4G1(10, Vector3D(0, 0, 4));
    Particle l_Particle1G2(10, Vector3D(0, 0, 5));
    Particle l_Particle2G2(10, Vector3D(0, 0, 6));
    Particle l_Particle3G2(10, Vector3D(0, 0, 7));
    Particle l_Particle4G2(10, Vector3D(0, 0, 8));
    AddParticule(l_Particle1G1);
    AddParticule(l_Particle2G1);
    AddParticule(l_Particle3G1);
    AddParticule(l_Particle4G1);
    AddParticule(l_Particle1G2);
    AddParticule(l_Particle2G2);
    AddParticule(l_Particle3G2);
    AddParticule(l_Particle4G2);
}

void GameWorld::GlutSetup(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 00);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Blobs");
    /* Callback for display */
    glutDisplayFunc(displayLoopWrapper);
    glutReshapeFunc(reshapeLoopWrapper);
    glutKeyboardFunc(key_pressedWrapper);
}

/*void GameWorld::reshapeLoopWrapper(int width, int height) { reshapeLoopWrapper(width, height); }

void GameWorld::translationWrapper(Vector3D v1) { translationWrapper(v1); }

void GameWorld::initSphereObjWrapper(float x) { initSphereObjWrapper(x); }

void GameWorld::displayLoopWrapper() { displayLoopWrapper(); }

void GameWorld::key_pressedWrapper(unsigned char key, int x, int y)
{
    key_pressedWrapper(key, x, y);
}*/

void GameWorld::Setup(int argc, char* argv[])
{
    GlutSetup(argc, argv);
    GameSetup();

    /* Main loop */
    glutMainLoop();
}

GameWorld::~GameWorld() {}

void GameWorld::AddForce(Particle* p_Particule, ParticleForceGenerator* fg)
{
    RegistreForces::EnregistrementForce p;
    p.fg = fg;
    p.particule = p_Particule;
    registreForces.AddEnregistrementForce(p);
}

void GameWorld::DeleteParticule(Particle p_Particule)
{
    listParticules.erase(std::find(listParticules.begin(), listParticules.end(), p_Particule));
}

// fonction pour initialiser une sphere dans notre environnement
// param float x Le rayon de notre sphere
void GameWorld::initSphereObjWrapper(float x) { glutSolidSphere(x, 50, 50); }

// fonction permettant le rafraichissement de la vue
void GameWorld::displayLoopWrapper(void)
{
    // debut calcul frame time
    int oldTimeSinceStart = 0;

    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Lnoire);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpec);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDif);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shine);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, Light1Dif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, Light1Spec);
    glLightfv(GL_LIGHT0, GL_AMBIENT, Light1Amb);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glBegin(GL_QUADS);

    glVertex3f(-2, -2, -2);
    glVertex3f(-2, 2, -2);
    glVertex3f(2, 2, -2);
    glVertex3f(2, -2, -2);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();

	for (int i = 0; i < listParticules.size(); i++) {
		// draw call pour chaque particule
		glTranslatef(listParticules[i].getPosition().getx() - 2, listParticules[i].getPosition().gety(),
			listParticules[i].getPosition().getz());
		initSphereObjWrapper(0.1f * listParticules[i].getMasse());

		// fonction pour appliquer une translation � un projectile
		listParticules[i].integrate(frameTime);
	}

        /*for
            each(Particle particle in GetListParticules())
            {
                // draw call pour chaque particule
                glTranslatef(particle.getPosition().getx() - 2, particle.getPosition().gety(),
                             particle.getPosition().getz());
                initSphereObjWrapper(0.1f * particle.getMasse());

                // fonction pour appliquer une translation � un projectile
                particle.integrate(frameTime);
            }*/

        glPopMatrix();

        glFlush();
        /* Swap front and back buffers */
        glutPostRedisplay();
        glutSwapBuffers();
        int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
        int deltaTime = timeSinceStart - oldTimeSinceStart;
        oldTimeSinceStart = timeSinceStart;
        frameTime = deltaTime / 1000;
        // fin calcul frame time
        // float currentTime = glutGet(GLUT_ELAPSED_TIME);
        // frameTime = (currentTime - previousTime) / 1000.0f;
}

// fonction de detection des inputs
// param char key La touche appuyee
// param int x Coordonnee X du curseur de la souris
// param int Y Coordonnee Y du curseur de la souris
void GameWorld::key_pressedWrapper(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
        // accelereation vers la gauche sur particule no1
		listParticules[0].setAcceleration(Vector3D(0, 0, 3));
        break;
    case 'd':
        // accelereation vers la gauche sur particule no1
		listParticules[0].setAcceleration(Vector3D(0, 0, 0));
        break;
    default:
        break;
    }
}

// fonction pour positionner la vue / la camera
// param int width La largeur de la fenetre
// param int height La hauteur de la fenetre
void GameWorld::reshapeLoopWrapper(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, -4, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, 1.0, 1.0, 12.0);
}