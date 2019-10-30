#pragma once
class Matrix3
{
private:

    float tab[9];

public:

	Matrix3(float tab[9]);
    Matrix3 MultiplicationScalaire(float a);
	float* MultiplicationVectorielle(float tab[3]);
    Matrix3 ProduitMatriciel(float tab[9]);
    Matrix3 MatriceInverse();
    Matrix3 MatriceTransposé();
    float* getTab();
};