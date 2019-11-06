#pragma once
#include "Vector3D.h"

class Quaternion
{
private:
	float m_R;
	float m_I;
	float m_J;
	float m_K;
public:
	Quaternion(float p_R, float p_I, float p_J, float p_K);
	Quaternion(Quaternion& p_Other);
	void Normalize();
	void operator*=(Quaternion p_Other);
	void RotateByVector(Vector3D p_Vector);
	void UpdateAngularVelocity(Vector3D p_Vector, float p_Time);
    float getR();
    float getI();
    float getJ();
    float getK();
};
