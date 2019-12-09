#pragma once
#include "Vector3D.h"
#include <cmath>

class Particle
{
public:
    // Constructeur de la classe particule
    Particle();
    // Destructeur de la classe particule
    virtual ~Particle();

    // Constructeur a deux parametres
    // param : masse : La masse de la particule
    // param : position : La position de la particule (par defaut, la particule est placee a
    // l'origine du repere)
    Particle(float masse, Vector3D position = Vector3D(0, 0, 0));

    // Constructeur de recopie de la classe particule
    // param : &particule : l'adresse de la particule qu'il faut recopier
    Particle(const Particle& particule);

    // Surcharge de l'operateur de comparaison pour la classe particule
    // param : &particule : l'adresse de la particule a comparer
    void operator=(const Particle& particule);

    // Surcharge de l'operateur de comparaison pour la classe particule
    // param : &particule : l'adresse de la particule a comparer
    bool operator==(const Particle& particule);

    // Getteur pour l'attribut masse
    // return la valeur de la masse
    float getMasse();
    // Setteur pour l'attribut masse
    // param : newMasse : la nouvelle valeur de la masse
    void setMasse(float newMasse);

    // Getteur pour l'attribut InverseMasse
    // return la valeur de la masse inverse
    float getInverseMasse();
    // Setteur pour l'attribut InverseMasse
    // param : newInverseMasse : la nouvelle valeur de la masse inverse
    void setInverseMasse(float newInverseMasse);

    // Getteur pour l'attribut Position
    // return le vecteur de la position
    Vector3D getPosition();
    // Setteur pour l'attribut Position
    // param : newPosition : la nouvelle valeur de la position
    void setPosition(Vector3D newPosition);

    // Getteur pour l'attribut Velocity
    // return le vecteur de la velocite
    Vector3D getVelocity();
    // Setteur pour l'attribut Velocity
    // param : newVelociy : la nouvelle valeur pour la velocite
    void setVelocity(Vector3D newVelocity);

    // Getteur pour l'attribut Acceleration
    // return le vecteur de l'acceleration
    Vector3D getAcceleration();
    // Setteur pour l'attribut Acceleration
    // param : newAcceleration : nouvelle valeur de l'acceleration
    void setAcceleration(Vector3D newAcceleration);

    // Fonction pour l'integrateur pour les particules
    // param : frameTime : le temps d'une frame
    void integrate(float frameTime);

    // Fonction pour calculer la resultante des forces
    // param : force : la force a ajouter a la resultante courante
    void addForce(const Vector3D& force);

    // Fonction pour nettoyer la resultante courante
    void clearAccum();

protected:
    float Masse;
    float InverseMasse;

    Vector3D Position;
    Vector3D Velocity;
    Vector3D Acceleration;

    Vector3D AccumForces;
};
