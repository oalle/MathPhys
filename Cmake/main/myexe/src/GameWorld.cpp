#include "GameWorld.h"
#include "DragForce.h"
#include "ParticleCable.h"

std::vector<Particle> GameWorld::listParticules;
RegistreForces GameWorld::registreForces;
ParticleContactResolver GameWorld::particleContactResolver;
Cube GameWorld::m_Cube;
Plane GameWorld::m_mur1;
Plane GameWorld::m_mur2;
Plane GameWorld::m_mur3;
BVH GameWorld::m_tree;
CollisionData GameWorld::m_collisiondata;
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
    m_collisiondata = CollisionData();
    listParticules = std::vector<Particle>();
    m_Cube = Cube(0.5f, 0.995f, 0.98f, Vector3D(1.0, -0.5, 0.5), Quaternion(1.0, 0.0, 0.0, 0.0),
                  Vector3D(1.0, -0.5, 0.5), Vector3D(0.5, 0.5, 0.5));
    // l'offset des murs est déterminé par la distance par rapprot au centre du cube(facilite les
    // calculs avec les sommets dans le repère de l'objet)
    m_mur1 = Plane(Vector3D(-1.5, -1.5, 3.0), Vector3D(0.0, 0.0, -1.0), 3.35);
    m_mur2 = Plane(Vector3D(-1.5, -1.5, 3.0), Vector3D(1.0, 0.0, 0.0), 3.35);
    m_mur3 = Plane(Vector3D(-1.5, -1.5, 3.0), Vector3D(0.0, 1.0, 0.0), 3.35);
    m_tree = BVH();
   
    /*m_tree = BVH(&m_Cube);
    m_tree.Insertion(&m_mur1, &m_tree);
    m_tree.Insertion(&m_mur2, &m_tree);
    m_tree.Insertion(&m_mur3, &m_tree);*/
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

int GameWorld::isInCollisions(BVH* tree1, BVH* tree2)
{
    Vector3D vectorBetween =
        (tree1->getobject()->getCenterVolumeEng() - tree2->getobject()->getCenterVolumeEng());
   
    if (vectorBetween.norme() <= (double) tree1->getobject()->getRayonVolemeEng() +
                                     (double) tree2->getobject()->getRayonVolemeEng())
    { return 1; }
    else
    {
        return 0;
    }
}
void GameWorld::generateCollisions(BVH tree)
{

    // si la distance entre les points est inférieure à la somme des rayons englobant alors on test
    // si il y a contact
    if (isInCollisions(tree.getLeftSon(), tree.getRightSon()))
    {
        // les deux fils sont des feuilles
        if (tree.getLeftSon()->isLeaf() && tree.getRightSon()->isLeaf())
        {
            generateContacts(tree.getLeftSon()->getobject(), tree.getRightSon()->getobject(),
                             &m_collisiondata);
        }
        // le fils gauche n'est pas une feuille
        else if (!tree.getLeftSon()->isLeaf() && tree.getRightSon()->isLeaf())
        {
            if (isInCollisions(tree.getLeftSon()->getLeftSon(), tree.getRightSon()))
            {
                generateContacts(tree.getLeftSon()->getLeftSon()->getobject(),
                                 tree.getRightSon()->getobject(), &m_collisiondata);
            }

            if (isInCollisions(tree.getLeftSon()->getRightSon(), tree.getRightSon()))
            {
                generateContacts(tree.getLeftSon()->getRightSon()->getobject(),
                                 tree.getRightSon()->getobject(), &m_collisiondata);
            }
        }
        // le fils droit n'est pas une feuille
        else if (!tree.getRightSon()->isLeaf() && tree.getLeftSon()->isLeaf())
        {
            if (isInCollisions(tree.getRightSon()->getLeftSon(), tree.getLeftSon()))
            {
                generateContacts(tree.getRightSon()->getLeftSon()->getobject(),
                                 tree.getLeftSon()->getobject(), &m_collisiondata);
            }

            if (isInCollisions(tree.getRightSon()->getRightSon(), tree.getLeftSon()))
            {
                generateContacts(tree.getRightSon()->getRightSon()->getobject(),
                                 tree.getLeftSon()->getobject(), &m_collisiondata);
            }
        }
        // les deux fils ne sont pas des feuilles
		//à modifier afin que puisse rentré en collision avec plus d'un mur
        else
        {
			//on se concentre sur le fils gauche
			//on teste entre les deux fils du fils de gauche entre eux
			generateCollisions(*tree.getLeftSon());
			//on teste entre les deux fils du fils de droite entre eux
            generateCollisions(*tree.getRightSon());
			//on teste entre eux
			//fils gauche du parent gauche avec fils gauche du parent droit
			if (isInCollisions(tree.getLeftSon()->getLeftSon(), tree.getRightSon()->getLeftSon()))
            {
                generateContacts(tree.getLeftSon()->getLeftSon()->getobject(),
                                 tree.getRightSon()->getLeftSon()->getobject(), &m_collisiondata);
            }
			//fils gauche du parent gauche avec fils droit du parent droit
			if (isInCollisions(tree.getLeftSon()->getLeftSon(), tree.getRightSon()->getRightSon()))
            {
                generateContacts(tree.getLeftSon()->getLeftSon()->getobject(),
                                 tree.getRightSon()->getRightSon()->getobject(), &m_collisiondata);
            }
			//fils droit du parent gauche avec fils gauche du parent droit
			if (isInCollisions(tree.getLeftSon()->getRightSon(), tree.getRightSon()->getLeftSon()))
            {
                generateContacts(tree.getLeftSon()->getRightSon()->getobject(),
                                 tree.getRightSon()->getLeftSon()->getobject(), &m_collisiondata);
            }
			//fils droit du parent gauche avec fils droit du parent droit
			if (isInCollisions(tree.getLeftSon()->getRightSon(), tree.getRightSon()->getRightSon()))
            {
                generateContacts(tree.getLeftSon()->getRightSon()->getobject(),
                                 tree.getRightSon()->getRightSon()->getobject(), &m_collisiondata);
            }
        }
    }
    else
    {
        if (!tree.getLeftSon()->isLeaf() && !tree.getRightSon()->isLeaf())
        {
            generateCollisions(*tree.getLeftSon());
            generateCollisions(*tree.getRightSon());
        }
    }
}

