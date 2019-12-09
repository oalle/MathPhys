#pragma once
#include "Contact.h"
#include "RigidBody.h"
#include "Vector3D.h"
#include <vector>

// using namespace std;
class CollisionData
{
private:
    vector<Contact> contacts;
    int contactrestant;

public:
    // Constructeur par defaut de la classe CollisionData
    CollisionData()
    {
        contacts = vector<Contact>();
        contactrestant = 0;
    };

    // Fonction pour ajouter un contact au vecteur de contacts
    // param : contact : le contact que l'on souhaite ajouter
    void addContact(Contact contact);

    // Getter pour l'attribut contacts de la classe CollisionData
    // return : la valeur de l'attribut contacts
    vector<Contact> getContacts() { return contacts; };

    // Getter pour l'attribut contactrestant de la classe CollisionData
    // return : le nombre de contacts restants
    int getContactRestant() { return contactrestant; };
};