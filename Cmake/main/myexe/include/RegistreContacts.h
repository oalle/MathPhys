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
    Registre GetListEnregistrementContact() { return registreContacts; }
    void AddEnregistrementContact(EnregistrementContact* p_EnregistrementContact)
    {
        registreContacts.push_back(*p_EnregistrementContact);
    }
    void DeleteEnregistrementContact(int p_Index);
};
