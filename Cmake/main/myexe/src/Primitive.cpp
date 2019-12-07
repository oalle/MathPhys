#include"Primitive.h"

Primitive::Primitive(RigidBody * body, Vector3D Position)
{ 
	this->body = body; 
	this->Position = Position;
}