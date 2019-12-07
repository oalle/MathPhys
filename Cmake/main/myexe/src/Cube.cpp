#include "Cube.h"
#include <math.h>

Cube::Cube(float InverseMass, float LinearDamping, float AngularDamping, Vector3D Position,
           Quaternion Orientation)
    : RigidBody(InverseMass, LinearDamping, AngularDamping, Position, Orientation)
{
    Sommet1bas = Vector3D(0.5, -0.5, 0.5);
    Sommet2bas = Vector3D(0.5, -0.5, -0.5);
    Sommet3bas = Vector3D(-0.5, -0.5, -0.5);
    Sommet4bas = Vector3D(-0.5, -0.5, 0.5);
    Sommet5haut = Vector3D(0.5, 0.5, 0.5);
    Sommet6haut = Vector3D(0.5, 0.5, -0.5);
    Sommet7haut = Vector3D(-0.5, 0.5, -0.5);
    Sommet8haut = Vector3D(-0.5, 0.5, 0.5);
    boundingsphere.center = Vector3D(Position.getx(), Position.gety(), Position.getz());
    boundingsphere.rayon = Sommet1bas.norme();

}
Cube::Cube() {}

Cube::~Cube() {}

void Cube::DerivedData()
{
    // update transform matrix
	
    m_TransformMatrix.setOrientation(m_Orientation);
	
    // update inertie tensor
	//on prend comme distance entre les sommets et l'axe de rotation (sur le centre de masse) une distance de 0.5 car chaque coordonn�e de sommet est de 0.5
	//sur n'importe quel axe
    float l_Ix = 1 / m_InverseMass * (float) pow(0.5, 2)*8;
    float l_Iy = 1 / m_InverseMass * (float) pow(0.5, 2)*8;
    float l_Iz = 1 / m_InverseMass * (float) pow(0.5, 2)*8;
    float l_Ixy = 1 / m_InverseMass * (float) 0.5 * (float) 0.5*8;
    float l_Ixz = 1 / m_InverseMass * (float) 0.5 * (float) 0.5*8;
    float l_Iyz = 1 / m_InverseMass * (float) 0.5 * (float) 0.5*8;

    float l_Tab[9] = {l_Ix, l_Ixy, l_Ixz, l_Ixy, l_Iy, l_Iyz, l_Ixz, l_Iyz, l_Iz};
    m_InverseInertieTensor = Matrix3(l_Tab).MatriceInverse();
}

//integreur du cube, permet de mettre � jour les sommet du cube en fonction de l'orientation
void Cube::IntegrateCube(float frameTime) { 
	integrate(frameTime); 
	// calcul derived data
    DerivedData();

	//pour faire la rotation j'utilise les coordonn�es d'origine des sommets
    Sommet1bas = m_Orientation.RotateVectorWithQuaternion(Vector3D(0.5, -0.5, 0.5));
	Sommet2bas = m_Orientation.RotateVectorWithQuaternion(Vector3D(0.5, -0.5, -0.5));
	Sommet3bas = m_Orientation.RotateVectorWithQuaternion(Vector3D(-0.5, -0.5, -0.5));
	Sommet4bas = m_Orientation.RotateVectorWithQuaternion(Vector3D(-0.5, -0.5, 0.5));
	Sommet5haut = m_Orientation.RotateVectorWithQuaternion(Vector3D(0.5, 0.5, 0.5));
	Sommet6haut = m_Orientation.RotateVectorWithQuaternion(Vector3D(0.5, 0.5, -0.5));
	Sommet7haut = m_Orientation.RotateVectorWithQuaternion(Vector3D(-0.5, 0.5, -0.5));
	Sommet8haut = m_Orientation.RotateVectorWithQuaternion(Vector3D(-0.5, 0.5, 0.5));

}