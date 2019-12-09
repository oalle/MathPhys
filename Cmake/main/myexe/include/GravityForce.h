#pragma once
#include "ParticleForceGenerator.h"
class GravityForce : public ParticleForceGenerator
{
private:
    Vector3D GravityVector;

public:
    // Constructeur par defaut de la classe GravityForce
    GravityForce();

    // Destructeur par defaut de la classe GravityForce
    ~GravityForce();

    // Fonction pour mettre a jour la force
    // Param : p_Particule : la particule sur la quelle on va mettre a jour la force
    virtual void updateForce(Particle* particule, float p_Duration) override;
};
