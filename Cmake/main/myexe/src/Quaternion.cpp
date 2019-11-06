#include "Quaternion.h"
#include <math.h>

Quaternion::Quaternion(float p_R, float p_I, float p_J, float p_K)
{
    m_R = p_R;
    m_I = p_I;
    m_J = p_J;
    m_K = p_K;
}

Quaternion::Quaternion(Quaternion& p_Other)
{
    m_R = p_Other.m_R;
    m_I = p_Other.m_I;
    m_J = p_Other.m_J;
    m_K = p_Other.m_K;
}

void Quaternion::Normalize()
{
    float l_D = pow(m_R, 2) + pow(m_I, 2) + pow(m_J, 2) + pow(m_K, 2);
    if (l_D == 0) { m_R = 1; }
    else
    {
        l_D = 1 / sqrt(l_D);
        m_R *= l_D;
        m_I *= l_D;
        m_J *= l_D;
        m_K *= l_D;
    }
}

void Quaternion::operator*=(Quaternion p_Other)
{
    m_R *= p_Other.m_R;
    m_I *= p_Other.m_I;
    m_J *= p_Other.m_J;
    m_K *= p_Other.m_K;
}

void Quaternion::RotateByVector(Vector3D p_Vector)
{
    Quaternion l_Q = Quaternion(0, p_Vector.getx(), p_Vector.gety(), p_Vector.getz());
    operator*=(l_Q);
}

void Quaternion::UpdateAngularVelocity(Vector3D p_Vector, float p_Time)
{
    Normalize();
    Quaternion l_Q = Quaternion(m_R, m_I, m_J, m_K);
    Quaternion l_Omega = Quaternion(0, p_Vector.getx(), p_Vector.gety(), p_Vector.getz());

    l_Q *= (l_Omega);
    l_Q.Normalize();

    l_Q.m_R *= (p_Time / 2);
    l_Q.m_I *= (p_Time / 2);
    l_Q.m_J *= (p_Time / 2);
    l_Q.m_K *= (p_Time / 2);

    l_Q.Normalize();

    m_R += l_Q.m_R;
    m_I += l_Q.m_I;
    m_J += l_Q.m_J;
    m_K += l_Q.m_K;
}

float Quaternion::getI() 
{ 
	return m_I; 
}

float Quaternion::getJ() { return m_J; }

float Quaternion::getK() { return m_K; }

float Quaternion::getR() { return m_R; }