#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "Particle.h"
#include "Vecteur3D.h"

using namespace std;

float sphereObjX = 0;
float sphereObjY = 0;
float sphereObjZ = 0;

Particle projectile;

float frameTime = 0.0033f;

float MatSpec[4] = { 0.1f, 0.1f, 0.5f, 1.0f };
float MatDif[4] = { 0.057f, 0.447f, 0.361f, 1.0f };
float MatAmb[4] = { 0.3f, 0.3f, 0.3f, 1.0f };
float Light1Pos[4] = { 0.0f, 0.0f, 20.0f, 1.0f };
float Light1Dif[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
float Light1Spec[4] = { 0.0f, 1.0f, 1.0f, 1.0f };
float Light1Amb[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
float Spot1Dir[3] = { 0.0f, 0.0f, -1.0f };
GLfloat position1[4] = { -5.0,0.0,3.0,0.0 };
GLfloat shine[1] = { 50.0 };
GLfloat Lnoire[4] = { 0.0,0.0,0.0,1.0 };

//fonction pour initialiser une sphere dans notre environnement
//param float x Le rayon de notre sphere
void initSphereObj(float x)
{
	glutSolidSphere(x, 50, 50);
}

//fonction pour appliquer une translation à un projectile
//param Vecteur3D vec1 La position d'un projectile
void translation(Vecteur3D vec1)
{
	projectile.integrate(frameTime);

	sphereObjX = sphereObjX + static_cast<float>(vec1.getx());
	sphereObjY = sphereObjY + static_cast<float>(vec1.gety());
	sphereObjZ = sphereObjZ + static_cast<float>(vec1.getz());

}

//fonction permettant le rafraichissement de la vue
void displayLoop(void)
{
	// debut calcul frame time
	//float previousTime = glutGet( GLUT_ELAPSED_TIME );


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

	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();

	Vecteur3D vec1 = projectile.getPosition();
	glTranslatef(sphereObjX - 2, sphereObjY, sphereObjZ);
	initSphereObj(0.1f);
	glPopMatrix();

	translation(vec1);



	glFlush();
	/* Swap front and back buffers */
	glutPostRedisplay();
	glutSwapBuffers();

	//for (int i = 0; i < 100; i++);

	// fin calcul frame time
	//float currentTime = glutGet(GLUT_ELAPSED_TIME);
	//frameTime = (currentTime - previousTime) / 1000.0f;

}

//fonction de detection des inputs
//param char key La touche appuyee
//param int x Coordonnee X du curseur de la souris
//param int Y Coordonnee Y du curseur de la souris
void key_pressed(unsigned char key, int x, int y) {

	Particle tmpBalle(100);
	Particle tmpBDF(50);
	Particle tmpLaser(0);
	Particle tmpBoulet(150);

	switch (key)
	{
	case 'a':
		sphereObjX = 0;
		sphereObjY = 0;
		sphereObjZ = 0;
		projectile = tmpBalle;
		break;
	case 'z':
		sphereObjX = 0;
		sphereObjY = 0;
		sphereObjZ = 0;
		projectile = tmpBDF;
		break;
	case 'e':
		sphereObjX = 0;
		sphereObjY = 0;
		sphereObjZ = 0;
		projectile = tmpLaser;
		break;
	case 'r':
		sphereObjX = 0;
		sphereObjY = 0;
		sphereObjZ = 0;
		projectile = tmpBoulet;
		break;
	default:
		break;
	}
}

//fonction pour positionner la vue / la camera
//param int width La largeur de la fenetre
//param int height La hauteur de la fenetre
void reshapeLoop(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, -4,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0, 1.0, 1.0, 12.0);
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(0, 00);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Hello world");
	/* Callback for display */
	glutDisplayFunc(displayLoop);
	glutReshapeFunc(reshapeLoop);
	glutKeyboardFunc(key_pressed);
	/* Main loop */
	glutMainLoop();
	return 0;
}