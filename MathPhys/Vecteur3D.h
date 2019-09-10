#pragma once
class Vecteur3D
{
public:
	
	Vecteur3D();
	Vecteur3D(double x, double y, double z);
	~Vecteur3D();
	double norme();
	double normecarre();
	void normalisation();
	void mulScalaire(double k);
	Vecteur3D prodComp(Vecteur3D vec1);
	double prodScalaire(Vecteur3D vec1);
	Vecteur3D prodVectorielle(Vecteur3D vec1);
	double getx();
	double gety();
	double getz();

	Vecteur3D operator+(Vecteur3D& vec);
	Vecteur3D operator-(Vecteur3D& vec);

private:
	double x, y, z;

};

