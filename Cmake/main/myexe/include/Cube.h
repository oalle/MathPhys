#pragma once
#include "RigidBody.h"

constexpr auto VERTEXNB = 8;

class Cube : public RigidBody
{
private:
    double m_EdgeHalfLength;

public:
	// liste des sommets du cube
    Vector3D m_VertexList[VERTEXNB]; 

	Cube();
    Cube(double p_EdgeHalfLength, float InverseMass, float LinearDamping, float AngularDamping,
         Vector3D Position, Quaternion Orientation);


	double getEdgeHalfLength();
	void setEdgeHalfLength(double p_EdgeHalfLength);

	void updateVertexList();

};