#include "ParticleContact.h"

//Constructeur a quatre arguments de la classe ParticleContact
//Param : p_Particles[2] : Le tableau des deux particules liees au contact
//Param : p_CoefficientRestitution : Le coefficient de restitution du contact
//Param : p_ContactNormale : Le vecteur de la normale au contact
//Param : p_Penetration : Le coefficient de penetration entre less deux particules
ParticleContact::ParticleContact(Particle* p_Particles[2], double p_CoefficientRestitution, Vector3D p_ContactNormale, double p_Penetration)
{
	m_Particles[0] = p_Particles[0];
	m_Particles[1] = p_Particles[1];
	m_CoefficientRestitution = p_CoefficientRestitution;

	m_ContactNormale = p_ContactNormale;

	m_Penetration = p_Penetration;
}

//Fonction pour resoudre un contact entre deux particules
void ParticleContact::Resolve(float p_Duration)
{
	ResolveVelocity(p_Duration);
	//ResolveInterpenetration();
}

//Fonction qui calcul la velocite d'approche des deux particules
double ParticleContact::CalculVS() const
{
	Vector3D l_Temp = m_ContactNormale;
	return l_Temp.prodScalaire(m_Particles[0]->getVelocity() - m_Particles[1]->getVelocity());
}

//Fonction qui resoud la velocite que less deux particule doivent avoir pour resoudre le contact
void ParticleContact::ResolveVelocity(float p_Duration)
{
	double l_VS = CalculVS();

	double l_VSP = -m_CoefficientRestitution * l_VS;


	//Voir pour changer en vecteur au besoin
	Vector3D l_VelocityTemp1 = m_Particles[0]->getVelocity();
	Vector3D l_VelocityTemp2 = m_Particles[1]->getVelocity();

	m_Particles[0]->setVelocity(m_ContactNormale.mulScalaireResult(m_Particles[0]->getInverseMasse() * l_VSP * p_Duration));
	m_Particles[0]->setVelocity(m_ContactNormale.mulScalaireResult(m_Particles[0]->getInverseMasse() * l_VSP * p_Duration));

}

//Fonction qui resoud les cas d'interpenetration entre deux particules
void ParticleContact::ResolveInterpenetration()
{
	Vector3D l_DistanceParticle0 = m_ContactNormale.mulScalaireResult((m_Particles[1]->getInverseMasse() / (m_Particles[0]->getInverseMasse() - m_Particles[1]->getInverseMasse())) * m_Penetration);
	Vector3D l_DistanceParticle1 = m_ContactNormale.mulScalaireResult(-(m_Particles[0]->getInverseMasse() / (m_Particles[0]->getInverseMasse() - m_Particles[1]->getInverseMasse())) * m_Penetration);

	m_Particles[0]->setPosition(m_Particles[0]->getPosition() + l_DistanceParticle0);
	m_Particles[1]->setPosition(m_Particles[1]->getPosition() + l_DistanceParticle1);
	
}
