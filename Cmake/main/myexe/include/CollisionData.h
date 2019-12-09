#pragma once
#include "RigidBody.h"
#include "Vector3D.h"
#include "Contact.h"
#include <vector>

using namespace std;
class CollisionData
{
private:
    
        vector<Contact> contacts;
		int contactrestant;
    

public:
                CollisionData()
                {
                    contacts = vector<Contact>();
                    contactrestant = 0;
                };
                void addContact(Contact contact);
                vector<Contact> getContacts() { return contacts; };
                int getContactRestant() { return contactrestant; };
};