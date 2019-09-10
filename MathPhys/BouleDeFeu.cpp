#include "BouleDeFeu.h"

BouleDeFeu::BouleDeFeu() {
	this->Damping = 0.7f;
	this->Masse = 2.5;

	this->Velocity = Vecteur3D(0.03, 0, 0.);
}

BouleDeFeu::~BouleDeFeu()
{

}
