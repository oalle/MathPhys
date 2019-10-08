#include "RegistreForces.h"

void RegistreForces::DeleteEnregistrementForce(int p_Index)
{
	registreForces.erase(registreForces.begin() + p_Index);
}
