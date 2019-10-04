#include "ParticleBungeeElastic.h"

ParticleBungeeElastic::ParticleBungeeElastic()
{
	this->ancragePoint = Vector3D(0.0, 0.0, 0.0);
	this->k = 0;
	this->restLength = 0;
}

ParticleBungeeElastic::ParticleBungeeElastic(Vector3D ancragePoint, float k, float restLength)
{
	this->ancragePoint = ancragePoint;
	this->k = k;
	this->restLength = restLength;
}

ParticleBungeeElastic::~ParticleBungeeElastic()
{
}

void ParticleBungeeElastic::updateForce(Particle* particule, float duration)
{
	Vector3D Force = Vector3D();
	Vector3D PosPartToAncragePoint = particule->getPosition() - this->ancragePoint;
	double distPartToAncragePoint = PosPartToAncragePoint.norme();
	PosPartToAncragePoint.normalisation();
	Force = PosPartToAncragePoint.mulScalaireResult(-k*(distPartToAncragePoint - this->restLength));
	particule->addForce(Force);
}
