#include "Balle.h"


//Constructeur pour la classe Balle
Balle::Balle()
{
	this->Damping = 0.2f;
	this->Masse = 5;

	this->Velocity = Vecteur3D(0.03, 0, 0.);
}

//Destructeur pour la classe Balle
Balle::~Balle()
{
}
