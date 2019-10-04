#pragma once
#include "ParticleForceGenerator.h"
class ParticleStiffSpring :
	public ParticleForceGenerator
{
private:
	Vector3D m_AnchoredPoint;
	int m_Damping;
	int m_ConstantSpring;

private:
	ParticleStiffSpring(Vector3D p_AnchoredPoint, int p_Damping, int p_ConstantSrping);

	void updateForce(Particle* p_Particle, float p_Duration);
};

