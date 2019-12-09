#pragma once
#include "RigidBody.h"
#include "Vector3D.h"
#include "Contact.h"
#include "Primitive.h"

using namespace std;
class Plane : public Primitive
{
private:
		//La normale sera finalement accessible dans primitive car nécessaire lors du calcul de l'interpénétration dans generate contacts
        
    //position de la primitive par rapport au centre de l'objet
		//offset correspond ici à la distance du plan par rapport au centre de l'objet(cube)
        
    

public:
        Plane(){};
		Plane(Vector3D Position, Vector3D normal, float offset);
        Vector3D getPosition() { return Position; }
        RigidBody* getRigidBody() { return body; };
        


};