#pragma once
class Vecteur3D
{
public:
	//constructeur de Vecteur3D
	Vecteur3D();
	//constructeur de Vecteur3D
	//param : double x, double y, double z les coordonnées du vecteur
	Vecteur3D(double x, double y, double z);
	//destructeur de Vecteur3D
	~Vecteur3D();
	//calcul la norme du vecteur
	//return double la norme du vecteur
	double norme();
	//calcul le carre de la norme du vecteur
	//return double le carre de la norme du vecteur
	double normecarre();
	//normalise le vecteur
	void normalisation();
	//multiplie le vecteur par un scalaire
	//param double k le scalaire
	void mulScalaire(double k);
	//calcul le produit composante du vecteur avec un autre vecteur
	//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit composante
	//return Le vecteur résultant du produit composante
	Vecteur3D prodComp(Vecteur3D vec1);
	//calcul le produit scalaire du vecteur avec un autre vecteur
	//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit scalaire
	//return Le vecteur résultant du produit scalaire
	double prodScalaire(Vecteur3D vec1);
	//calcul le produit vectorielle du vecteur avec un autre vecteur
	//param Vecteur3D vec1 Le vecteur avec lequel on souhaite calculer le produit vectorielle
	//return Le vecteur résultant du produit vectorielle
	Vecteur3D prodVectorielle(Vecteur3D vec1);
	//accesseur de la coordonnée x
	double getx();
	//accesseur de la coordonnée y
	double gety();
	//accesseur de la coordonnée z
	double getz();
	//surcharge l'opérateur + pour additionner deux vecteurs composante par composante
	//param Vecteur3D vec Le vecteur avec lequel on souhaite additionner le vecteur
	//return Le vecteur résultant de l'addition des vecteurs
	Vecteur3D operator+(Vecteur3D& vec);
	//surcharge l'opérateur - pour soustraire deux vecteurs composante par composante
	//param Vecteur3D vec Le vecteur avec lequel on souhaite soustraire le vecteur
	//return Le vecteur résultant de la soustraction des vecteurs
	Vecteur3D operator-(Vecteur3D& vec);

private:
	double x, y, z;

};

