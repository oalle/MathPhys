#include "Vecteur3D.h"
#include <math.h>


Vecteur3D::Vecteur3D()
{
	x = 0;
	y = 0;
	z = 0;
}

Vecteur3D::Vecteur3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


Vecteur3D::~Vecteur3D()
{
}

double Vecteur3D::norme()
{
	return sqrt(prodScalaire(*this));
}

double Vecteur3D::normecarre()
{
	return prodScalaire(*this);
}

void Vecteur3D::normalisation()
{
	mulScalaire(1 / norme());
}

void Vecteur3D::mulScalaire(double k)
{
	x = k * x;
	y = k * y;
	z = k * z;
}

Vecteur3D Vecteur3D::prodComp(Vecteur3D vec1)
{
	return Vecteur3D(x*vec1.getx(),y*vec1.gety(),z*getz());
}

double Vecteur3D::prodScalaire(Vecteur3D vec1)
{
	return x*vec1.getx()+y*vec1.gety()+ z * vec1.getz();
}

Vecteur3D Vecteur3D::prodVectorielle(Vecteur3D vec1)
{
	double x2 = y * vec1.getz() - z * gety();
	double y2 = z * vec1.getx() - x * getz();
	double z2 = x * vec1.gety() - y * getx();
	return Vecteur3D(x2,y2,z2);
}

double Vecteur3D::getx()
{
	return x;
}

double Vecteur3D::gety()
{
	return y;
}

double Vecteur3D::getz()
{
	return z;
}

Vecteur3D Vecteur3D::operator+(Vecteur3D &vec)
{
	return Vecteur3D(this->getx() + vec.getx(), this->gety() + vec.gety(), this->getz() + vec.getz());
}

Vecteur3D Vecteur3D::operator-(Vecteur3D &vec)
{
	return Vecteur3D(this->getx() - vec.getx(), this->gety() - vec.gety(), this->getz() - vec.getz());
}