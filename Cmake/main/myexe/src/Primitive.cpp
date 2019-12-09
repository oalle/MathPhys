#include "Primitive.h"

// Constructeur a 6 arguments de la classe Primitive
// param : InverseMass : l'inverse de la masse de la primitive
// param : LinearDamping : la valeur du linear damping de la primitive
// param : AngularDamping : la valeur du damping aangulaire de la primitive
// param : Positionrigid : la position du rigid body de la primitive
// param : Orientation : le quaternion d'orientation de la primitive
// param : Position : la position de la primitive
Primitive::Primitive(float InverseMass, float LinearDamping, float AngularDamping,
                     Vector3D Positionrigid, Quaternion Orientation, Vector3D Position)
{
    this->body =
        new RigidBody(InverseMass, LinearDamping, AngularDamping, Positionrigid, Orientation);
    this->Position = Position;
    boundingsphere = {Vector3D(), 0.0};
}

// Constructeur a 2 parametres de la classe Primitive
// param : body : le rigid body de la primitive
// param : Position : la position de la primitive
Primitive::Primitive(RigidBody* body, Vector3D Position)
{
    this->body = body;
    this->Position = Position;
}