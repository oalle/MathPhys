#include "GameWorld.h"
#include "ParticleCable.h"
#include "DragForce.h"


std::vector<Particle> GameWorld::listParticules;
RegistreForces GameWorld::registreForces;
ParticleContactResolver GameWorld::particleContactResolver;
RigidBody GameWorld::m_RigidBody;

GameWorld::GameWorld() {}

float frameTime = 0.0033f;

float MatSpec[4] = {0.1f, 0.1f, 0.5f, 1.0f};
float MatDif[4] = {0.057f, 0.447f, 0.361f, 1.0f};
float MatAmb[4] = {0.3f, 0.3f, 0.3f, 1.0f};
float Light1Pos[4] = {0.0f, 0.0f, 20.0f, 1.0f};
float Light1Dif[4] = {1.0f, 1.0f, 1.0f, 1.0f};
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
    m_RigidBody = RigidBody(1 / 10, 0.7, 0.7, Vector3D(2, 0, 8), Quaternion(90, 1, 1, 1));

    /*Particle l_Particle1G1(10, Vector3D(2, 0, 8));
    Particle l_Particle2G1(10, Vector3D(2, 3, 8));
    Particle l_Particle3G1(10, Vector3D(4, 0, 8));
    Particle l_Particle4G1(10, Vector3D(4, 3, 8));
    Particle l_Particle1G2(10, Vector3D(-2, 0, 8));
    Particle l_Particle2G2(10, Vector3D(-2, 3, 8));
    Particle l_Particle3G2(10, Vector3D(-4, 0, 8));
    Particle l_Particle4G2(10, Vector3D(-4, 3, 8));
    AddParticule(l_Particle1G1);
    AddParticule(l_Particle2G1);
    AddParticule(l_Particle3G1);
    AddParticule(l_Particle4G1);
    AddParticule(l_Particle1G2);
    AddParticule(l_Particle2G2);
    AddParticule(l_Particle3G2);
    AddParticule(l_Particle4G2);*/
	// application de la force ressort
    //ParticleSpring* l_ParticleSpringP12G1 = new ParticleSpring(listParticules[1], 1, 0.003);
    //AddForce(&listParticules[0], l_ParticleSpringP12G1);
    //ParticleSpring* l_ParticleSpringP21G1 = new ParticleSpring(listParticules[0], 1, 0.003);
    //AddForce(&listParticules[1], l_ParticleSpringP21G1);

    //ParticleSpring* l_ParticleSpringP31G1 = new ParticleSpring(listParticules[2], 1, 0.003);
    //AddForce(&listParticules[0], l_ParticleSpringP31G1);
    //ParticleSpring* l_ParticleSpringP13G1 = new ParticleSpring(listParticules[0], 1, 0.003);
    //AddForce(&listParticules[2], l_ParticleSpringP13G1);

    //ParticleSpring* l_ParticleSpringP34G1 = new ParticleSpring(listParticules[2], 1, 0.003);
    //AddForce(&listParticules[3], l_ParticleSpringP34G1);
    //ParticleSpring* l_ParticleSpringP43G1 = new ParticleSpring(listParticules[3], 1, 0.003);
    //AddForce(&listParticules[2], l_ParticleSpringP43G1);

    //ParticleSpring* l_ParticleSpringP24G1 = new ParticleSpring(listParticules[1], 1, 0.003);
    //AddForce(&listParticules[3], l_ParticleSpringP24G1);
    //ParticleSpring* l_ParticleSpringP42G1 = new ParticleSpring(listParticules[3], 1, 0.003);
    //AddForce(&listParticules[1], l_ParticleSpringP42G1);

    // application de la force drag
     //float l_DragCoeff1 = 0.1f;
     //float l_DragCoeff2 = 10.f;
     //DragForce* l_DragForce = new DragForce(l_DragCoeff1, l_DragCoeff2);
     //AddForce(&listParticules[0], l_DragForce);
     //AddForce(&listParticules[1], l_DragForce);
     //AddForce(&listParticules[2], l_DragForce);
     //AddForce(&listParticules[3], l_DragForce);
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
void GameWorld::def_carre(void)
{
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glEnd();
}

