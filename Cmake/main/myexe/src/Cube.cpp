#include "..\include\Cube.h"

Cube::Cube() : RigidBody()
{
    m_EdgeHalfLength = 1;
    updateVertexList();
}

Cube::Cube(double p_EdgeHalfLength, float InverseMass, float LinearDamping, float AngularDamping,
           Vector3D Position, Quaternion Orientation)
    : RigidBody(InverseMass, LinearDamping, AngularDamping, Position, Orientation)
{
    m_EdgeHalfLength = p_EdgeHalfLength;
    updateVertexList();
}

double Cube::getEdgeHalfLength() { return m_EdgeHalfLength; }
void Cube::setEdgeHalfLength(double p_EdgeHalfLength) { m_EdgeHalfLength = p_EdgeHalfLength; }

// mets à jour la liste des sommets du cube
void Cube::updateVertexList()
{
    m_VertexList[0] = getPosition() + Vector3D(-m_EdgeHalfLength, -m_EdgeHalfLength, -m_EdgeHalfLength);	// P1
    m_VertexList[1] = getPosition() + Vector3D(-m_EdgeHalfLength, m_EdgeHalfLength, -m_EdgeHalfLength);		// P2
    m_VertexList[2] = getPosition() + Vector3D(m_EdgeHalfLength, m_EdgeHalfLength, -m_EdgeHalfLength);		// P3
    m_VertexList[3] = getPosition() + Vector3D(m_EdgeHalfLength, -m_EdgeHalfLength, -m_EdgeHalfLength);		// P4

    m_VertexList[4] = getPosition() + Vector3D(m_EdgeHalfLength, -m_EdgeHalfLength, m_EdgeHalfLength);		// P5
    m_VertexList[5] = getPosition() + Vector3D(m_EdgeHalfLength, m_EdgeHalfLength, m_EdgeHalfLength);		// P6
    m_VertexList[6] = getPosition() + Vector3D(-m_EdgeHalfLength, m_EdgeHalfLength, m_EdgeHalfLength);		// P7
    m_VertexList[7] = getPosition() + Vector3D(-m_EdgeHalfLength, -m_EdgeHalfLength, m_EdgeHalfLength);		// P8
}

void Cube::integrate(float frametime)
{ 
	RigidBody::integrate(frametime);
	updateVertexList();
}