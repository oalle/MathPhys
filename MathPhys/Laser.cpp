#include "Laser.h"

Laser::Laser() {
	this->Damping = 1.0f;
	this->Masse = 0;

	this->Velocity = Vecteur3D(0.1, 0, 0.);
}

Laser::~Laser() {

}
