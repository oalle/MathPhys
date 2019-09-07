#include "Veccteur3D.h"
#include <cmath>


Veccteur3D::Veccteur3D()
{
	x = 0;
	y = 0;
	z = 0;
}

Veccteur3D::Veccteur3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


Veccteur3D::~Veccteur3D()
{
}

double Veccteur3D::norme()
{
	return sqrt(prodScalaire(*this));
}

double Veccteur3D::normecarre()
{
	return prodScalaire(*this);
}

void Veccteur3D::normalisation()
{
	mulScalaire(1 / norme());
}

void Veccteur3D::mulScalaire(double k)
{
	x = k * x;
	y = k * y;
	z = k * z;
}

Veccteur3D Veccteur3D::prodComp(Veccteur3D vec1)
{
	return Veccteur3D(x*vec1.getx(),y*vec1.gety(),z*getz());
}

double Veccteur3D::prodScalaire(Veccteur3D vec1)
{
	return x*vec1.getx()+y*vec1.gety()+ z * vec1.getz();
}

Veccteur3D Veccteur3D::prodVectorielle(Veccteur3D vec1)
{
	double x2 = y * vec1.getz() - z * gety();
	double y2 = z * vec1.getx() - x * getz();
	double z2 = x * vec1.gety() - y * getx();
	return Veccteur3D(x2,y2,z2);
}

double Veccteur3D::getx()
{
	return x;
}

double Veccteur3D::gety()
{
	return y;
}

double Veccteur3D::getz()
{
	return z;
}

bool Veccteur3D::operator==(Veccteur3D& vec2)
{
	return (this->getx() == vec2.getx() && this->gety() == vec2.gety() && this->getz() == vec2.getz());
}

void Veccteur3D::operator=(Veccteur3D& vec2)
{
	this->x = vec2.getx();
	this->y = vec2.gety();
	this->z = vec2.getz();
}

Veccteur3D Veccteur3D::operator+(Veccteur3D& vec2)
{
	return Veccteur3D(this->getx() + vec2.getx(), this->gety() + vec2.gety(), this->getz() + vec2.getz());
}

Veccteur3D Veccteur3D::operator-(Veccteur3D &vec2)
{
	return Veccteur3D(this->getx() - vec2.getx(), this->gety() - vec2.gety(), this->getz() - vec2.getz());
}