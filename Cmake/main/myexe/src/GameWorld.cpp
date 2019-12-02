#include "GameWorld.h"
#include "DragForce.h"
#include "ParticleCable.h"


std::vector<Particle> GameWorld::listParticules;
RegistreForces GameWorld::registreForces;
ParticleContactResolver GameWorld::particleContactResolver;
Cube GameWorld::m_Cube;
Vector3D gravity;
int angleDemo = 45;

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
    m_Cube = Cube(0.5, 0.995, 0.98, Vector3D(1.0, -0.5, 0.5), Quaternion(1.0, 0.0, 0.0, 0.0));
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

void GameWorld::def_cube(void)
{
    //face gauche
	glPushMatrix();
	//coordonnée du centre du rigidBody(particule)
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);    
	//coordonnée sommet1 par rapport au rigidBody
	glVertex3f( m_Cube.getSommet1().getx(), m_Cube.getSommet1().gety(), m_Cube.getSommet1().getz());
	//sommet5
    glVertex3f(m_Cube.getSommet5().getx(), m_Cube.getSommet5().gety(), m_Cube.getSommet5().getz());
	//sommet6
    glVertex3f(m_Cube.getSommet6().getx(), m_Cube.getSommet6().gety(), m_Cube.getSommet6().getz());
	//sommet2
    glVertex3f(m_Cube.getSommet2().getx(), m_Cube.getSommet2().gety(), m_Cube.getSommet2().getz());
    glEnd();
	glPopMatrix();
	//face en face
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);     
	//sommet 2
	glVertex3f( m_Cube.getSommet2().getx(), m_Cube.getSommet2().gety(), m_Cube.getSommet2().getz());
	//sommet 6
    glVertex3f(m_Cube.getSommet6().getx(), m_Cube.getSommet6().gety(), m_Cube.getSommet6().getz());
	//sommet 7
    glVertex3f(m_Cube.getSommet7().getx(), m_Cube.getSommet7().gety(), m_Cube.getSommet7().getz());
	//sommet 3
    glVertex3f( m_Cube.getSommet3().getx(), m_Cube.getSommet3().gety(), m_Cube.getSommet3().getz());
    glEnd();
	glPopMatrix();

	//face gauche
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);     
	//sommet 3
	glVertex3f( m_Cube.getSommet3().getx(), m_Cube.getSommet3().gety(), m_Cube.getSommet3().getz());
	//sommet 7
    glVertex3f( m_Cube.getSommet7().getx(), m_Cube.getSommet7().gety(), m_Cube.getSommet7().getz());
	//sommet 8
    glVertex3f( m_Cube.getSommet8().getx(), m_Cube.getSommet8().gety(), m_Cube.getSommet8().getz());
	//sommet 4
    glVertex3f( m_Cube.getSommet4().getx(), m_Cube.getSommet4().gety(), m_Cube.getSommet4().getz());
    glEnd();
	glPopMatrix();

	//face arrière
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);     
	//sommet 4
	glVertex3f( m_Cube.getSommet4().getx(), m_Cube.getSommet4().gety(), m_Cube.getSommet4().getz());
	//sommet 8
    glVertex3f( m_Cube.getSommet8().getx(), m_Cube.getSommet8().gety(), m_Cube.getSommet8().getz());
	//sommet 5
    glVertex3f( m_Cube.getSommet5().getx(), m_Cube.getSommet5().gety(), m_Cube.getSommet5().getz());
	//sommet 1
    glVertex3f( m_Cube.getSommet1().getx(), m_Cube.getSommet1().gety(), m_Cube.getSommet1().getz());
    glEnd();
	glPopMatrix();

	//face haute
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);     
	//sommet 6
	glVertex3f( m_Cube.getSommet6().getx(), m_Cube.getSommet6().gety(), m_Cube.getSommet6().getz());
	//sommet 5
    glVertex3f( m_Cube.getSommet5().getx(), m_Cube.getSommet5().gety(), m_Cube.getSommet5().getz());
	//sommet 8
    glVertex3f( m_Cube.getSommet8().getx(), m_Cube.getSommet8().gety(), m_Cube.getSommet8().getz());
	//sommet 7
    glVertex3f( m_Cube.getSommet7().getx(), m_Cube.getSommet7().gety(), m_Cube.getSommet7().getz());
    glEnd();
	glPopMatrix();

	//face basse
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);    
	//sommet 1
	glVertex3f( m_Cube.getSommet1().getx(), m_Cube.getSommet1().gety(), m_Cube.getSommet1().getz());
	//sommet 2
    glVertex3f( m_Cube.getSommet2().getx(), m_Cube.getSommet2().gety(), m_Cube.getSommet2().getz());
	//sommet 3
    glVertex3f( m_Cube.getSommet3().getx(), m_Cube.getSommet3().gety(), m_Cube.getSommet3().getz());
	//sommet 4
    glVertex3f( m_Cube.getSommet4().getx(), m_Cube.getSommet4().gety(), m_Cube.getSommet4().getz());
    glEnd();
	glPopMatrix();
    

	//sommet 1 bas
    glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
    glTranslatef(m_Cube.getSommet1().getx(), m_Cube.getSommet1().gety(), m_Cube.getSommet1().getz());
	glColor3f(0.0f, 1.0f, 0.0f);
	initSphereObjWrapper(0.1);
	
	
	glPopMatrix();


	//sommet 2 bas
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glTranslatef(m_Cube.getSommet2().getx(), m_Cube.getSommet2().gety(), m_Cube.getSommet2().getz());
	glColor3f(1.0f, 0.0f, 0.0f);
	initSphereObjWrapper(0.1);
	
	glPopMatrix();

	//sommet 3 bas
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glTranslatef(m_Cube.getSommet3().getx(), m_Cube.getSommet3().gety(), m_Cube.getSommet3().getz());
	glColor3f(0.0f, 1.0f, 0.0f);
	initSphereObjWrapper(0.1);
	
	glPopMatrix();

	//sommet 4 bas
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glTranslatef(m_Cube.getSommet4().getx(), m_Cube.getSommet4().gety(), m_Cube.getSommet4().getz());
	initSphereObjWrapper(0.1);
	glColor3f(0.0f, 1.0f, 0.0f);
	glPopMatrix();

	//sommet 5 haut
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glTranslatef(m_Cube.getSommet5().getx(), m_Cube.getSommet5().gety(), m_Cube.getSommet5().getz());
	initSphereObjWrapper(0.1);
	glColor3f(0.0f, 1.0f, 0.0f);
	glPopMatrix();

	//sommet 6 haut
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glTranslatef(m_Cube.getSommet6().getx(), m_Cube.getSommet6().gety(), m_Cube.getSommet6().getz());
	initSphereObjWrapper(0.1);
	glColor3f(0.0f, 1.0f, 0.0f);
	glPopMatrix();

	//sommet 7 haut
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glTranslatef(m_Cube.getSommet7().getx(), m_Cube.getSommet7().gety(), m_Cube.getSommet7().getz());
	initSphereObjWrapper(0.1);
	glColor3f(0.0f, 1.0f, 0.0f);
	glPopMatrix();

	//sommet 8 haut
	glPushMatrix();
	glTranslatef(m_Cube.getPosition().getx(), m_Cube.getPosition().gety(), m_Cube.getPosition().getz());
	glTranslatef(m_Cube.getSommet8().getx(), m_Cube.getSommet8().gety(), m_Cube.getSommet8().getz());
	initSphereObjWrapper(0.1);
    glColor3f(0.0f, 1.0f, 0.0f);
	glPopMatrix();	
	glPushMatrix();
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
    //glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2, 0.5, 0.9, 0);
    glMatrixMode(GL_MODELVIEW);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // update du registre des forces
    /*for (int i = 0; i < registreForces.GetListEnregistrementForce().size(); i++)
    {
        registreForces.GetListEnregistrementForce()[i].fg->updateForce(
            registreForces.GetListEnregistrementForce()[i].particule, frameTime);
    }
    // update du registre des contacts
    ParticleContactResolver::resolveContact(frameTime);*/

	
	
    def_cube();

    // On ajoute la force de gravité
	m_Cube.AddForceAtBodyPoint(gravity, Vector3D(0, 0, 0));
	//on integrate
    m_Cube.IntegrateCube(frameTime);

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
		//force sur arete en x et y
        //m_Cube.AddForceAtBodyPoint(Vector3D(-0.015, 0.020, 0.0), Vector3D(0.5, 0.5, 0.0));
		//force sur le point d'origine donc sans rotation
		//m_Cube.AddForceAtBodyPoint(Vector3D(-0.015, 0.028, 0.0), Vector3D(0.0, 0.0, 0.0));
		//force sur une arete en y et z
		//m_Cube.AddForceAtBodyPoint(Vector3D(0.0, 0.020, 0.03), Vector3D(0.0, 0.5, -0.5));
		//force sur sommet rouge en x et y et z
        //m_Cube.AddForceAtBodyPoint(Vector3D(-0.015, 0.015555, 0.015), Vector3D(0.5, -0.5, -0.5));
		//force sur sommet arete au dessus et a droite du sommet rouge en x et z
        m_Cube.AddForceAtBodyPoint(Vector3D(-0.015, 0.000, 0.015), Vector3D(-0.5, 0.0, -0.5));
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