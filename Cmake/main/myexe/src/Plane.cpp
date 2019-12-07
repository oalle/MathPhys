#include"Plane.h"

Plane::Plane(Vector3D Position, Vector3D normal, float offset)
{
    this->body = new RigidBody();
    body->setCenterVolumeEng(Position);
    body->setRayonVolemeEng(offset);
    this->Position = Position;
    this->normal = normal;
    this->offset = offset;
}