#include "..\include\Matrix4.h"

Matrix4::Matrix4(float tab[12])
{
    for (int i = 0; i < 12; i++) { this->tab[i] = tab[i]; }
}

Matrix4::~Matrix4() {}

Matrix4 Matrix4::MultiplicationScalaire(float a)
{
    float tabRes[12] = {0};
    for (int i = 0; i < 12; i++) { tabRes[i] = this->tab[i] * a; }
    return Matrix4(tabRes);
}

Vector3D Matrix4::MultiplicationVectorielle(Vector3D vec)
{
    float tabRes[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        tabRes[i] = this->tab[i * 4] * vec.getx() + this->tab[i * 4 + 1] * vec.gety() +
                    this->tab[i * 4 + 2] * vec.getz() + this->tab[i * 4 + 3];
    }
    return Vector3D(tabRes[0], tabRes[1], tabRes[2]);
}

Matrix4 Matrix4::ProduitMatriciel(float tab[12])
{
    float tabRes[12] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 3; k++) { tabRes[i + j] += this->tab[i * 3 + k] * tab[k * 3 + j]; }
            tabRes[i * 4 + j] = this->tab[i * 4] * this->tab[j] +
                                this->tab[i * 4  + 1] * this->tab[j + 4] +
                                this->tab[i * 4 + 2] * this->tab[j + 8];
            //on ajoute l'élément de la dernière colonne de A seulement 
			//à la dernière colonne de B car le dernier élément de la dernière colonne de B est 1
			//sinon ils fallent 0 (dernière ligne = 0 0 0 1)
			if (j == 3) { 
				tabRes[i * 4 + j] += this->tab[i * 4 + 3];
			}
        }
    }
    return Matrix4(tabRes);
}

Matrix4 Matrix4::MatriceInverse()
{
	float tabRes[12] = {0};
    float det =
        this->tab[2] * this->tab[5] * this->tab[8] + this->tab[4] * this->tab[9] * this->tab[2] +
        this->tab[8] * this->tab[1] * this->tab[6] - this->tab[0] * this->tab[9] * this->tab[6] -
        this->tab[4] * this->tab[1] * this->tab[10] - this->tab[0] * this->tab[5] * this->tab[10];
        tabRes[0] = -this->tab[9] * this->tab[6] + this->tab[5] * this->tab[10];
    tabRes[1] = this->tab[9] * this->tab[2] - this->tab[1] * this->tab[10];
        tabRes[2] = -this->tab[5] * this->tab[2] + this->tab[1] * this->tab[6];
    tabRes[3] =
        this->tab[9] * this->tab[6] * this->tab[3] - this->tab[5] * this->tab[10] * this->tab[3] -
        this->tab[9] * this->tab[2] * this->tab[7] + this->tab[1] * this->tab[10] * this->tab[7] +
        this->tab[5] * this->tab[2] * this->tab[11] - this->tab[1] * this->tab[6] * this->tab[11];
        tabRes[4] = this->tab[8] * this->tab[6] - this->tab[4] * this->tab[10];
    tabRes[5] = -this->tab[8] * this->tab[2] + this->tab[0] * this->tab[10];
        tabRes[6] = this->tab[4] * this->tab[2] - this->tab[0] * this->tab[6];
    tabRes[7] =
        -this->tab[8] * this->tab[6] * this->tab[3] + this->tab[4] * this->tab[10] * this->tab[3] +
        this->tab[8] * this->tab[2] * this->tab[7] - this->tab[0] * this->tab[10] * this->tab[7] -
        this->tab[4] * this->tab[2] * this->tab[11] + this->tab[0] * this->tab[6] * this->tab[11];
        tabRes[8] = -this->tab[8] * this->tab[5] + this->tab[4] * this->tab[9];
    tabRes[9] = this->tab[8] * this->tab[1] - this->tab[0] * this->tab[9];
        tabRes[10] = -this->tab[4] * this->tab[1] + this->tab[0] * this->tab[5];
    tabRes[11] =
        this->tab[8] * this->tab[5] * this->tab[3] - this->tab[4] * this->tab[9] * this->tab[3] -
        this->tab[8] * this->tab[1] * this->tab[7] + this->tab[0] * this->tab[9] * this->tab[7] +
        this->tab[4] * this->tab[1] * this->tab[11] - this->tab[0] * this->tab[5] * this->tab[11];
    return Matrix4(tabRes).MultiplicationScalaire(1/det);
}

float* Matrix4::getTab() 
{ 
	return this->tab; 
}