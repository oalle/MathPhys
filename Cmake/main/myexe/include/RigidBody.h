#pragma once
#include "Vector3D.h"
#include "Quaternion.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include <math.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
class RigidBody
{

private:
    float m_InverseMass;
    float m_LinearDamping;
	float m_AngularDamping;
    Vector3D m_Position; // position du centre de masse du rigidbody
    Vector3D m_Velocity;
	Vector3D m_Acceleration;
    Vector3D m_AngularAcceleration;
	Vector3D m_AngularVelocity;
    Quaternion m_Orientation;
    Vector3D m_Rotation;
    Matrix3 m_TransformMatrix;
    Matrix3 m_InverseInertieTensor;
	

	Vector3D forceAccum;
	Vector3D torqueAccum;

public:
        RigidBody(){};
	RigidBody(float InverseMass,  float LinearDamping, float AngularDamping, Vector3D Position , Quaternion Orientation);
	//Constructeur de recopie de la classe particule
	//param : &particule : l'adresse de la particule qu'il faut recopier
	RigidBody(const RigidBody& p_RigidBody);
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
    Vector3D getPosition() { return m_Position; };
    Matrix3 getTransformMatrix() { return m_TransformMatrix; };
    Matrix3 getInverseInertieTensor() { return m_InverseInertieTensor; };
    Quaternion getOrientation() { return m_Orientation; };
	float getMasse() { return 1/m_InverseMass; };
	//Surcharge de l'operateur de comparaison pour la classe particule
	//param : &particule : l'adresse de la particule a comparer
	bool operator==(RigidBody& p_RigidBody);
	
};