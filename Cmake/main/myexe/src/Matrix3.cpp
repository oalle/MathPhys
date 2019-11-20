#include "Matrix3.h"
constexpr auto SIZE = 9;

Matrix3::Matrix3(float tab[SIZE])
{
    for (int i = 0; i < 9; i++) { this->tab[i] = tab[i]; }
}

Matrix3::~Matrix3()
{
    
}

Matrix3 Matrix3::MultiplicationScalaire(float a)
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) { tabRes[i] = this->tab[i] * a; }
    return Matrix3(tabRes);
}

Vector3D Matrix3::MultiplicationVectorielle(Vector3D v)
{
    float tabRes[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        float temp;
        if (i == 0) { temp = v.getx(); }
        if (i == 1) { temp = v.gety(); }
        if (i == 2) { temp = v.getz(); }
        for (int j = 0; j < 3; j++) { tabRes[i] += this->tab[i * 3 + j] * temp; }
    }
    return Vector3D(tabRes[0], tabRes[1], tabRes[2]);
}

Matrix3 Matrix3::ProduitMatriciel(Matrix3 B)
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            { tabRes[i + j] += this->tab[i * 3 + k] * B.getTab()[k * 3 + j]; }
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

float* Matrix3::getTab() { return this->tab; }

Matrix3 Matrix3::operator+(Matrix3& B)
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) { tabRes[i] = this->getTab()[i] + B.getTab()[i]; }
    return Matrix3(tabRes);
}

Matrix3 Matrix3::operator-(Matrix3& B)
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) { tabRes[i] = this->getTab()[i] - B.getTab()[i]; }
    return Matrix3(tabRes);
}

bool Matrix3::operator==(const Matrix3& p_Matrix3)
{
	return this->tab == p_Matrix3.tab ;
}

void Matrix3::setOrientation(Quaternion q) 
{ 
	tab[0] = 1 - (2 * (q.getJ() * q.getJ()) +2*(q.getK()*q.getK())); 
	tab[1] = 2 * q.getI() * q.getJ() + 2 * q.getK() * q.getR();
    tab[2] = 2 * q.getI() * q.getK() - 2 * q.getJ() * q.getR();
    tab[3] = 2 * q.getI() * q.getJ() - 2 * q.getK() * q.getR();
    tab[4] = 1 - (2 * (q.getI() * q.getI()) + 2 * (q.getK() * q.getK()));
    tab[5] = 2 * q.getJ() * q.getK() + 2 * q.getI() * q.getR();
    tab[6] = 2 * q.getI() * q.getK() + 2 * q.getJ() * q.getR();
    tab[7] = 2 * q.getJ() * q.getK() - 2 * q.getI() * q.getR();
    tab[8] = 1 - (2 * (q.getI() * q.getI()) + 2 * (q.getJ() * q.getJ()));
}
