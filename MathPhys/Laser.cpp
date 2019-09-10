#include "Laser.h"

Laser::Laser() {
	this->Damping = 0.7f;
	this->Masse = 0;

	this->Velocity = Vecteur3D(0.03, 0, 0.);
}

Laser::~Laser() {

}
