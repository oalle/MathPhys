#include"Plane.h"

Plane::Plane(Vector3D Position, Vector3D normal, float offset)
{
    this->body = NULL;
    boundingsphere.center = Position;
    boundingsphere.rayon = offset;
    this->Position = Position;
    this->normal = normal;
    this->offset = offset;
}