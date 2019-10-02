#pragma once

#include "Vecteur3D.h"
#include "Particule.h"
#include "ParticuleForceGenerator.h"
class ParticleAnchoredSpring :
	public ParticuleForceGenerator
{
public:
	Vecteur3D m_AnchoredPoint;
	int m_WidthSpring;
	int m_ConstantSpring;

private:
	ParticleAnchoredSpring(Vecteur3D p_AnchoredPoint, int p_WidthSpring, int p_ConstantSrping);

	void updateForce(Particule * p_Particle, float p_Duration);

};

