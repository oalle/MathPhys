#include "Laser.h"

//constructeur pour la classe Laser
Laser::Laser() {
	this->Damping = 1.0f;
	this->Masse = 0;

	this->Velocity = Vecteur3D(0.1, 0, 0.);
}

//Destructeur pour la classe Laser
Laser::~Laser() {

}
