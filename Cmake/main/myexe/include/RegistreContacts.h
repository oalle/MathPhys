#pragma once
#include "ParticleContact.h"
#include <vector>

class RegistreContacts
{
public:
    struct EnregistrementContact
    {
        ParticleContact* contact;
    };
    typedef std::vector<EnregistrementContact> Registre;

private:
    Registre registreContacts;

public:
    // Getter pour le registre des contacts
    // return : le registre des contacts
    Registre GetListEnregistrementContact() { return registreContacts; }

    // Methode pour ajouter un enregistrement de contact au registre des contacts
    // param : l'enregistrement de contact que l'on veut ajouter
    void AddEnregistrementContact(EnregistrementContact* p_EnregistrementContact)
    {
        registreContacts.push_back(*p_EnregistrementContact);
    }

    // Fonction qui permet de retirer un contact du registre des contacts
    // Param : p_Index : l'index dans la liste du contact que l'on souhaite supprimer
    void DeleteEnregistrementContact(int p_Index);
};
