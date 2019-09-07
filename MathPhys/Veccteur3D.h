#pragma once
class Veccteur3D
{
public:
	
	Veccteur3D();
	Veccteur3D(double x, double y, double z);
	~Veccteur3D();
	double norme();
	double normecarre();
	void normalisation();
	void mulScalaire(double k);
	Veccteur3D prodComp(Veccteur3D vec1);
	double prodScalaire(Veccteur3D vec1);
	Veccteur3D prodVectorielle(Veccteur3D vec1);
	double getx();
	double gety();
	double getz();
private:
	double x, y, z;

};

