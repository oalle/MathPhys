#include "ParticleContact.h"

ParticleContact::ParticleContact(Particle* p_Particles[2], double p_CoefficientRestitution)
{
	m_Particles[0] = p_Particles[0];
	m_Particles[1] = p_Particles[1];
	m_CoefficientRestitution = p_CoefficientRestitution;

	Vector3D l_Temp = p_Particles[0]->getPosition() - p_Particles[1]->getPosition();
	l_Temp.normalisation();
	m_ContactNormale = l_Temp;
}

void ParticleContact::Resolve(float p_Duration)
{
	ResolveVelocity(p_Duration);
}

double ParticleContact::CalculVS() const
{
	Vector3D l_Temp = m_ContactNormale;
	return l_Temp.prodScalaire(m_Particles[0]->getVelocity() - m_Particles[1]->getVelocity());
}

void ParticleContact::ResolveVelocity(float p_Duration)
{
	double l_VS = CalculVS();

	double l_VSP = -m_CoefficientRestitution * l_VS;

	//TODO Appliquer l'impulsion


}

void ParticleContact::ResolveInterpenetration(float p_Duration)
{

}
