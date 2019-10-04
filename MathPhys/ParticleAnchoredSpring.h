#pragma once

#include "Vector3D.h"
#include "Particle.h"
#include "ParticleForceGenerator.h"
class ParticleAnchoredSpring :
	public ParticleForceGenerator
{
private:
	Vector3D m_AnchoredPoint;
	double m_WidthSpring;
	double m_ConstantSpring;

public:
	ParticleAnchoredSpring(Vector3D p_AnchoredPoint, double p_WidthSpring, double p_ConstantSrping);

	void updateForce(Particle * p_Particle, float p_Duration);

};

