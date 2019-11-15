#pragma once
#include "Vector3D.h"
#include "Quaternion.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include <math.h>
class RigidBody
{

private:
    float m_InverseMass;
    float m_LinearDamping;
    Vector3D m_Position;
    Vector3D m_Velocity;
    Quaternion m_Orientation;
    Vector3D m_Rotation;
    Matrix4 m_TransformMatrix;
    Matrix3 m_InverseInertieTensor;
	float m_AngularDamping;

	Vector3D forceAccum;
	Vector3D torqueAccum;

public:
    void DerivedData();
	void AddForceAtPoint(Vector3D p_Force, Vector3D p_Point);
	void AddForceAtBodyPoint(Vector3D p_Force, Vector3D p_Point);
};