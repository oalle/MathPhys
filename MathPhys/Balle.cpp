#include "Balle.h"



Balle::Balle()
{
	this->Damping = 0.2f;
	this->Masse = 5;

	this->Velocity = Vecteur3D(0.03, 0, 0.);
}


Balle::~Balle()
{
}
