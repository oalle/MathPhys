#include "ParticleBungeeElastic.h"

//Constructeur par defaut de la classe ParticleBungeeElastic
ParticleBungeeElastic::ParticleBungeeElastic()
{
	this->ancragePoint = Vector3D(0.0, 0.0, 0.0);
	this->k = 0;
	this->restLength = 0;
}

//Constructeur a trois arguments de la classe ParticleBungeeElastic
//Param : ancragePoint : La position du point d'ancrage de l'elastique
//Param : k : Une constante propre au ressort
//Param : restLength : La longueur du ressort au repos
ParticleBungeeElastic::ParticleBungeeElastic(Vector3D ancragePoint, double k, double restLength)
{
	this->ancragePoint = ancragePoint;
	this->k = k;
	this->restLength = restLength;
}

//Le destructeur par defaut de la classe ParticleBungeeElastic
ParticleBungeeElastic::~ParticleBungeeElastic()
{
}

//Fonction pour mettre a jour la force
//Param : particule : La particule sur la quelle on veut mettre a jour la force
void ParticleBungeeElastic::updateForce(Particle* p_Particule, float duration)
{
	Vector3D Force = Vector3D();
    Vector3D PosPartToAncragePoint = p_Particule->getPosition() - this->ancragePoint;
	double distPartToAncragePoint = PosPartToAncragePoint.norme();
	if (distPartToAncragePoint > this->restLength)
	{
		PosPartToAncragePoint.normalisation();
		Force = PosPartToAncragePoint.mulScalaireResult(-k * (distPartToAncragePoint - this->restLength));
		p_Particule->addForce(Force);
	}
	
}
