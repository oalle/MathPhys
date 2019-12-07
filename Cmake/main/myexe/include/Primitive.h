#pragma once
#include "RigidBody.h"
#include "Vector3D.h"
#include "Contact.h"

using namespace std;
class Primitive
{
protected:
    
        RigidBody * body;
    //position de la primitive par rapport au centre de l'objet
		Vector3D Position;
    

public:
        Primitive(){};
		Primitive(RigidBody * body, Vector3D Position);
    
};