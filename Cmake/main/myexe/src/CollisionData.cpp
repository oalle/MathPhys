#include "CollisionData.h"

// Fonction pour ajouter un contact au vecteur de contacts
// param : contact : le contact que l'on souhaite ajouter
void CollisionData::addContact(Contact contact)
{
    this->contacts.push_back(contact);
    this->contactrestant = this->contacts.size();
}