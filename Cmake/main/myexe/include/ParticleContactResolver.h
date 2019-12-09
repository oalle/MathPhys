#pragma once
#include "ParticleContact.h"
#include "RegistreContacts.h"
#include <vector>

class ParticleContactResolver
{
private:
    static int m_Iteration;
    static int m_IterationMax;

    static RegistreContacts registreContacts;

public:
    // Constructeur par defaut de la classe ParticleContactResolver
    ParticleContactResolver();

    // Constructeur a un argument de la classe ParticleContactResolver
    // Param : p_IterationMax : le nombre d'iteration maximum que l'ont effectuera
    ParticleContactResolver(int p_IterationMax);

    // Methode qui ajoute un contact au registre des contacts
    // Param : le contact a ajouter
    static void AddContact(ParticleContact* p_Contact);

    // Setter pour le nombre d'iteration max
    // Param : le nombre d'itteration max
    static void setIterationMax(int p_IterationMax) { m_IterationMax = p_IterationMax; }

    // Fonction qui resoud les contacts se trouvant dans le registre des contacts
    static void resolveContact(float p_Duration);
};
