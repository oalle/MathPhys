#pragma once

#include "Particle.h"
#include "Vector3D.h"

class ParticleContact
{

private:
	Particle* m_Particles[2];
	double m_CoefficientRestitution;
	Vector3D m_ContactNormale;

public:
	ParticleContact(Particle * p_Particles[2], double p_CoefficientRestitution);
	void ResolveContact(float p_Duration);
	double CalculVS() const;
	void ResolveVelocity(float p_Duration);

};

