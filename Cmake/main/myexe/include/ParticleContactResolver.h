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
    ParticleContactResolver();
    ParticleContactResolver(int p_IterationMax);

    static void AddContact(ParticleContact* p_Contact);

	static void setIterationMax(int p_IterationMax) 
	{ 
		m_IterationMax = p_IterationMax; 
	}

	static void resolveContact(float p_Duration);
};
