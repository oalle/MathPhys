#include "Matrix3.h"
#include <iostream>
constexpr auto SIZE = 9;

// Coonstructeur par defaut pour la classe Matrix3
Matrix3::Matrix3()
{
    for (int i = 0; i < 9; i++) { this->tab[i] = 0; }
}

// Coonstructeur a un parametre pour la classe Matrix3
// Param : tab[9] : un tableau avec les 9 float de la matrice
Matrix3::Matrix3(float tab[SIZE])
{
    for (int i = 0; i < 9; i++) { this->tab[i] = tab[i]; }
}

// Destructeur de la classe Matrix3
Matrix3::~Matrix3() {}

// Methode pour claculer la multiplication scalaire d'une matrice
// Param : a : le scalaire par le quel on souhaite multiplier la matrice
// Return : la nouvelle matrice
Matrix3 Matrix3::MultiplicationScalaire(float a)
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) { tabRes[i] = this->tab[i] * a; }
    return Matrix3(tabRes);
}

// Methode pour calculer la multiplication vectorielle d'une matrice
// Param : vec : le vecteur par le quel on souhaite multiplier la matrice
// Return : le nouveau vecteur
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

// Methode pour calculer le produit matricielle d'une matrice
// Param : B : la matrice par la quelle on veut multiplier la matrice
// Return : la nouvelle matrice
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

// Methode pour calculer la matrice inverse
// Return : la nouvelle matrice
Matrix3 Matrix3::MatriceInverse()
{
    Matrix3 relut;
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    float detM =
        this->tab[0] * this->tab[4] * this->tab[8] + this->tab[3] * this->tab[7] * this->tab[2] +
        this->tab[6] * this->tab[1] * this->tab[5] - this->tab[0] * this->tab[7] * this->tab[5] -
        this->tab[6] * this->tab[4] * this->tab[2] - this->tab[3] * this->tab[1] * this->tab[8];
    if (detM != 0.0)
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
        relut = Matrix3(tabRes);
    }
    else
    {
		relut = Matrix3(tab);
    }
    
    return relut;
}

// Methode pour calculer la transposee de la matrice
// Return : la nouvelle matrice
Matrix3 Matrix3::MatriceTranspose()
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) { tabRes[i * 3 + j] = this->tab[i + j * 3]; }
    }
    return Matrix3(tabRes);
}

// Getter pour le tableau de float de la matrice
// Return : le tableau de float de la matrice
float* Matrix3::getTab() { return this->tab; }

// Surcharge de l'operateur +
Matrix3 Matrix3::operator+(Matrix3& B)
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) { tabRes[i] = this->getTab()[i] + B.getTab()[i]; }
    return Matrix3(tabRes);
}

// Surcharge de l'operateur -
Matrix3 Matrix3::operator-(Matrix3& B)
{
    float tabRes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) { tabRes[i] = this->getTab()[i] - B.getTab()[i]; }
    return Matrix3(tabRes);
}

bool Matrix3::operator==(const Matrix3& p_Matrix3) { return this->tab == p_Matrix3.tab; }

// Methode pour transformer un quaternion en Matrix3
// Param Quaternion q le quaternion
void Matrix3::setOrientation(Quaternion q)
{
    tab[0] = 1 - (2 * (q.getJ() * q.getJ()) + 2 * (q.getK() * q.getK()));
    tab[1] = 2 * q.getI() * q.getJ() + 2 * q.getK() * q.getR();
    tab[2] = 2 * q.getI() * q.getK() - 2 * q.getJ() * q.getR();
    tab[3] = 2 * q.getI() * q.getJ() - 2 * q.getK() * q.getR();
    tab[4] = 1 - (2 * (q.getI() * q.getI()) + 2 * (q.getK() * q.getK()));
    tab[5] = 2 * q.getJ() * q.getK() + 2 * q.getI() * q.getR();
    tab[6] = 2 * q.getI() * q.getK() + 2 * q.getJ() * q.getR();
    tab[7] = 2 * q.getJ() * q.getK() - 2 * q.getI() * q.getR();
    tab[8] = 1 - (2 * (q.getI() * q.getI()) + 2 * (q.getJ() * q.getJ()));
}

// Methode pour passer du repere de l'objet vers le repere du monde
// Param : p_Vector : le vecteur dont on doit changer les coordonnees
// Return : le vecteur avec les nouvelles coordonnees
Vector3D Matrix3::LocalToWorld(Vector3D p_Vector)
{
    return this->MultiplicationVectorielle(p_Vector);
}

// Methode pour passer du repere du monde au repere de l'objet
// Param : p_Vector : le vecteur dont on doit changer les coordonnees
// Return : le vecteur avec les nouvelles coordonnees
Vector3D Matrix3::WorldToLocal(Vector3D p_Vector)
{
    Matrix3 l_Temp = this->MatriceInverse();
    return l_Temp.MultiplicationVectorielle(p_Vector);
}
