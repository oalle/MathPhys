#pragma once
#include "ParticleContact.h"
#include <vector>

class ParticleContactResolver
{
public:
    typedef std::vector<ParticleContact> RegistreContacts;

private:
    static RegistreContacts registreContacts;
    int m_Iteration;
    int m_IterationMax;

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
    void DeleteContact(int p_Index)
	{
		registreContacts.erase(registreContacts.begin() + p_Index); 
	}
    void setIterationMax(int p_IterationMax) 
	{ 
		m_IterationMax = p_IterationMax; 
	}

	void resolveContact(float p_Duration);
};
