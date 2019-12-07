#pragma once
#include "RigidBody.h"
#include "Vector3D.h"
#include "Contact.h"
#include "Primitive.h"

using namespace std;
class Plane : public Primitive
{
private:
    
        Vector3D normal;
    //position de la primitive par rapport au centre de l'objet
        float offset;
    

public:
        Plane(){};
		Plane(Vector3D Position, Vector3D normal, float offset);
        Vector3D getPosition() { return Position; }
        RigidBody* getRigidBody() { return body; };


};