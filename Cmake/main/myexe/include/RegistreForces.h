#pragma once
#include "Particle.h"
#include "ParticleForceGenerator.h"
#include <vector>

class RegistreForces
{
public:
    struct EnregistrementForce
    {
        Particle* particule;
        ParticleForceGenerator* fg;
    };
    typedef std::vector<EnregistrementForce> Registre;

private:
    Registre registreForces;

public:
    // Getter pour le registre des forces
    // return : le registre des forces
    Registre GetListEnregistrementForce() { return registreForces; }

    // Methode pour ajouter un enregistrement de force dans le registre des forces
    // param : l'enregistrement de force que l'on veut ajouter
    void AddEnregistrementForce(EnregistrementForce* p_EnregistrementForce)
    {
        registreForces.push_back(*p_EnregistrementForce);
    }

    // Fonction qui permet de retirer une force du registre des forces
    // Param : p_Index : l'index dans la liste de la force que l'on souhaite supprimer
    void DeleteEnregistrementForce(int p_Index);
};
