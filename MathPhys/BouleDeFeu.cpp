#include "BouleDeFeu.h"

BouleDeFeu::BouleDeFeu() {
	this->Damping = 0.1f;
	this->Masse = 2.5;

	this->Velocity = Vecteur3D(0.08, 0, 0.);
}

BouleDeFeu::~BouleDeFeu()
{

}
