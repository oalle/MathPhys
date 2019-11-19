#include "Quaternion.h"
#include <math.h>

//Constructeurs a 4 parametres de la classe Quaternions
//Param : p_R : le premier float du Quaternion
//Param : p_I : le deuxieme float du Quaternion
//Param : p_J : le troisieme float du Quaternion
//Param : p_K : le quatrieme float du Quaternion
Quaternion::Quaternion(float p_R, float p_I, float p_J, float p_K)
{
    m_R = p_R;
    m_I = p_I;
    m_J = p_J;
    m_K = p_K;
}

//Constructeur de recopie pour la classe Quaternion
//Param : p_Other : le Quaternion a reccopier
Quaternion::Quaternion(Quaternion& p_Other)
{
    m_R = p_Other.m_R;
    m_I = p_Other.m_I;
    m_J = p_Other.m_J;
    m_K = p_Other.m_K;
}

//Methode pour normaliser un quaternion
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

//Surcharge de l'operateur *=
void Quaternion::operator*=(Quaternion p_Other)
{
    m_R *= p_Other.m_R;
    m_I *= p_Other.m_I;
    m_J *= p_Other.m_J;
    m_K *= p_Other.m_K;
}

//Methode pour faiire la rotation d'un quaternion
//Param : p_Vector : le vecteur pour la rotation
void Quaternion::RotateByVector(Vector3D p_Vector)
{
    Quaternion l_Q = Quaternion(0, p_Vector.getx(), p_Vector.gety(), p_Vector.getz());
    operator*=(l_Q);
}

//Methode pour mettre a jour la velocite angulaire du quaternion
//Param : p_Vector : le vecteur pour la velocite angulaire
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

//Getter pour le premier float du quaternion
float Quaternion::getI() { return m_I; }

//Getter pour le deuxieme float du quaternion
float Quaternion::getJ() { return m_J; }

//Getter pour le troisieme float du quaternion
float Quaternion::getK() { return m_K; }

//Getter pour le quatrieme float du quaternion
float Quaternion::getR() { return m_R; }