#include "Vecteur3D.h"
#include <math.h>

//constructeur de Vecteur3D
Vecteur3D::Vecteur3D()
{
	x = 0;
	y = 0;
	z = 0;
}

//constructeur de Vecteur3D
//param : double x, double y, double z les coordonnées du vecteur
Vecteur3D::Vecteur3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

//destructeur de Vecteur3D
Vecteur3D::~Vecteur3D()
{
}

//calcul la norme du vecteur
//return double la norme du vecteur
double Vecteur3D::norme()
{
	return sqrt(prodScalaire(*this));
}

//calcul le carre de la norme du vecteur
//return double le carre de la norme du vecteur
double Vecteur3D::normecarre()
{
	return prodScalaire(*this);
}

//normalise le vecteur
void Vecteur3D::normalisation()
{
	mulScalaire(1 / norme());
}

//multiplie le vecteur par un scalaire
//param double k le scalaire
void Vecteur3D::mulScalaire(double k)
{
	x = k * x;
	y = k * y;
	z = k * z;
}

//calcul le produit composante du vecteur avec un autre vecteur
//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit composante
//return Le vecteur résultant du produit composante
Vecteur3D Vecteur3D::prodComp(Vecteur3D vec1)
{
	return Vecteur3D(x*vec1.getx(),y*vec1.gety(),z*getz());
}

//calcul le produit scalaire du vecteur avec un autre vecteur
//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit scalaire
//return Le vecteur résultant du produit scalaire
double Vecteur3D::prodScalaire(Vecteur3D vec1)
{
	return x*vec1.getx()+y*vec1.gety()+ z * vec1.getz();
}

//calcul le produit vectorielle du vecteur avec un autre vecteur
//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit vectorielle
//return Le vecteur résultant du produit vectorielle
Vecteur3D Vecteur3D::prodVectorielle(Vecteur3D vec1)
{
	double x2 = y * vec1.getz() - z * gety();
	double y2 = z * vec1.getx() - x * getz();
	double z2 = x * vec1.gety() - y * getx();
	return Vecteur3D(x2,y2,z2);
}

//accesseur de la coordonnée x
double Vecteur3D::getx()
{
	return x;
}

//accesseur de la coordonnée y
double Vecteur3D::gety()
{
	return y;
}

//accesseur de la coordonnée z
double Vecteur3D::getz()
{
	return z;
}

//surcharge l'opérateur + pour additionner deux vecteurs composante par composante
//param Vecteur3D vec Le vecteur avec lequel on souhaite additionner le vecteur
//return Le vecteur résultant de l'addition des vecteurs
Vecteur3D Vecteur3D::operator+(Vecteur3D &vec)
{
	return Vecteur3D(this->getx() + vec.getx(), this->gety() + vec.gety(), this->getz() + vec.getz());
}

//surcharge l'opérateur - pour soustraire deux vecteurs composante par composante
//param Vecteur3D vec Le vecteur avec lequel on souhaite soustraire le vecteur
//return Le vecteur résultant de la soustraction des vecteurs
Vecteur3D Vecteur3D::operator-(Vecteur3D &vec)
{
	return Vecteur3D(this->getx() - vec.getx(), this->gety() - vec.gety(), this->getz() - vec.getz());
}