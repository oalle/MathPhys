#pragma once

#include "Particle.h"
#include "Vector3D.h"

class ParticleContact
{

private:
	Particle* m_Particles[2];
	double m_CollisionRestitution;
	Vector3D m_ContactNormale;

public:
	ParticleContact(Particle * p_Particles[2], double p_CollisionRestitution, Vector3D p_ContactNormale);
	void ResolveContact(float p_Duration);
	double CalculCollisionRestitution() const;
	void ResolveVelocity(float p_Duration);

};

