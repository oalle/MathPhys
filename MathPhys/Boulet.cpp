#include "Boulet.h"

Boulet::Boulet() {
	this->Damping = 0.7f;
	this->Masse = 14;

	this->Velocity = Vecteur3D(0.03, 0.01, 0.);
}

Boulet::~Boulet() {

}
