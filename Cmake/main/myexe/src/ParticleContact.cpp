#include "ParticleContact.h"

ParticleContact::ParticleContact(Particle* p_Particles[2], double p_CoefficientRestitution, Vector3D p_ContactNormale, double p_Penetration)
{
	m_Particles[0] = p_Particles[0];
	m_Particles[1] = p_Particles[1];
	m_CoefficientRestitution = p_CoefficientRestitution;

	m_ContactNormale = p_ContactNormale;

	m_Penetration = p_Penetration;
	/*Vector3D l_Temp = p_Particles[0]->getPosition() - p_Particles[1]->getPosition();
	l_Temp.normalisation();
	m_ContactNormale = l_Temp;*/
}

void ParticleContact::Resolve(float p_Duration)
{
	ResolveVelocity(p_Duration);
	ResolveInterpenetration();
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


	//Voir pour changer en vecteur au besoin
	Vector3D l_VelocityTemp1 = m_Particles[0]->getVelocity();
	Vector3D l_VelocityTemp2 = m_Particles[1]->getVelocity();

	m_Particles[0]->setVelocity(l_VelocityTemp1 + m_ContactNormale.mulScalaireResult(m_Particles[0]->getInverseMasse() * l_VSP * p_Duration));


}

void ParticleContact::ResolveInterpenetration()
{
	Vector3D l_DistanceParticle0 = m_ContactNormale.mulScalaireResult((m_Particles[1]->getInverseMasse() / (m_Particles[0]->getInverseMasse() - m_Particles[1]->getInverseMasse())) * m_Penetration);
	Vector3D l_DistanceParticle1 = m_ContactNormale.mulScalaireResult(-(m_Particles[0]->getInverseMasse() / (m_Particles[0]->getInverseMasse() - m_Particles[1]->getInverseMasse())) * m_Penetration);

	m_Particles[0]->setPosition(m_Particles[0]->getPosition() + l_DistanceParticle0);
	m_Particles[1]->setPosition(m_Particles[1]->getPosition() + l_DistanceParticle1);
	
}
