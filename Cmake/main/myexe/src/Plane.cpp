#include "Plane.h"

// Constructeur a trois parametres de la classe Plane
// param : Position : la position de plan
// param : normal : la normal du plan
// param : offset : l'offset du plan
Plane::Plane(Vector3D Position, Vector3D normal, float offset)
{
    this->body = NULL;
    boundingsphere.center = Position;
    boundingsphere.rayon = offset;
    this->Position = Position;
    this->normal = normal;
    this->offset = offset;
}