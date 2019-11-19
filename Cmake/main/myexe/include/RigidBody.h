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
    Vector3D m_Position; // position du centre de masse du rigidbody
    Vector3D m_Velocity;
	Vector3D m_Acceleration;
    Vector3D m_AngularAcceleration;
	Vector3D m_AngularVelocity;
    Quaternion m_Orientation;
    Vector3D m_Rotation;
    Matrix3 m_TransformMatrix;
    Matrix3 m_InverseInertieTensor;
	float m_AngularDamping;

	Vector3D forceAccum;
	Vector3D torqueAccum;

public:
	//Methode pour calculer les donnees derivees du corps rigide
    void DerivedData();

	//Methode pour ajouter un force a un point 
	//Param : p_Force : le vecteur correspondant a la force a appliquer
	//Param : p_Point : le point sur le quel on doit ajouter la force
	void AddForceAtPoint(Vector3D p_Force, Vector3D p_Point);

	//Methode pour ajouter une force a un point du corps rigide
	//Param : p_Force : le vecteur correspondant a la force a appliquer
	//Param : p_Point : le point sur le quel on doit ajouter la force
	void AddForceAtBodyPoint(Vector3D p_Force, Vector3D p_Point);

	//Methode pour l'integrateur
    void integrate(float frametime);

	//Fonction pour nettoyer la resultante courante
	void clearAccum();

	
};