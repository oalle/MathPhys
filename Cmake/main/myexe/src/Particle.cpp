#include "Particle.h"
#include <cassert>

// Constructeur de la classe particule
Particle::Particle()
{
    Masse = 0;
    InverseMasse = 0;

    this->Position = Vector3D(0, 0, 0);
    this->Velocity = Vector3D(0, 0, 0);

    // gravity
    // this->Acceleration = Vecteur3D(0, -0.0098, 0);
}

// Destructeur de la classe particule
Particle::~Particle() {}

// Constructeur a deux parametres
// param : masse : La masse de la particule
// param : position : La position de la particule (par defaut, la particule est placee a l'origine
// du repere)
Particle::Particle(float masse, Vector3D position)
{
    this->Masse = masse;
    this->InverseMasse = 1 / masse;

    this->Position = position;
    this->Velocity = Vector3D(0, 0, 0);
}

// Constructeur de recopie de la classe particule
// param : &particule : l'adresse de la particule qu'il faut recopier
Particle::Particle(const Particle& particule)
{
    this->Acceleration = particule.Acceleration;
    this->Masse = particule.Masse;
    this->InverseMasse = particule.InverseMasse;
    this->Position = particule.Position;
    this->Velocity = particule.Velocity;
}

// Surcharge de l'operateur d'assignation pour la classe particule
// param : &particule : l'adresse de la particule a assigner
void Particle::operator=(const Particle& particule)
{
    this->Acceleration = particule.Acceleration;
    this->Masse = particule.Masse;
    this->InverseMasse = particule.InverseMasse;
    this->Position = particule.Position;
    this->Velocity = particule.Velocity;
}

// Surcharge de l'operateur de comparaison pour la classe particule
// param : &particule : l'adresse de la particule a comparer
bool Particle::operator==(const Particle& particule)
{
    return this->Acceleration == particule.Acceleration &&
           this->AccumForces == particule.AccumForces &&
           this->InverseMasse == particule.InverseMasse && this->Masse == particule.Masse &&
           this->Position == particule.Position && this->Velocity == particule.Velocity;
}

// Getteur pour l'attribut masse
// return la valeur de la masse
float Particle::getMasse() { return this->Masse; }

// Setteur pour l'attribut masse
// param : newMasse : la nouvelle valeur de la masse
void Particle::setMasse(float newMasse)
{
    this->Masse = newMasse;
    this->InverseMasse = 1 / this->Masse;
}

// Getteur pour l'attribut InverseMasse
// return la valeur de la masse inverse
float Particle::getInverseMasse() { return this->InverseMasse; }

// Setteur pour l'attribut InverseMasse
// param : newInverseMasse : la nouvelle valeur de la masse inverse
void Particle::setInverseMasse(float newInverseMasse) { this->InverseMasse = newInverseMasse; }

// Getteur pour l'attribut Position
// return le vecteur de la position
Vector3D Particle::getPosition() { return this->Position; }

// Setteur pour l'attribut Position
// param : newPosition : la nouvelle valeur de la position
void Particle::setPosition(Vector3D newPosition) { this->Position = newPosition; }

// Getteur pour l'attribut Velocity
// return le vecteur de la velocite
Vector3D Particle::getVelocity() { return this->Velocity; }

// Setteur pour l'attribut Velocity
// param : newVelociy : la nouvelle valeur pour la velocite
void Particle::setVelocity(Vector3D newVelocity) { this->Velocity = newVelocity; }

// Getteur pour l'attribut Acceleration
// return le vecteur de l'acceleration
Vector3D Particle::getAcceleration() { return this->Acceleration; }

// Setteur pour l'attribut Acceleration
// param : newAcceleration : nouvelle valeur de l'acceleration
void Particle::setAcceleration(Vector3D newAcceleration) { this->Acceleration = newAcceleration; }

// Fonction pour l'integrateur pour les particules
// param : frameTime : le temps d'une frame
void Particle::integrate(float frameTime)
{
    if (this->InverseMasse < 0) return;

    assert(frameTime > 0);

    // update position
    Vector3D Temp = this->Velocity;
    Temp.mulScalaire(frameTime);
    this->Position = this->Position + Temp;

    // calcul acceleration
    Vector3D AccumForcesTemp = this->AccumForces;
    AccumForcesTemp.mulScalaire(this->InverseMasse);
    this->Acceleration = AccumForcesTemp;
    // TODO faire 2e version des fonctions mulScal, etc (renvoie d'un Vecteur3D ou non)

    // update velocite
    Vector3D AccelerationTemp = this->Acceleration;
    AccelerationTemp.mulScalaire(frameTime);
    this->Velocity += AccelerationTemp;

    // clear AccumForces
    clearAccum();
}

// Fonction pour calculer la resultante des forces
// param : force : la force a ajouter a la resultante courante
void Particle::addForce(const Vector3D& force) { this->AccumForces += force; }

// Fonction pour nettoyer la resultante courante
void Particle::clearAccum() { this->AccumForces = Vector3D(0, 0, 0); }