// on ne fera que les collision de type vertex face
void GameWorld::generateContacts(Primitive* prim1, Primitive* prim2, CollisionData* data)
{
    float isSommet1Contact = 0;
    float isSommet2Contact = 0;
    float isSommet3Contact = 0;
    float isSommet4Contact = 0;
    float isSommet5Contact = 0;
    float isSommet6Contact = 0;
    float isSommet7Contact = 0;
    float isSommet8Contact = 0;

    // Si les deux primitives sont les murs alors on ne fait rien
    if (prim1->getRigidBody() == NULL && prim2->getRigidBody() == NULL) {}
    // si prim1 est le cube et prim2 un mur
    else if (prim1->getRigidBody() != NULL && prim2->getRigidBody() == NULL)
    {
		float distancemurorigine =
                    prim2->getPosition().prodScalaire(prim2->getnormal());
        // calcul de la distance des sommets par rapport au mur
        float distanceSommet1 = m_Cube.getSommet1().prodScalaire(prim2->getnormal());
        float distanceSommet2 = m_Cube.getSommet2().prodScalaire(prim2->getnormal());
        float distanceSommet3 = m_Cube.getSommet3().prodScalaire(prim2->getnormal());
        float distanceSommet4 = m_Cube.getSommet4().prodScalaire(prim2->getnormal());
        float distanceSommet5 = m_Cube.getSommet5().prodScalaire(prim2->getnormal());
        float distanceSommet6 = m_Cube.getSommet6().prodScalaire(prim2->getnormal());
        float distanceSommet7 = m_Cube.getSommet7().prodScalaire(prim2->getnormal());
        float distanceSommet8 = m_Cube.getSommet8().prodScalaire(prim2->getnormal());
		Vector3D positionSommet1 = prim1->getRigidBody()->getPosition() + m_Cube.getSommet1();
				Vector3D positionSommet2 = prim1->getRigidBody()->getPosition() + m_Cube.getSommet2();
				Vector3D positionSommet3 = prim1->getRigidBody()->getPosition() + m_Cube.getSommet3();
				Vector3D positionSommet4 = prim1->getRigidBody()->getPosition() + m_Cube.getSommet4();
				Vector3D positionSommet5 = prim1->getRigidBody()->getPosition() + m_Cube.getSommet5();
				Vector3D positionSommet6 = prim1->getRigidBody()->getPosition() + m_Cube.getSommet6();
				Vector3D positionSommet7 = prim1->getRigidBody()->getPosition() + m_Cube.getSommet7();
				Vector3D positionSommet8 = prim1->getRigidBody()->getPosition() + m_Cube.getSommet8();
               
                distanceSommet1 = positionSommet1.prodScalaire(prim2->getnormal());
				distanceSommet2 = positionSommet2.prodScalaire(prim2->getnormal());
				distanceSommet3 = positionSommet3.prodScalaire(prim2->getnormal());
				distanceSommet4 = positionSommet4.prodScalaire(prim2->getnormal());
				distanceSommet5 = positionSommet5.prodScalaire(prim2->getnormal());
				distanceSommet6 = positionSommet6.prodScalaire(prim2->getnormal());
				distanceSommet7 = positionSommet7.prodScalaire(prim2->getnormal());
				distanceSommet8 = positionSommet8.prodScalaire(prim2->getnormal());
		
        if (distanceSommet1 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet1() - prim2->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim2->getnormal(), distanceSommet1 - distancemurorigine);
            m_collisiondata.addContact(contact1);

        }
        else if (distanceSommet2 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet2() - prim2->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim2->getnormal(), distanceSommet2 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet3 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet3() - prim2->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim2->getnormal(), distanceSommet3 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet4 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet4() - prim2->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim2->getnormal(), distanceSommet4 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet5 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet5() - prim2->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim2->getnormal(), distanceSommet5 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet6 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet6() - prim2->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim2->getnormal(), distanceSommet6 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet7 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet7() - prim2->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim2->getnormal(), distanceSommet7 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet8 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet8() - prim2->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim2->getnormal(), distanceSommet8 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
    }
    // si prim2 est le cube et prim1 un mur
    else if (prim1->getRigidBody() == NULL && prim2->getRigidBody() != NULL)
    {
		 float distancemurorigine =
                    prim1->getPosition().prodScalaire(prim1->getnormal());
        // calcul de la distance des sommets par rapport au mur
        float distanceSommet1 = m_Cube.getSommet1().prodScalaire(prim1->getnormal());
        float distanceSommet2 = m_Cube.getSommet2().prodScalaire(prim1->getnormal());
        float distanceSommet3 = m_Cube.getSommet3().prodScalaire(prim1->getnormal());
        float distanceSommet4 = m_Cube.getSommet4().prodScalaire(prim1->getnormal());
        float distanceSommet5 = m_Cube.getSommet5().prodScalaire(prim1->getnormal());
        float distanceSommet6 = m_Cube.getSommet6().prodScalaire(prim1->getnormal());
        float distanceSommet7 = m_Cube.getSommet7().prodScalaire(prim1->getnormal());
        float distanceSommet8 = m_Cube.getSommet8().prodScalaire(prim1->getnormal());
		
		//vecteurposition du sommet dans le monde
                Vector3D positionSommet1 = prim2->getRigidBody()->getPosition() + m_Cube.getSommet1();
				Vector3D positionSommet2 = prim2->getRigidBody()->getPosition() + m_Cube.getSommet2();
				Vector3D positionSommet3 = prim2->getRigidBody()->getPosition() + m_Cube.getSommet3();
				Vector3D positionSommet4 = prim2->getRigidBody()->getPosition() + m_Cube.getSommet4();
				Vector3D positionSommet5 = prim2->getRigidBody()->getPosition() + m_Cube.getSommet5();
				Vector3D positionSommet6 = prim2->getRigidBody()->getPosition() + m_Cube.getSommet6();
				Vector3D positionSommet7 = prim2->getRigidBody()->getPosition() + m_Cube.getSommet7();
				Vector3D positionSommet8 = prim2->getRigidBody()->getPosition() + m_Cube.getSommet8();
               
                distanceSommet1 = positionSommet1.prodScalaire(prim1->getnormal());
				distanceSommet2 = positionSommet2.prodScalaire(prim1->getnormal());
				distanceSommet3 = positionSommet3.prodScalaire(prim1->getnormal());
				distanceSommet4 = positionSommet4.prodScalaire(prim1->getnormal());
				distanceSommet5 = positionSommet5.prodScalaire(prim1->getnormal());
				distanceSommet6 = positionSommet6.prodScalaire(prim1->getnormal());
				distanceSommet7 = positionSommet7.prodScalaire(prim1->getnormal());
				distanceSommet8 = positionSommet8.prodScalaire(prim1->getnormal());
        if (distanceSommet1 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet1() - prim1->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim1->getnormal(), distanceSommet1 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet2 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet2() - prim1->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim1->getnormal(), distanceSommet2 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet3 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet3() - prim1->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim1->getnormal(), distanceSommet3 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet4 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet4() - prim1->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim1->getnormal(), distanceSommet4 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet5 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet5() - prim1->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim1->getnormal(), distanceSommet5 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet6 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet6() - prim1->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim1->getnormal(), distanceSommet6 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet7 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet7() - prim1->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim1->getnormal(), distanceSommet7 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
        else if (distanceSommet8 <= distancemurorigine)
        {
            Vector3D contactPoint = m_Cube.getSommet8() - prim2->getCenterVolumeEng();
            contactPoint.mulScalaire(0.5);
            Contact contact1 =
                Contact(contactPoint, prim2->getnormal(), distanceSommet8 - distancemurorigine);
            m_collisiondata.addContact(contact1);
        }
    }
}

void GameWorld::def_room(void)
{
    // mur1
    glPushMatrix();
    glTranslatef(m_mur1.getPosition().getx(), m_mur1.getPosition().gety(),
                 m_mur1.getPosition().getz());
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    // coordonnée sommet1 par rapport au rigidBody
    glVertex3f(0.0, 0.0, 0.0);
    // sommet5
    glVertex3f(0.0, 3.0, 0.0);
    // sommet6
    glVertex3f(0.0, 3.0, -3.0);
    // sommet2
    glVertex3f(0.0, 0.0, -3.0);
    glEnd();
    glPopMatrix();

    // mur2
    glPushMatrix();
    glTranslatef(m_mur2.getPosition().getx(), m_mur2.getPosition().gety(),
                 m_mur2.getPosition().getz());
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    // coordonnée sommet1 par rapport au rigidBody
    glVertex3f(0.0, 0.0, 0.0);
    // sommet5
    glVertex3f(3.0, 0.0, 0.0);
    // sommet6
    glVertex3f(3.0, 3.0, 0.0);
    // sommet2
    glVertex3f(0.0, 3.0, 0.0);
    glEnd();
    glPopMatrix();

    // mur3
    glPushMatrix();
    glTranslatef(m_mur3.getPosition().getx(), m_mur3.getPosition().gety(),
                 m_mur3.getPosition().getz());
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    // coordonnée sommet1 par rapport au rigidBody
    glVertex3f(0.0, 0.0, 0.0);
    // sommet5
    glVertex3f(0.0, 0.0, -3.0);
    // sommet6
    glVertex3f(3.0, 0.0, -3.0);
    // sommet2
    glVertex3f(3.0, 0.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(m_mur2.getPosition().getx(), m_mur2.getPosition().gety(),
                 m_mur2.getPosition().getz());
    glColor3f(0.0f, 1.0f, 0.0f);
    initSphereObjWrapper(0.1);
    glPopMatrix();
}

void GameWorld::def_cube(void)
{
    // face gauche
    glPushMatrix();
    // coordonnée du centre du rigidBody(particule)
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    // coordonnée sommet1 par rapport au rigidBody
    glVertex3f(m_Cube.getSommet1().getx(), m_Cube.getSommet1().gety(), m_Cube.getSommet1().getz());
    // sommet5
    glVertex3f(m_Cube.getSommet5().getx(), m_Cube.getSommet5().gety(), m_Cube.getSommet5().getz());
    // sommet6
    glVertex3f(m_Cube.getSommet6().getx(), m_Cube.getSommet6().gety(), m_Cube.getSommet6().getz());
    // sommet2
    glVertex3f(m_Cube.getSommet2().getx(), m_Cube.getSommet2().gety(), m_Cube.getSommet2().getz());
    glEnd();
    glPopMatrix();
    // face en face
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    // sommet 2
    glVertex3f(m_Cube.getSommet2().getx(), m_Cube.getSommet2().gety(), m_Cube.getSommet2().getz());
    // sommet 6
    glVertex3f(m_Cube.getSommet6().getx(), m_Cube.getSommet6().gety(), m_Cube.getSommet6().getz());
    // sommet 7
    glVertex3f(m_Cube.getSommet7().getx(), m_Cube.getSommet7().gety(), m_Cube.getSommet7().getz());
    // sommet 3
    glVertex3f(m_Cube.getSommet3().getx(), m_Cube.getSommet3().gety(), m_Cube.getSommet3().getz());
    glEnd();
    glPopMatrix();

    // face gauche
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    // sommet 3
    glVertex3f(m_Cube.getSommet3().getx(), m_Cube.getSommet3().gety(), m_Cube.getSommet3().getz());
    // sommet 7
    glVertex3f(m_Cube.getSommet7().getx(), m_Cube.getSommet7().gety(), m_Cube.getSommet7().getz());
    // sommet 8
    glVertex3f(m_Cube.getSommet8().getx(), m_Cube.getSommet8().gety(), m_Cube.getSommet8().getz());
    // sommet 4
    glVertex3f(m_Cube.getSommet4().getx(), m_Cube.getSommet4().gety(), m_Cube.getSommet4().getz());
    glEnd();
    glPopMatrix();

    // face arrière
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    // sommet 4
    glVertex3f(m_Cube.getSommet4().getx(), m_Cube.getSommet4().gety(), m_Cube.getSommet4().getz());
    // sommet 8
    glVertex3f(m_Cube.getSommet8().getx(), m_Cube.getSommet8().gety(), m_Cube.getSommet8().getz());
    // sommet 5
    glVertex3f(m_Cube.getSommet5().getx(), m_Cube.getSommet5().gety(), m_Cube.getSommet5().getz());
    // sommet 1
    glVertex3f(m_Cube.getSommet1().getx(), m_Cube.getSommet1().gety(), m_Cube.getSommet1().getz());
    glEnd();
    glPopMatrix();

    // face haute
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    // sommet 6
    glVertex3f(m_Cube.getSommet6().getx(), m_Cube.getSommet6().gety(), m_Cube.getSommet6().getz());
    // sommet 5
    glVertex3f(m_Cube.getSommet5().getx(), m_Cube.getSommet5().gety(), m_Cube.getSommet5().getz());
    // sommet 8
    glVertex3f(m_Cube.getSommet8().getx(), m_Cube.getSommet8().gety(), m_Cube.getSommet8().getz());
    // sommet 7
    glVertex3f(m_Cube.getSommet7().getx(), m_Cube.getSommet7().gety(), m_Cube.getSommet7().getz());
    glEnd();
    glPopMatrix();

    // face basse
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    // sommet 1
    glVertex3f(m_Cube.getSommet1().getx(), m_Cube.getSommet1().gety(), m_Cube.getSommet1().getz());
    // sommet 2
    glVertex3f(m_Cube.getSommet2().getx(), m_Cube.getSommet2().gety(), m_Cube.getSommet2().getz());
    // sommet 3
    glVertex3f(m_Cube.getSommet3().getx(), m_Cube.getSommet3().gety(), m_Cube.getSommet3().getz());
    // sommet 4
    glVertex3f(m_Cube.getSommet4().getx(), m_Cube.getSommet4().gety(), m_Cube.getSommet4().getz());
    glEnd();
    glPopMatrix();

    // sommet 1 bas
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glTranslatef(m_Cube.getSommet1().getx(), m_Cube.getSommet1().gety(),
                 m_Cube.getSommet1().getz());
    glColor3f(0.0f, 1.0f, 0.0f);
    initSphereObjWrapper(0.1);

    glPopMatrix();

    // sommet 2 bas
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glTranslatef(m_Cube.getSommet2().getx(), m_Cube.getSommet2().gety(),
                 m_Cube.getSommet2().getz());
    glColor3f(1.0f, 0.0f, 0.0f);
    initSphereObjWrapper(0.1);

    glPopMatrix();

    // sommet 3 bas
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glTranslatef(m_Cube.getSommet3().getx(), m_Cube.getSommet3().gety(),
                 m_Cube.getSommet3().getz());
    glColor3f(0.0f, 1.0f, 0.0f);
    initSphereObjWrapper(0.1);

    glPopMatrix();

    // sommet 4 bas
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glTranslatef(m_Cube.getSommet4().getx(), m_Cube.getSommet4().gety(),
                 m_Cube.getSommet4().getz());
    initSphereObjWrapper(0.1);
    glColor3f(0.0f, 1.0f, 0.0f);
    glPopMatrix();

    // sommet 5 haut
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glTranslatef(m_Cube.getSommet5().getx(), m_Cube.getSommet5().gety(),
                 m_Cube.getSommet5().getz());
    initSphereObjWrapper(0.1);
    glColor3f(0.0f, 1.0f, 0.0f);
    glPopMatrix();

    // sommet 6 haut
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glTranslatef(m_Cube.getSommet6().getx(), m_Cube.getSommet6().gety(),
                 m_Cube.getSommet6().getz());
    initSphereObjWrapper(0.1);
    glColor3f(0.0f, 1.0f, 0.0f);
    glPopMatrix();

    // sommet 7 haut
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glTranslatef(m_Cube.getSommet7().getx(), m_Cube.getSommet7().gety(),
                 m_Cube.getSommet7().getz());
    initSphereObjWrapper(0.1);
    glColor3f(0.0f, 1.0f, 0.0f);
    glPopMatrix();

    // sommet 8 haut
    glPushMatrix();
    glTranslatef(m_Cube.getRigidBody()->getPosition().getx(),
                 m_Cube.getRigidBody()->getPosition().gety(),
                 m_Cube.getRigidBody()->getPosition().getz());
    glTranslatef(m_Cube.getSommet8().getx(), m_Cube.getSommet8().gety(),
                 m_Cube.getSommet8().getz());
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
    glEnable(GL_LIGHTING);
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

    glColor3f(0.2, 0.5, 0.7);

    // broad phase
    // on test quel objet peuvent être en collision avec bvh
    /*
	std::cout <<"tree"<<m_tree.getobject()->getCenterVolumeEng().getx()<<m_tree.getobject()->getCenterVolumeEng().gety()<<m_tree.getobject()->getCenterVolumeEng().getz() << std::endl;
	std::cout <<"left son"<<m_tree.getLeftSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getLeftSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getLeftSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
	std::cout <<"right son"<<m_tree.getRightSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getRightSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getRightSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
	std::cout <<"lef left son"<<m_tree.getLeftSon()->getLeftSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getLeftSon()->getLeftSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getLeftSon()->getLeftSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
    std::cout <<"lef right son"<<m_tree.getLeftSon()->getRightSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getLeftSon()->getRightSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getLeftSon()->getRightSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
    std::cout <<"right right son"<<m_tree.getRightSon()->getRightSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getRightSon()->getRightSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getRightSon()->getRightSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
	std::cout <<"lef left son"<<m_tree.getRightSon()->getLeftSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getRightSon()->getLeftSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getRightSon()->getLeftSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
	*/
	 BVH* Leftson = new BVH();
	 BVH* Rightson =new BVH();
	m_tree.setLeftSon(Leftson);
	m_tree.setRightSon(Rightson);
	BVH* Cube1 = new BVH(&m_Cube);
    BVH *Mur1 = new BVH(&m_mur1);
    BVH* Mur2 = new BVH(&m_mur2);
	BVH* Mur3 = new BVH(&m_mur3);
	m_tree.getLeftSon()->setLeftSon(Mur3);
	m_tree.getLeftSon()->setRightSon(Cube1);
        m_tree.getRightSon()->setRightSon(Mur2);
        m_tree.getRightSon()->setLeftSon(Mur1);
		/*std::cout <<"tree"<<m_tree.getobject()->getCenterVolumeEng().getx()<<m_tree.getobject()->getCenterVolumeEng().gety()<<m_tree.getobject()->getCenterVolumeEng().getz() << std::endl;
	std::cout <<"left son"<<m_tree.getLeftSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getLeftSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getLeftSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
	std::cout <<"right son"<<m_tree.getRightSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getRightSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getRightSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
	std::cout <<"lef left son"<<m_tree.getLeftSon()->getLeftSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getLeftSon()->getLeftSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getLeftSon()->getLeftSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
    std::cout <<"lef right son"<<m_tree.getLeftSon()->getRightSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getLeftSon()->getRightSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getLeftSon()->getRightSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
    std::cout <<"right right son"<<m_tree.getRightSon()->getRightSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getRightSon()->getRightSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getRightSon()->getRightSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
	std::cout <<"lef left son"<<m_tree.getRightSon()->getLeftSon()->getobject()->getCenterVolumeEng().getx()<<m_tree.getRightSon()->getLeftSon()->getobject()->getCenterVolumeEng().gety()<<m_tree.getRightSon()->getLeftSon()->getobject()->getCenterVolumeEng().getz() << std::endl;
	*/
	generateCollisions(m_tree);
    if (m_collisiondata.getContactRestant() > 0) {
        m_Cube.getRigidBody()->setVelocity(Vector3D(0.0, 0.0, 0.0));
		m_Cube.getRigidBody()->setAngularVelocity(Vector3D(0.0, 0.0, 0.0));
		gravity = Vector3D(0, 0, 0);
                std::cout << "Point d'impact : ("
                          << m_collisiondata.getContacts().at(0).getContactPoint().getx() << ","
                          << m_collisiondata.getContacts().at(0).getContactPoint().gety() << ","
                          << m_collisiondata.getContacts().at(0).getContactPoint().getz() << ")"
                          << std::endl;
				std::cout << "Normale Point d'impact : ("
                          << m_collisiondata.getContacts().at(0).getContactNormal().getx() << ","
                          << m_collisiondata.getContacts().at(0).getContactNormal().gety() << ","
                          << m_collisiondata.getContacts().at(0).getContactNormal().getz() << ")"
                          << std::endl;
				std::cout <<" Penetration"" : ("
                          << m_collisiondata.getContacts().at(0).getPenetration() << ")"
                          << std::endl;
	}

    def_room();

    def_cube();

    // On ajoute la force de gravité
    m_Cube.getRigidBody()->AddForceAtBodyPoint(gravity, Vector3D(0, 0, 0));
    // on integrate
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
        // force sur arete en x et y
        //m_Cube.getRigidBody()->AddForceAtBodyPoint(Vector3D(-0.015, 0.020, 0.0), Vector3D(0.5, 0.5, 0.0));
        // force sur le point d'origine donc sans rotation
        //m_Cube.getRigidBody()->AddForceAtBodyPoint(Vector3D(-0.015, 0.028, 0.0), Vector3D(0.0, 0.0, 0.0));
        // force sur une arete en y et z
         //m_Cube.getRigidBody()->AddForceAtBodyPoint(Vector3D(0.0, 0.020, 0.03), Vector3D(0.0, 0.5, -0.5));
        // force sur sommet rouge en x et y et z
         //m_Cube.getRigidBody()->AddForceAtBodyPoint(Vector3D(-0.015, 0.015555, 0.015), Vector3D(0.5, -0.5, -0.5));
        // force sur sommet arete au dessus et a droite du sommet rouge en x et z
        m_Cube.getRigidBody()->AddForceAtBodyPoint(Vector3D(-0.090, 0.000, 0.010),Vector3D(-0.5, 0.0, -0.5));
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