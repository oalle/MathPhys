#pragma once
#include "ParticleForceGenerator.h"

class DragForce : public ParticleForceGenerator
{
private:
    float coeffDrag1;
    float coeffDrag2;

public:
    // Constructeur par defaut de la classe DragForce
    DragForce();

    // Constructeur a deux arguments de la classe DragForce
    // Param : p_CoeffDrag1 : Le premier coefficient de drag
    // Param : p_CoeffDrag2 : Le deuxieme coefficient de drag
    DragForce(float coeffDrag1, float coeffDrag2);

    // Destructeur par defaut de la classe DragForce
    ~DragForce();

    // Fonction pour mettre a jour les forces
    // Param : p_Particule : La particule sur la quelle on veut mettre a jour la force
    // Param : p_Duration
    void updateForce(Particle* particule, float p_Duration) override;
};
