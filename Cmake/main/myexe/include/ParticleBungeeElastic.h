#pragma once
#include "Particle.h"
#include "ParticleForceGenerator.h"
#include "Vector3D.h"

class ParticleBungeeElastic : public ParticleForceGenerator
{
private:
    Vector3D ancragePoint;
    double k;
    double restLength;

public:
    // Constructeur par defaut de la classe ParticleBungeeElastic
    ParticleBungeeElastic();

    // Constructeur a trois arguments de la classe ParticleBungeeElastic
    // Param : ancragePoint : La position du point d'ancrage de l'elastique
    // Param : k : Une constante propre au ressort
    // Param : restLength : La longueur du ressort au repos
    ParticleBungeeElastic(Vector3D ancragePoint, double k, double restLength);

    // Le destructeur par defaut de la classe ParticleBungeeElastic
    ~ParticleBungeeElastic();

    // Fonction pour mettre a jour la force
    // Param : particule : La particule sur la quelle on veut mettre a jour la force
    void updateForce(Particle* particule, float duration) override;
};
