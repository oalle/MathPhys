#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

using namespace std;

int x = 0;
int y = 0;
int z = 0;


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

void defboule(int x)
{
	
	glutSolidSphere(x, 50, 50);
	
}

void display(void)
{
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
	glTranslatef(x, y, z);

	defboule(1);
	glPopMatrix();


	
	glFlush();
	/* Swap front and back buffers */
	glutPostRedisplay();
	glutSwapBuffers();
}
void key_pressed(unsigned char key, int x, int y) {
	/*if (key == 'q') {
		defboule(1);
	}*/
}
void redim(int width, int height)
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
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 100);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Hello world");
	/* Callback for display */
	glutDisplayFunc(display);
	glutReshapeFunc(redim);
	glutKeyboardFunc(key_pressed);
	/* Main loop */
	glutMainLoop();
	return 0;
}

