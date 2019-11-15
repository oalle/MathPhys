#pragma once
#include "Vector3D.h"
#include "Quaternion.h"
#include "Matrix3.h"
#include "Matrix4.h"
class RigidBody
{

protected:
    float m_InverseMass;
    float m_LinearDamping;
    Vector3D m_Position;
    Vector3D m_Velocity;
    Quaternion m_Orientation;
    Vector3D m_Rotation;
    Matrix3 m_TransformMatrix;
    Matrix4 m;

public:
    void CalculDerivee();
};