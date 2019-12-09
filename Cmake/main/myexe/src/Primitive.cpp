#include "Primitive.h"
Primitive::Primitive(float InverseMass, float LinearDamping, float AngularDamping,
                     Vector3D Positionrigid, Quaternion Orientation, Vector3D Position) 
{
    this->body =  new RigidBody(InverseMass, LinearDamping, AngularDamping, Positionrigid, Orientation);
	this->Position = Position;
	boundingsphere = {Vector3D(), 0.0};

}


Primitive::Primitive(RigidBody* body, Vector3D Position)
    {
        this->body = body;
        this->Position = Position;
    }