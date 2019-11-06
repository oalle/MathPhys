#include "Matrix4.h"

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

//en utilisans 1  en dernier �l�ment du vecteur
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

Matrix4 Matrix4::ProduitMatriciel(Matrix4 matrix)
{
    float tabRes[12] = {0};
	float* tabmatrix = matrix.getTab();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tabRes[i * 4 + j] = this->tab[i * 4] * tabmatrix[j] +
                                this->tab[i * 4  + 1] * tabmatrix[j + 4] +
                                this->tab[i * 4 + 2] * tabmatrix[j + 8];
            //on ajoute l'�l�ment de la derni�re colonne de A seulement 
			//� la derni�re colonne de B car le dernier �l�ment de la derni�re colonne de B est 1
			//sinon ils vallent 0 (derni�re ligne = 0 0 0 1)
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

//transformation d'un vecteur directeur, on ignore la partie translation
//en utilisans 0  en dernier �l�ment du vecteur
Vector3D  Matrix4::transformationVecteurDir(Vector3D vec)
{
	float tabRes[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        tabRes[i] = this->tab[i * 4] * vec.getx() + this->tab[i * 4 + 1] * vec.gety() +
                    this->tab[i * 4 + 2] * vec.getz();
    }
    return Vector3D(tabRes[0], tabRes[1], tabRes[2]);
}

float* Matrix4::getTab() 
{ 
	return this->tab; 
}

/*En ajoutant x, y, z en fin dans la derni�re colonne*/
void Matrix4::setOrientation(Quaternion q) 
{
	tab[0] = 1 - (2 * (q.getJ() * q.getJ()) +2*(q.getK()*q.getK())); 
	tab[1] = 2 * q.getI() * q.getJ() + 2 * q.getK() * q.getR();
    tab[2] = 2 * q.getI() * q.getK() - 2 * q.getJ() * q.getR();
    tab[3] = q.getI();
    tab[4] = 2 * q.getI() * q.getJ() - 2 * q.getK() * q.getR();
    tab[5] = 1 - (2 * (q.getI() * q.getI()) + 2 * (q.getK() * q.getK()));
    tab[6] = 2 * q.getJ() * q.getK() + 2 * q.getI() * q.getR();
    tab[7] = q.getJ();
    tab[8] = 2 * q.getI() * q.getK() + 2 * q.getJ() * q.getR();
    tab[9] = 2 * q.getJ() * q.getK() - 2 * q.getI() * q.getR();
    tab[10] = 1 - (2 * (q.getI() * q.getI()) + 2 * (q.getJ() * q.getJ()));
    tab[11] = q.getK();

}