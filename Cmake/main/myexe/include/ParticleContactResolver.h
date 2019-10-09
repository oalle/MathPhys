#pragma once
#include "ParticleContact.h"
#include <vector>

class ParticleContactResolver
{
public:
    typedef std::vector<ParticleContact> RegistreContacts;

private:
    static RegistreContacts registreContacts;
    static int m_Iteration;
    static int m_IterationMax;

public:
    ParticleContactResolver();
    ParticleContactResolver(int p_IterationMax);

    RegistreContacts GetListContacts()
	{ 
		return registreContacts;
	}
    void static AddContact(ParticleContact p_ParticleContact)
    {
        registreContacts.push_back(p_ParticleContact);
    }
    void static DeleteContact(int p_Index)
    {
        registreContacts.erase(registreContacts.begin() + p_Index);
    }
    void static DeleteAllContacts()
    {
        registreContacts.clear();
    }
	static void setIterationMax(int p_IterationMax) 
	{ 
		m_IterationMax = p_IterationMax; 
	}

	static void resolveContact(float p_Duration);
};
