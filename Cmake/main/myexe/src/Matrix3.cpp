#include "Matrix3.h"

Matrix3::Matrix3(float tab[9])
{
    for (int i = 0; i < 9; i++) { this->tab[i] = tab[i]; }
}

Matrix3 Matrix3::MultiplicationScalaire(float a)
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) 
	{ 
		tabRes[i]=this->tab[i] *a; 
	}
    return Matrix3(tabRes);
}

float* Matrix3::MultiplicationVectorielle(float tab[3])
{
    float tabRes[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) { tabRes[i] += this->tab[i * 3 + j] * tab[i]; }
    }
    return tabRes;
}

Matrix3 Matrix3::ProduitMatriciel(float tab[9])
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++) { tabRes[i + j] += this->tab[i * 3 + k] * tab[k * 3 + j]; }
        }
    }
    return Matrix3(tabRes);
}

Matrix3 Matrix3::MatriceInverse()
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    float detM =
        this->tab[0] * this->tab[4] * this->tab[8] + this->tab[3] * this->tab[7] * this->tab[2] +
        this->tab[6] * this->tab[1] * this->tab[5] - this->tab[0] * this->tab[7] * this->tab[5] -
        this->tab[6] * this->tab[4] * this->tab[2] - this->tab[3] * this->tab[1] * this->tab[8];
    if (detM > 0.00001)
    {
        tabRes[0] = (this->tab[4] * this->tab[8] - this->tab[5] * this->tab[7]) / detM;
        tabRes[1] = (this->tab[2] * this->tab[7] - this->tab[1] * this->tab[8]) / detM;
        tabRes[2] = (this->tab[1] * this->tab[5] - this->tab[2] * this->tab[4]) / detM;
        tabRes[3] = (this->tab[5] * this->tab[6] - this->tab[3] * this->tab[8]) / detM;
        tabRes[4] = (this->tab[0] * this->tab[8] - this->tab[2] * this->tab[6]) / detM;
        tabRes[5] = (this->tab[2] * this->tab[3] - this->tab[0] * this->tab[5]) / detM;
        tabRes[6] = (this->tab[3] * this->tab[7] - this->tab[4] * this->tab[6]) / detM;
        tabRes[7] = (this->tab[1] * this->tab[6] - this->tab[0] * this->tab[7]) / detM;
        tabRes[8] = (this->tab[0] * this->tab[4] - this->tab[1] * this->tab[3]) / detM;
    }
    return Matrix3(tabRes);
}

Matrix3 Matrix3::MatriceTransposé()
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) { tabRes[i * 3 + j] = this->tab[i + j * 3]; }
    }
    return Matrix3(tabRes);
}

float* Matrix3::getTab() 
{ 
	return this->tab; 
}

Matrix3 operator+(Matrix3 M, Matrix3 B)
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) 
	{ 
		tabRes[i] = M.getTab[i] + B.getTab[i];
	}
    return Matrix3(tabRes);
}

Matrix3 operator-(Matrix3 M, Matrix3 B)
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) 
	{ 
		tabRes[i] = M.getTab[i] - B.getTab[i]; 
	}
    return Matrix3(tabRes);
}