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
        Contact(Vector3D contactPoint, Vector3D contactNormal, float penetration)
        {
            this->contactPoint = contactPoint;
            this->contactNormal = contactNormal;
            this->penetration = penetration;
        };
        Vector3D getContactPoint() { return contactPoint; };
		Vector3D getContactNormal(){return contactNormal;};
        float getPenetration() { return penetration; };
    
};