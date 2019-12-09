#include "CollisionData.h"

void CollisionData::addContact(Contact contact) { 
	this->contacts.push_back(contact);
    this->contactrestant = this->contacts.size();
}