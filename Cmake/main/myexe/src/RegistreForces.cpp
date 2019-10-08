#include "RegistreForces.h"

//Fonction qui permet de retirer une force du registre des forces
//Param : p_Index : l'index dans la liste de la force que l'on souhaite supprimer
void RegistreForces::DeleteEnregistrementForce(int p_Index)
{
	registreForces.erase(registreForces.begin() + p_Index);
}
