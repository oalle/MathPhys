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
    // Constructeur a 3 parametre de la classe Contact
    // param : contactPoint : le point de contact entre deux objets
    // param : contactNormal : la normal au point de contact
    // param : penetration : la valeur de l'interpenetration du contact
    Contact(Vector3D contactPoint, Vector3D contactNormal, float penetration)
    {
        this->contactPoint = contactPoint;
        this->contactNormal = contactNormal;
        this->penetration = penetration;
    };

    // Getter pour l'attribut contactPoint de la classe Contact
    // return : la valeur de contactPoint
    Vector3D getContactPoint() { return contactPoint; };

    // Getter pour l'attribut contactNormal de la classe Contact
    // return : la valeur de l'attribut contactNormal
    Vector3D getContactNormal() { return contactNormal; };

    // Getter pour l'attribut penetration de la classe Contact
    // return : la valeur de l'attribut penetration
    float getPenetration() { return penetration; };
};