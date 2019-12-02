#pragma once
#include "Vector3D.h"
class Vector3D;

class Quaternion
{
private:
	float m_R;
	float m_I;
	float m_J;
	float m_K;
public:
    Quaternion(){};
	//Constructeurs a 4 parametres de la classe Quaternions
	//Param : p_R : le premier float du Quaternion
	//Param : p_I : le deuxieme float du Quaternion
	//Param : p_J : le troisieme float du Quaternion
	//Param : p_K : le quatrieme float du Quaternion
	Quaternion(float p_R, float p_I, float p_J, float p_K);

	//Constructeur de recopie pour la classe Quaternion
	//Param : p_Other : le Quaternion a reccopier
	Quaternion(Quaternion& p_Other);

	//Methode pour normaliser un quaternion
	void Normalize();

	//Surcharge de l'operateur *=
	void operator*=(Quaternion p_Other);

	//Methode pour faiire la rotation d'un quaternion
	//Param : p_Vector : le vecteur pour la rotation
	void RotateByVector(Vector3D p_Vector);

	Vector3D RotateVectorWithQuaternion(Vector3D p_Vector);

	//Methode pour mettre a jour la velocite angulaire du quaternion
	//Param : p_Vector : le vecteur pour la velocite angulaire
	void UpdateAngularVelocity(Vector3D p_Vector, float p_Time);

	//Getter pour le premier float du quaternion
    float getR();

	//Getter pour le deuxieme float du quaternion
    float getI();

	//Getter pour le troisieme float du quaternion
    float getJ();

	//Getter pour le quatrieme float du quaternion
    float getK();
	bool operator==(const Quaternion& p_Quaternion);
};
