#pragma once
#include "Matrix4.h"

class Matrix4;
class Vector3D
{
public:
	//constructeur de Vecteur3D
	Vector3D();

	//constructeur de Vecteur3D
	//param : double x, double y, double z les coordonnées du vecteur
	Vector3D(double x, double y, double z);

	//destructeur de Vecteur3D
	~Vector3D();

	//calcul la norme du vecteur
	//return double la norme du vecteur
	double norme();

	//calcul le carre de la norme du vecteur
	//return double le carre de la norme du vecteur
	double normecarre();

	//normalise le vecteur
	void normalisation();

	//multiplie le vecteur par un scalaire
	//param double k le scalaire
	void mulScalaire(double k);

	//donne le resultat de la multiplication entre le vecteur et le scalaire
	//param double k le scalaire
	//return Vector3D le vecteur resultant
	Vector3D mulScalaireResult(double k);

	//calcul le produit composante du vecteur avec un autre vecteur
	//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit composante
	//return Le vecteur résultant du produit composante
	Vector3D prodComp(Vector3D vec1);

	//calcul le produit scalaire du vecteur avec un autre vecteur
	//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit scalaire
	//return Le vecteur résultant du produit scalaire
	double prodScalaire(Vector3D vec1);

	//calcul le produit vectorielle du vecteur avec un autre vecteur
	//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit vectorielle
	//return Le vecteur résultant du produit vectorielle
	Vector3D prodVectorielle(Vector3D vec1);

	//accesseur de la coordonnée x
	double getx();

	//accesseur de la coordonnée y
	double gety();

	//accesseur de la coordonnée z
	double getz();

	//surcharge l'opérateur + pour additionner deux vecteurs composante par composante
	//param Vecteur3D vec Le vecteur avec lequel on souhaite additionner le vecteur
	//return Le vecteur résultant de l'addition des vecteurs
	Vector3D operator+(const Vector3D& vec);

	//surcharge l'opérateur - pour soustraire deux vecteurs composante par composante
	//param Vecteur3D vec Le vecteur avec lequel on souhaite soustraire le vecteur
	//return Le vecteur résultant de la soustraction des vecteurs
	Vector3D operator-(const Vector3D& vec);

	//surcharge l'opérateur += pour additionner deux vecteurs composante par composante
	//param Vecteur3D vec Le vecteur avec lequel on souhaite additionner le vecteur
	//return Le vecteur résultant de l'addition des vecteurs
	void operator+=(const Vector3D& vec);

	//Surcharge de l'operateur de comparaison pour la classe Vecteur3D
	//param : &vec : l'adresse du Vecteur3D a comparer
	bool operator==(const Vector3D& vec);

	//Surcharge de l'operateur d'assignation pour la classe Vecteur3D
	//param : &vec : l'adresse du Vecteur3D a assigner
	void operator=(const Vector3D& vec);

private:
	double x, y, z;

};

