#pragma once
#include "Vector3D.h"
#include"Quaternion.h"
#include "Matrix3.h"
#include"Matrix4.h"
class RigidBody
{

protected:
    float inverseMass;
    float linearDamping;
    Vector3D position;
    Vector3D velocity;
    Quaternion Orientation;
    Vector3D Rotation;
    Matrix3 transformMatrix;
    Matrix4 m;

public:

    void calculDonnéesDérivées();
}