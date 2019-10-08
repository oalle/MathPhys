#pragma once

#include "Particle.h"
#include "Vector3D.h"

class ParticleContact
{

private:
	Particle* m_Particles[2];
	double m_CoefficientRestitution;
	Vector3D m_ContactNormale;
	double m_Penetration;

public:
	ParticleContact(Particle * p_Particles[2], double p_CoefficientRestitution, Vector3D p_ContactNormale, double m_Penetration);
	void Resolve(float p_Duration);
	double CalculVS() const;
	void ResolveVelocity(float p_Duration);
	void ResolveInterpenetration();
};