void GameWorld::def_cube(void)
{ 
    glPushMatrix(); 

    glPushMatrix();
        def_carre();
        glPopMatrix();

    glPushMatrix();
        glTranslatef(-1 * (getRigidBody().getPosition().getx() - 2),
                     -1 * (getRigidBody().getPosition().gety()),
                     -1 * (getRigidBody().getPosition().getz()));
        def_carre();
        glPopMatrix();

    glPushMatrix();
        glRotatef(-90, 0, 1, 0);
        glTranslatef(-1 * (getRigidBody().getPosition().getx() - 2),
                     -1 * (getRigidBody().getPosition().gety()),
                     -1 * (getRigidBody().getPosition().getz()));
        def_carre();
        glPopMatrix();

    glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glTranslatef(-1 * (getRigidBody().getPosition().getx() - 2),
                     -1 * (getRigidBody().getPosition().gety()),
                     -1 * (getRigidBody().getPosition().getz()));
        def_carre();
        glPopMatrix();

    glPushMatrix();
        glRotatef(-90, 1, 0, 0);
        glTranslatef(-1 * (getRigidBody().getPosition().getx() - 2),
                     -1 * (getRigidBody().getPosition().gety()),
                     -1 * (getRigidBody().getPosition().getz()));
        def_carre();
        glPopMatrix();

    glPushMatrix();
        glRotatef(90, 1, 0, 0);  /*glColor3f(1.0,1.0,1.0);*/

        glTranslatef(-1 * (getRigidBody().getPosition().getx() - 2),
                     -1 * (getRigidBody().getPosition().gety()),
                     -1 * (getRigidBody().getPosition().getz()));
        def_carre();
        glPopMatrix();
}

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
    registreForces.AddEnregistrementForce(&p);
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
    float oldTimeSinceStart = 0;

    // init vue glut
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
    /*glBegin(GL_QUADS);

    // creation d'un bloc sol
    /*glColor3f(0.0, 1.0, 0.0);

    glVertex3f(-2, -2, -2);
    glVertex3f(-2, 2, -2);
    glVertex3f(2, 2, -2);
    glVertex3f(2, -2, -2);*/
   /* glEnd();*/

    glColor3f(1.0, 0.0, 0.0);

    // update du registre des forces
    /*for (int i = 0; i < registreForces.GetListEnregistrementForce().size(); i++)
    {
        registreForces.GetListEnregistrementForce()[i].fg->updateForce(
            registreForces.GetListEnregistrementForce()[i].particule, frameTime);
    }
    // update du registre des contacts
    ParticleContactResolver::resolveContact(frameTime);*/

    // affichage des particules et appel � integrate (qui clear aussi les AccumForces)
    /*for (int i = 0; i < listParticules.size(); i++)
    {
        glPushMatrix();

        // draw call pour chaque particule
        glTranslatef(listParticules[i].getPosition().getx(), listParticules[i].getPosition().gety(),
                     listParticules[i].getPosition().getz());
        initSphereObjWrapper(0.01f * listParticules[i].getMasse());
        glTranslatef(-1 * (listParticules[i].getPosition().getx() - 2),
                     -1 * (listParticules[i].getPosition().gety()),
                     -1 * (listParticules[i].getPosition().getz()));
        // fonction pour appliquer une translation � un projectile
        listParticules[i].integrate(frameTime);

        glPopMatrix();
    }*/
	// affichage du rigidBody et appel � integrate (qui clear aussi les AccumForces)
	glPushMatrix();
	glTranslatef(getRigidBody().getPosition().getx(), getRigidBody().getPosition().gety(),
                    getRigidBody().getPosition().getz());
	initSphereObjWrapper(1);
        def_cube();
	/*glTranslatef(-1 * (getRigidBody().getPosition().getx() - 2),
                     -1 * (getRigidBody().getPosition().gety()),
                     -1 * (getRigidBody().getPosition().getz()));*/
        // fonction pour appliquer une translation � un projectile
        getRigidBody().integrate(frameTime);

        glPopMatrix();

    glFlush();
    /* Swap front and back buffers */
    glutPostRedisplay();
    glutSwapBuffers();

    // fin calcul frame time
    float timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
    float deltaTime = timeSinceStart - oldTimeSinceStart;
    frameTime = deltaTime / 1000;
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
    {
        // application de la force ressort
        ParticleSpring* l_ParticleSpringP12G1 = new ParticleSpring(listParticules[1], 1, 0.003);
        AddForce(&listParticules[0], l_ParticleSpringP12G1);
        ParticleSpring* l_ParticleSpringP21G1 = new ParticleSpring(listParticules[0], 1, 0.003);
        AddForce(&listParticules[1], l_ParticleSpringP21G1);

        ParticleSpring* l_ParticleSpringP31G1 = new ParticleSpring(listParticules[2], 1, 0.003);
        AddForce(&listParticules[0], l_ParticleSpringP31G1);
        ParticleSpring* l_ParticleSpringP13G1 = new ParticleSpring(listParticules[0], 1, 0.003);
        AddForce(&listParticules[2], l_ParticleSpringP13G1);

        ParticleSpring* l_ParticleSpringP34G1 = new ParticleSpring(listParticules[2], 1, 0.003);
        AddForce(&listParticules[3], l_ParticleSpringP34G1);
        ParticleSpring* l_ParticleSpringP43G1 = new ParticleSpring(listParticules[3], 1, 0.003);
        AddForce(&listParticules[2], l_ParticleSpringP43G1);

        ParticleSpring* l_ParticleSpringP24G1 = new ParticleSpring(listParticules[1], 1, 0.003);
        AddForce(&listParticules[3], l_ParticleSpringP24G1);
        ParticleSpring* l_ParticleSpringP42G1 = new ParticleSpring(listParticules[3], 1, 0.003);
        AddForce(&listParticules[1], l_ParticleSpringP42G1);

		// application de la force drag
        //float l_DragCoeff1 = 0.1f;
        //float l_DragCoeff2 = 10.f;
        //DragForce* l_DragForce = new DragForce(l_DragCoeff1, l_DragCoeff2);
        //AddForce(&listParticules[0], l_DragForce);
        //AddForce(&listParticules[1], l_DragForce);
        //AddForce(&listParticules[2], l_DragForce);
        //AddForce(&listParticules[3], l_DragForce);

        // ParticleCable l_ParticleCableP12G1(&listParticules[0], &listParticules[1], 1, 1);
        // l_ParticleCableP12G1.addContact();
        // ParticleContactResolver::resolveContact(frameTime);

        // GravityForce* l_GravityForce = new GravityForce();
        // AddForce(&listParticules[0], l_GravityForce);
        break;
    }
    case 'd':
    {
        // accelereation vers la gauche sur particule no1
        listParticules[0].setAcceleration(Vector3D(-0.01, 0, 0));
        break;
    }
    default:
    {
        break;
    }
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