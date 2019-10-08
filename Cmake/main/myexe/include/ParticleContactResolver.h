#pragma once
#include "ParticleContact.h"
#include <vector>

class ParticleContactResolver
{
public:
    typedef std::vector<ParticleContact> RegistreContacts;

private:
    static RegistreContacts registreContacts;
    double m_Iteration;
    double m_IterationMax;

public:
    ParticleContactResolver();
    ParticleContactResolver(double p_IterationMax);

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
    void setIterationMax(double p_IterationMax) 
	{ 
		m_IterationMax = p_IterationMax; 
	}

	void resolveContact(float p_Duration);
};
