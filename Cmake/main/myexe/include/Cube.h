#pragma once
#include "RigidBody.h"
#include "Vector3D.h"
#include "Primitive.h"

class Cube : public Primitive
{
private :
    Vector3D Sommet1bas;
	Vector3D Sommet2bas;
	Vector3D Sommet3bas;
	Vector3D Sommet4bas;
	Vector3D Sommet5haut;
	Vector3D Sommet6haut;
	Vector3D Sommet7haut;
	Vector3D Sommet8haut;
    Vector3D Halfsize;
	

public:
	
    
	Cube(float InverseMass, float LinearDamping, float AngularDamping,
                     Vector3D Positionrigid, Quaternion Orientation, Vector3D Position, Vector3D Halfsize);
	Cube();
	~Cube();

	Vector3D getSommet1() { return Sommet1bas; };
	Vector3D getSommet2() { return Sommet2bas; };
	Vector3D getSommet3() { return Sommet3bas; };
	Vector3D getSommet4() { return Sommet4bas; };
	Vector3D getSommet5() { return Sommet5haut; };
	Vector3D getSommet6() { return Sommet6haut; };
	Vector3D getSommet7() { return Sommet7haut; };
	Vector3D getSommet8() { return Sommet8haut; };
	//Methode pour calculer les donnees derivees du corps rigide
    void DerivedData();

	void IntegrateCube(float frameTime);


};