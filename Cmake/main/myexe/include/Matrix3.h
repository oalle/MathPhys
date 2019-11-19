#pragma once
#include "Vector3D.h"
#include "Quaternion.h"
class Matrix3
{
private:

    float tab[9];

public:

	Matrix3(float tab[9]);
	~Matrix3();
    Matrix3 MultiplicationScalaire(float a);
	Vector3D MultiplicationVectorielle(Vector3D vec);
    Matrix3 ProduitMatriciel(Matrix3 B);
    Matrix3 MatriceInverse();
    Matrix3 MatriceTransposé();
	float* getTab();
    void setOrientation(Quaternion q);
	//Surcharge de l'operateur +
    Matrix3 operator+(Matrix3& B);
	//Surcharge de l'operateur -
	Matrix3 operator-(Matrix3& B);

	//Methode pour passer du repere de l'objet vers le repere du monde
	//Paraam : p_Vector : le vecteur dont on doit changer les coordonnees
	//Return : le vecteur avec les nouvelles coordonnees
	Vector3D LocalToWorld(Vector3D p_Vector);
	//Methode pour passer du repere du monde au repere de l'objet
	//Param : p_Vector : le vecteur dont on doit changer les coordonnees
	//Return : le vecteur avec les nouvelles coordonnees
	Vector3D WorldToLocal(Vector3D p_Vector);

};