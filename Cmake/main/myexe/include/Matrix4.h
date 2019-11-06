#pragma once
#include <Vector3D.h>
class Matrix4
{
private:

    float tab[12];

public:

	Matrix4(float tab[12]);
    ~Matrix4();
    Matrix4 MultiplicationScalaire(float a);
	Vector3D MultiplicationVectorielle(Vector3D vec);
    Matrix4 ProduitMatriciel(float tab[12]);
    Matrix4 MatriceInverse();
    float* getTab();
};