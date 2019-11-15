#include "RigidBody.h"
#include <math.h>

void RigidBody::DerivedData() 
{
	float l_Ix = 1 / m_InverseMass * pow(m_Position.getx(), 2);
	float l_Iy = 1 / m_InverseMass * pow(m_Position.gety(), 2);
	float l_Iz = 1 / m_InverseMass * pow(m_Position.getz(), 2);
	float l_Ixy = 1 / m_InverseMass * m_Position.getx() * m_Position.gety();
	float l_Ixz = 1 / m_InverseMass * m_Position.getx() * m_Position.getz();
	float l_Iyz = 1 / m_InverseMass * m_Position.gety() * m_Position.getz();

	float l_Tab[9] = { l_Ix, l_Ixy, l_Ixz, l_Ixy, l_Iy, l_Iyz, l_Ixz, l_Iyz, l_Iz };
	m_InverseInertieTensor = Matrix3(l_Tab).MatriceInverse();
}

void RigidBody::AddForceAtPoint(Vector3D p_Force, Vector3D p_Point)
{
    // convertir p_Point en coord relatives au centre de masse
    Vector3D pointRelatif =
        m_Position - p_Point.ChangingBase(m_TransformMatrix); // pas sur de la conversion
    pointRelatif.normalisation();

    // update forceAccum
    forceAccum += p_Force;
    // update torqueAccum
    torqueAccum += p_Force.prodVectorielle(pointRelatif);
}

void RigidBody::AddForceAtBodyPoint(Vector3D p_Force, Vector3D p_Point)
{
    // convertir p_Point dans le repere du monde
    Vector3D pointRelatif = p_Point.ChangingBase(m_TransformMatrix.MatriceInverse());
    pointRelatif.normalisation();

    AddForceAtPoint(p_Force, pointRelatif);
}

void RigidBody::integrate(float frameTime) 
{
	// calcul acceleration lineaire
	Vector3D AccumForcesTemp = this->forceAccum;
	AccumForcesTemp.mulScalaire(this->m_InverseMass);
	this->m_Acceleration = AccumForcesTemp;

	//calcul acceleration angulaire
	Vector3D torqueAccumTemp = this->torqueAccum;
    Matrix3 inverseInertieTensorTemp = this->m_InverseInertieTensor;
    this->m_AccelerationAngulaire = this->m_InverseInertieTensor.MultiplicationVectorielle(this->torqueAccum);

	// update velocite
	Vector3D AccelerationTemp = this->m_Acceleration;
	AccelerationTemp.mulScalaire(frameTime);
    Vector3D velocityTemp = this->m_Velocity.mulScalaireResult(pow(this->m_LinearDamping, frameTime));
	this->m_Velocity = velocityTemp + AccelerationTemp;
	
	// velocity angular
	
}