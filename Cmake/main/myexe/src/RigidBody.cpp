#include "RigidBody.h"

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
    Vector3D pointRelatif = m_Position - p_Point.ChangingBase(m_TransformMatrix); // pas sur de la conversion
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