#pragma once
#include <Vector3D.h>
class Matrix4
{
private:

    float tab[12];

public:
	/*constructeur de Matrix4
	param : float tab[12] le tableau de valeur pour la matrice*/
	Matrix4(float tab[12]);

    /*destructeur de Matrix4*/
    ~Matrix4();

	/*Multiplie la Matrice4 par un scalaire
	param : float a le scalaire
	return la Matrix4 resultante*/
    Matrix4 MultiplicationScalaire(float a);

	/*Multiplie la Matrice4 par un vecteur(non direction)
	param : Vector3D vec le vecteur
	return le Vector3D resultant*/
	Vector3D MultiplicationVectorielle(Vector3D vec);

	/*Multiplie la Matrice4 par une autre Matrix4
	param : Matrix4 matrix la matrice
	return la Matrix4 resultante*/
    Matrix4 ProduitMatriciel(Matrix4 matrix);

	/*Calcul la matrice inverse de la Matrix4
	return la Matrix4 resultante*/
    Matrix4 MatriceInverse();

	/*Multiplie la Matrice4 par un vecteur direction
	param : Vector3D vec le vecteur
	return le Vector3D resultant*/
    Vector3D transformationVecteurDir(Vector3D vec);

	/*renvoie le tableau de valeur de la Matrix4
	return le tableau de valeur*/
    float* getTab();
};