#pragma once

#include "ParticleForceGenerator.h"
class ParticleAnchoredSpring :
	public ParticleForceGenerator
{
private:
	Vecteur3D m_AnchoredPoint;
	int m_WidthSpring;
	int m_ConstantSpring;

public:
	ParticleAnchoredSpring(Vecteur3D p_AnchoredPoint, int p_WidthSpring, int p_ConstantSrping);

	void updateForce(Particle * p_Particle, float p_Duration);

};

