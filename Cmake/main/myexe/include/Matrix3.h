#pragma once
#include "Vector3D.h"
#include "Quaternion.h"
class Matrix3
{
private:

    float tab[9];

public:

	//Coonstructeur a un parametre pour la classe Matrix3
	//Param : tab[9] : un tableau avec les 9 float de la matrice
	Matrix3(float tab[9]);

	//Destructeur de la classe Matrix3
	~Matrix3();

	//Methode pour claculer la multiplication scalaire d'une matrice
	//Param : a : le scalaire par le quel on souhaite multiplier la matrice
    Matrix3 MultiplicationScalaire(float a);

	//Methode pour calculer la multiplication vectorielle d'une matrice
	//Param : vec : le vecteur par le quel on souhaite multiplier la matrice
	Vector3D MultiplicationVectorielle(Vector3D vec);

	//Methode pour calculer le produit matricielle d'une matrice
	//Param : B : la matrice par la quelle on veut multiplier la matrice
    Matrix3 ProduitMatriciel(Matrix3 B);

	//Methode pour calculer la matrice inverse
    Matrix3 MatriceInverse();

	//Methode pour calculer la transposee de la matrice
    Matrix3 MatriceTranspose();

	//Getter pour le tableau de float de la matrice
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