#include "RigidBody.h"

void RigidBody::DerivedData() 
{

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