#pragma once
#include "RigidBody.h"
#include "Vector3D.h"

using namespace std;
class Contact
{
private:
    
        Vector3D contactPoint;
		Vector3D contactNormal;
        float penetration;
    

public:
        Contact(){};
    
};