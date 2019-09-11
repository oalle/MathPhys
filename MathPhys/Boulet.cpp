#include "Boulet.h"

//Constructeur pour la classe Boulet
Boulet::Boulet() {
	this->Damping = 0.01f;
	this->Masse = 14;

	this->Velocity = Vecteur3D(0.01, 0, 0.);
}

//Destructeur de la classe Boulet
Boulet::~Boulet() {

}
