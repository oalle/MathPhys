#pragma once
#include "Contact.h"
#include "RigidBody.h"
#include "Vector3D.h"

using namespace std;
class Primitive
{
protected:
    RigidBody* body;
    // position de la primitive par rapport au centre de l'objet
    Vector3D Position;
    struct BoundingSphere
    {
        Vector3D center;
        float rayon;
    };

    BoundingSphere boundingsphere;
    // attribut pour plane
    Vector3D normal;
    float offset;

public:
    // Constructeur par defaut de la classe Primitive
    Primitive() { boundingsphere = {Vector3D(), 0.0}; };

    // Constructeur a 6 arguments de la classe Primitive
    // param : InverseMass : l'inverse de la masse de la primitive
    // param : LinearDamping : la valeur du linear damping de la primitive
    // param : AngularDamping : la valeur du damping aangulaire de la primitive
    // param : Positionrigid : la position du rigid body de la primitive
    // param : Orientation : le quaternion d'orientation de la primitive
    // param : Position : la position de la primitive
    Primitive(float InverseMass, float LinearDamping, float AngularDamping, Vector3D Positionrigid,
              Quaternion Orientation, Vector3D Position);

    // Constructeur a 2 parametres de la classe Primitive
    // param : body : le rigid body de la primitive
    // param : Position : la position de la primitive
    Primitive(RigidBody* body, Vector3D Position);

    // Getter pour le rayon de la bouding sphere
    // return : le rayon de la bounding sphere
    float getRayonVolemeEng() { return boundingsphere.rayon; };

    // Getter pour le centre de la bounding sphere
    // return : la position du centre de la bounding sphere
    Vector3D getCenterVolumeEng() { return boundingsphere.center; };

    // Setter pour le rayon de la bounding sphere
    // param : rayon : le rayon de la bounding sphere
    void setRayonVolemeEng(float rayon) { boundingsphere.rayon = rayon; };

    // Setter pour la position du centre de la boudning sphere
    // param : vector : la position du centre de la boudning sphere
    void setCenterVolumeEng(Vector3D vector) { boundingsphere.center = vector; };

    // Getter pour l'attribut body de la classe Primitive
    // return : le rigidBody de la Primitive
    RigidBody* getRigidBody() { return body; };

    // Getter pour l'attribut position de la classe Primitive
    // return : la position de la Primitive
    Vector3D getPosition() { return Position; };

    // Getter pour l'attribut normal de la primitive
    // return : la valeur de la normal de la Primitive
    Vector3D getnormal() { return normal; };

    // Getter pour l'attribut offset de la primitive
    // return : l'offset de la primitive
    float getoffset() { return offset; };
};