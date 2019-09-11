#pragma once
#include <cmath>
#include "Vecteur3D.h"

class Particule
{
public:
	//Constructeur de la classe particule
	Particule();
	//Destructeur de la classe particule
	virtual ~Particule();

	//Constructeur de recopie de la classe particule
	//param : &particule : l'adresse de la particule qu'il faut recopier
	Particule(Particule& particule);

	//Surcharge de l'operateur d'assignation pour la classe particule
	//param : &particule : l'adresse de la particule a assigner
	void operator=(Particule& particule);

	//Getteur pour l'attribut masse 
	//return la valeur de la masse
	float getMasse();
	//Setteur pour l'attribut masse
	//param : newMasse : la nouvelle valeur de la masse
	void setMasse(float newMasse);

	//Getteur pour l'attribut InverseMasse
	//return la valeur de la masse inverse
	float getInverseMasse();
	//Setteur pour l'attribut InverseMasse
	//param : newInverseMasse : la nouvelle valeur de la masse inverse
	void setInverseMasse(float newInverseMasse);

	//Getteur pour l'attribut Damping
	//return la valeur du damping
	float getDamping();
	//Setteur pour l'attribut Damping
	//param : newDamping : la nouvelle valeur du damping
	void setDamping(float newDamping);

	//Getteur pour l'attribut Position
	//return la valeur de la position
	Vecteur3D getPosition();
	//Setteur pour l'attribut Position
	//param : newPosition : la nouvelle valeur de la position
	void setPosition(Vecteur3D newPosition);

	//Getteur pour l'attribut Velocity
	//return la valeur de la velocite
	Vecteur3D getVelocity();
	//Setteur pour l'attribut Velocity
	//param : newVelociy : la nouvelle valeur pour la velocite
	void setVelocity(Vecteur3D newVelocity);

	//Getteur pour l'attribut Acceleration
	//return la valeur de l'acceleration
	Vecteur3D getAcceleration();
	//Setteur pour l'attribut Acceleration
	//param : newAcceleration : nouvelle valeur de l'acceleration
	void setAcceleration(Vecteur3D newAcceleration);

	//Fonction pour l'integrateur pour les particules
	//param : frameTime : le temps d'une frame
	void integrer(float frameTime);

protected:
	float Masse;
	float InverseMasse;
	float Damping;

	Vecteur3D Position;
	Vecteur3D Velocity;
	Vecteur3D Acceleration;

};

