#include "RegistreContacts.h"

// Fonction qui permet de retirer un contact du registre des contacts
// Param : p_Index : l'index dans la liste du contact que l'on souhaite supprimer
void RegistreContacts::DeleteEnregistrementContact(int p_Index)
{
    registreContacts.erase(registreContacts.begin() + p_Index);
}

