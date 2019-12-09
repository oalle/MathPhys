#include "Cube.h"
#include <math.h>

Cube::Cube(float InverseMass, float LinearDamping, float AngularDamping, Vector3D Positionrigid,
           Quaternion Orientation,Vector3D Position, Vector3D Halfsize)
    : Primitive(InverseMass, LinearDamping, AngularDamping, Positionrigid, Orientation, Position)
{
    this->Halfsize = Halfsize;
    Sommet1bas = Vector3D(Halfsize.getx(), -Halfsize.gety(), Halfsize.getz());
    Sommet2bas = Vector3D(Halfsize.getx(), -Halfsize.gety(), -Halfsize.getz());
    Sommet3bas = Vector3D(-Halfsize.getx(), -Halfsize.gety(), -Halfsize.getz());
    Sommet4bas = Vector3D(-Halfsize.getx(), -Halfsize.gety(), Halfsize.getz());
    Sommet5haut = Vector3D(Halfsize.getx(), Halfsize.gety(), Halfsize.getz());
    Sommet6haut = Vector3D(Halfsize.getx(), Halfsize.gety(), -Halfsize.getz());
    Sommet7haut = Vector3D(-Halfsize.getx(), Halfsize.gety(), -Halfsize.getz());
    Sommet8haut = Vector3D(-Halfsize.getx(), Halfsize.gety(), Halfsize.getz());
    boundingsphere.center = Vector3D(Position.getx(), Position.gety(), Position.getz());
    boundingsphere.rayon = Sommet1bas.norme();
    this->Position = Position;

}
Cube::Cube() {}

Cube::~Cube() {}

void Cube::DerivedData()
{
    // update transform matrix
	
    body->getTransformMatrix().setOrientation(body->getOrientation());
	
    // update inertie tensor
	//on prend comme distance entre les sommets et l'axe de rotation (sur le centre de masse) une distance de 0.5 car chaque coordonn�e de sommet est de 0.5
	//sur n'importe quel axe
    float l_Ix = body->getMasse() * (float) pow(0.5, 2)*8;
    float l_Iy = body->getMasse() * (float) pow(0.5, 2)*8;
    float l_Iz = body->getMasse() * (float) pow(0.5, 2)*8;
    float l_Ixy = body->getMasse() * (float) 0.5 * (float) 0.5*8;
    float l_Ixz = body->getMasse() * (float) 0.5 * (float) 0.5*8;
    float l_Iyz = body->getMasse() * (float) 0.5 * (float) 0.5*8;

    float l_Tab[9] = {l_Ix, l_Ixy, l_Ixz, l_Ixy, l_Iy, l_Iyz, l_Ixz, l_Iyz, l_Iz};
   body->SetMatriceTensor(Matrix3(l_Tab).MatriceInverse());
}

//integreur du cube, permet de mettre � jour les sommet du cube en fonction de l'orientation
void Cube::IntegrateCube(float frameTime) { 
	body->integrate(frameTime); 
	// calcul derived data
    DerivedData();

	//pour faire la rotation j'utilise les coordonn�es d'origine des sommets
    Sommet1bas = body->getOrientation().RotateVectorWithQuaternion(Vector3D(Halfsize.getx(), -Halfsize.gety(), Halfsize.getz()));
	Sommet2bas = body->getOrientation().RotateVectorWithQuaternion(Vector3D(Halfsize.getx(), -Halfsize.gety(), -Halfsize.getz()));
	Sommet3bas = body->getOrientation().RotateVectorWithQuaternion(Vector3D(-Halfsize.getx(), -Halfsize.gety(), -Halfsize.getz()));
	Sommet4bas = body->getOrientation().RotateVectorWithQuaternion(Vector3D(-Halfsize.getx(), -Halfsize.gety(), Halfsize.getz()));
	Sommet5haut = body->getOrientation().RotateVectorWithQuaternion(Vector3D(Halfsize.getx(), Halfsize.gety(), Halfsize.getz()));
	Sommet6haut = body->getOrientation().RotateVectorWithQuaternion(Vector3D(Halfsize.getx(), Halfsize.gety(), -Halfsize.getz()));
	Sommet7haut = body->getOrientation().RotateVectorWithQuaternion(Vector3D(-Halfsize.getx(), Halfsize.gety(), -Halfsize.getz()));
	Sommet8haut = body->getOrientation().RotateVectorWithQuaternion(Vector3D(-Halfsize.getx(), Halfsize.gety(), Halfsize.getz()));

}