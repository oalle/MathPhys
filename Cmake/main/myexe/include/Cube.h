#pragma once
#include "Primitive.h"
#include "RigidBody.h"
#include "Vector3D.h"

class Cube : public Primitive
{
private:
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
    // Constructeur a 7 parametres de la classe Cube
    // param : InverseMass : l'inverse de la masse du cube
    // param : LinearDamping : le damping lineaire du cube
    // param : AngularDamping : le damping angulaire du cube
    // param : Positionrigid : la position du rigidBody du cube
    // param : Orientation : le quaternion d'orientationd du cube
    // param : Position : la position du cube
    // param : HalfSize : la demi longueur de l'arrete du cube
    Cube(float InverseMass, float LinearDamping, float AngularDamping, Vector3D Positionrigid,
         Quaternion Orientation, Vector3D Position, Vector3D Halfsize);

    // Constructeur par defaut de la classe Cube
    Cube();

    // Destructeur par defaut de la classe Cube
    ~Cube();

    // Getter pour le premier sommet du cube
    // return : la position du premier sommet du cube
    Vector3D getSommet1() { return Sommet1bas; };

    // Getter pour le deuxieme sommet du cube
    // return : la position du deuxieme sommet du cube
    Vector3D getSommet2() { return Sommet2bas; };

    // Getter pour le troisieme sommet du cube
    // return : la position du troisieme sommet du cube
    Vector3D getSommet3() { return Sommet3bas; };

    // Getter pour le quatrieme sommet du cube
    // return : la position du quatrieme sommet du cube
    Vector3D getSommet4() { return Sommet4bas; };

    // Getter pour le cinquieme sommet du cube
    // return : la position du cinquieme sommet du cube
    Vector3D getSommet5() { return Sommet5haut; };

    // Getter pour le sixieme sommet du cube
    // return : la position du sixieme sommet du cube
    Vector3D getSommet6() { return Sommet6haut; };

    // Getter pour le septieme sommet du cube
    // return : la position du septieme sommet du cube
    Vector3D getSommet7() { return Sommet7haut; };

    // Getter pour le huitieme sommet du cube
    // return : la position du huitieme sommet du cube
    Vector3D getSommet8() { return Sommet8haut; };

    // Methode pour calculer les donnees derivees du corps rigide
    void DerivedData();

    // Methode pour l'integrateur du cube
    // param : frameTime : le temps de la frame avec le quel on doit faire les calcul
    void IntegrateCube(float frameTime);
};