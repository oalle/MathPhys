#include "Vector3D.h"
#include <math.h>

//constructeur de Vecteur3D
Vector3D::Vector3D()
{
	x = 0;
	y = 0;
	z = 0;
}

//constructeur de Vecteur3D
//param : double x, double y, double z les coordonnées du vecteur
Vector3D::Vector3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

//destructeur de Vecteur3D
Vector3D::~Vector3D()
{
}

//calcul la norme du vecteur
//return double la norme du vecteur
double Vector3D::norme()
{
	return sqrt(prodScalaire(*this));
}

//calcul le carre de la norme du vecteur
//return double le carre de la norme du vecteur
double Vector3D::normecarre()
{
	return prodScalaire(*this);
}

//normalise le vecteur
void Vector3D::normalisation()
{
	mulScalaire(1 / norme());
}

//multiplie le vecteur par un scalaire
//param double k le scalaire
void Vector3D::mulScalaire(double k)
{
	x = k * x;
	y = k * y;
	z = k * z;
}

Vector3D Vector3D::mulScalaireResult(double k)
{
	Vector3D result = Vector3D(k * x, k * y, k * z);
	return result;
}

//calcul le produit composante du vecteur avec un autre vecteur
//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit composante
//return Le vecteur résultant du produit composante
Vector3D Vector3D::prodComp(Vector3D vec1)
{
	return Vector3D(x*vec1.getx(),y*vec1.gety(),z*getz());
}

//calcul le produit scalaire du vecteur avec un autre vecteur
//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit scalaire
//return Le vecteur résultant du produit scalaire
double Vector3D::prodScalaire(Vector3D vec1)
{
	return x*vec1.getx()+y*vec1.gety()+ z * vec1.getz();
}

//calcul le produit vectorielle du vecteur avec un autre vecteur
//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit vectorielle
//return Le vecteur résultant du produit vectorielle
Vector3D Vector3D::prodVectorielle(Vector3D vec1)
{
	double x2 = y * vec1.getz() - z * gety();
	double y2 = z * vec1.getx() - x * getz();
	double z2 = x * vec1.gety() - y * getx();
	return Vector3D(x2,y2,z2);
}

//accesseur de la coordonnée x
double Vector3D::getx()
{
	return x;
}

//accesseur de la coordonnée y
double Vector3D::gety()
{
	return y;
}

//accesseur de la coordonnée z
double Vector3D::getz()
{
	return z;
}

//surcharge l'opérateur + pour additionner deux vecteurs composante par composante
//param Vecteur3D vec Le vecteur avec lequel on souhaite additionner le vecteur
//return Le vecteur résultant de l'addition des vecteurs
Vector3D Vector3D::operator+(const Vector3D &vec)
{
	return Vector3D(this->getx() + vec.x, this->gety() + vec.y, this->getz() + vec.z);
}

//surcharge l'opérateur - pour soustraire deux vecteurs composante par composante
//param Vecteur3D vec Le vecteur avec lequel on souhaite soustraire le vecteur
//return Le vecteur résultant de la soustraction des vecteurs
Vector3D Vector3D::operator-(const Vector3D &vec)
{
	return Vector3D(this->getx() - vec.x, this->gety() - vec.y, this->getz() - vec.z);
}

//surcharge l'opérateur += pour additionner deux vecteurs composante par composante
//param Vecteur3D vec Le vecteur avec lequel on souhaite additionner le vecteur
//return Le vecteur résultant de l'addition des vecteurs
void Vector3D::operator+=(const Vector3D& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
}

//Surcharge de l'operateur de comparaison pour la classe vecteur3D
//param : &vec : l'adresse du vecteur3D a comparer
bool Vector3D::operator==(const Vector3D& vec)
{
	return this->getx() == vec.x && this->gety() == vec.y && this->getz() == vec.z;
}
//Surcharge de l'operateur d'assignation pour la classe Vecteur3D
//param : &vec : l'adresse du Vecteur3D a assigner
void Vector3D::operator=(const Vector3D& vec)
{
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;
}

//Methode pour changer la base d'un vecteur
Vector3D Vector3D::ChangingBase(Matrix4 p_Matrix)
{
	float l_Tab[12] = { 1,0,0,x,0,1,0,y,0,0,1,z};
	Matrix4 l_TempMatrix = Matrix4(l_Tab);
	Matrix4 l_FirstMul = p_Matrix.ProduitMatriciel(l_TempMatrix);
	Matrix4 l_InverseMatrix = p_Matrix.MatriceInverse();
	Matrix4 l_SecondMul = l_FirstMul.ProduitMatriciel(l_InverseMatrix);
    float * l_TabResult = l_SecondMul.getTab();
    return Vector3D(l_TabResult[3], l_TabResult[7], l_TabResult[11]);
}	
