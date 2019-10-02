#pragma once

#include "Vector3D.h"
#include "Particle.h"
#include "ParticleForceGenerator.h"
class ParticleAnchoredSpring :
	public ParticleForceGenerator
{
public:
	Vector3D m_AnchoredPoint;
	int m_WidthSpring;
	int m_ConstantSpring;

private:
	ParticleAnchoredSpring(Vector3D p_AnchoredPoint, int p_WidthSpring, int p_ConstantSrping);

	void updateForce(Particle * p_Particle, float p_Duration);

};

