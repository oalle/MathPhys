#include "GameWorld.h"
#include "DragForce.h"
#include "ParticleCable.h"

std::vector<Particle> GameWorld::listParticules;
RegistreForces GameWorld::registreForces;
ParticleContactResolver GameWorld::particleContactResolver;
RigidBody GameWorld::m_RigidBody;
Vector3D gravity;

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
    m_RigidBody =
        RigidBody(0.5, 1, 1, Vector3D(0.08, -0.08, 0), Quaternion(0.01, 0.01, 0.01, 0.01));
    gravity = Vector3D(0, 0, 0);	
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
    glTranslatef(0.0, 0.0, -0.5);
    def_carre();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glTranslatef(0.0, 0.0, -0.5);
    def_carre();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0.0, 0.0, -0.5);
    def_carre();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0.0, 0.0, -0.5);
    def_carre();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glColor3f(1.0, 1.0, 1.0);

    glTranslatef(0.0, 0.0, -0.5);
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
    glClearColor(0.2, 0.5, 0.9, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    glColor3f(0.2, 0.5, 0.7);

    // update du registre des forces
    /*for (int i = 0; i < registreForces.GetListEnregistrementForce().size(); i++)
    {
        registreForces.GetListEnregistrementForce()[i].fg->updateForce(
            registreForces.GetListEnregistrementForce()[i].particule, frameTime);
    }
    // update du registre des contacts
    ParticleContactResolver::resolveContact(frameTime);*/

    // affichage du rigidBody et appel � integrate (qui clear aussi les AccumForces)
    glPushMatrix();

    glRotatef(getRigidBody().getInverseInertieTensor().getTab()[0], 1.0, 0.0, 0.0);
    glRotatef(getRigidBody().getInverseInertieTensor().getTab()[4], 0.0, 1.0, 0.0);
    glRotatef(getRigidBody().getInverseInertieTensor().getTab()[8], 0.0, 0.0, 1.0);
    glTranslatef(getRigidBody().getPosition().getx(), getRigidBody().getPosition().gety(),
                 getRigidBody().getPosition().getz());
    def_cube();
    // fonction pour appliquer une translation � un projectile
	m_RigidBody.AddForceAtBodyPoint(gravity, Vector3D(0, 0, 0));
    m_RigidBody.integrate(frameTime);

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
    case 'd':
    {
        // accelereation vers la gauche sur particule no1
        m_RigidBody.AddForceAtBodyPoint(Vector3D(-0.015, 0.028, 0.1), Vector3D(5.0, 1.0, 1.0));
        gravity = Vector3D(0, -0.00007, 0);
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