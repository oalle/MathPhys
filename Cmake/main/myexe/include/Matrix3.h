#pragma once
#include "Vector3D.h"
#include "Quaternion.h"
#define SIZE 9
class Matrix3
{
private:

    float tab[SIZE];

public:

	Matrix3(float tab[SIZE]);
	~Matrix3();
    Matrix3 MultiplicationScalaire(float a);
	Vector3D MultiplicationVectorielle(Vector3D vec);
    Matrix3 ProduitMatriciel(Matrix3 B);
    Matrix3 MatriceInverse();
    Matrix3 MatriceTransposé();
    float* getTab();
    void setOrientation(Quaternion q);
    Matrix3 operator+(Matrix3& B);
	Matrix3 operator-(Matrix3& B);

};