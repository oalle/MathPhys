#pragma once
#include "ParticleForceGenerator.h"
class ParticleBuoyancy : public ParticleForceGenerator
{
private:
    double m_MaxDepth;
    double m_ObjectVolume;
    double m_WaterHeight;
    double m_Density;

public:
    // Constructeur a quatre arguments de la classe ParticleBuoyancy
    // Param : p_MaxDepth : La profondeur maximale de l'eau
    // Param : p_ObjectVolume : Le volume de l'objet se trouvant dans l'eau
    // Param : p_WaterHeight : la hauteur de l'eau
    // Param : p_Desity : la densite de l'eau
    ParticleBuoyancy(double p_MaxDepth, double p_ObjectVolume, double p_WaterHeight,
                     double p_Density);

    // Fonction pour mettre a jour la force
    // Param : p_Particle : la particule sur la quelle on veut mettre a jour la force
    void updateForce(Particle* p_Particle, float p_Duration) override;
};
