#pragma once
#include "ParticleForceGenerator.h"

class ParticleStiffSpring :
	public ParticleForceGenerator
{
private:
	Vector3D m_AnchoredPoint;
	double m_Damping;
	double m_ConstantSpring;

private:
	ParticleStiffSpring(Vector3D p_AnchoredPoint, double p_Damping, double p_ConstantSrping);

	void updateForce(Particle* p_Particle, float p_Duration);
};

