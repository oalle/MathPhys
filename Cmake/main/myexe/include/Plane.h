#pragma once
#include "Contact.h"
#include "Primitive.h"
#include "RigidBody.h"
#include "Vector3D.h"

//using namespace std;
class Plane : public Primitive
{
private:
    // La normale sera finalement accessible dans primitive car nécessaire lors du calcul de
    // l'interpénétration dans generate contacts

    // position de la primitive par rapport au centre de l'objet
    // offset correspond ici à la distance du plan par rapport au centre de l'objet(cube)

public:
    // Constructeur par defaut de la classe Plane
    Plane(){};

    // Constructeur a trois parametres de la classe Plane
    // param : Position : la position de plan
    // param : normal : la normal du plan
    // param : offset : l'offset du plan
    Plane(Vector3D Position, Vector3D normal, float offset);

    // Getter pour l'attribut Position de la classe Primitive
    // return : la position du plan
    Vector3D getPosition() { return Position; }

    // Getter pour l'attribut body de la classe Primitive
    // return : la valeur du rigidBody du plan
    RigidBody* getRigidBody() { return body; };
};