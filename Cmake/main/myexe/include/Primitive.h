#pragma once
#include "RigidBody.h"
#include "Vector3D.h"
#include "Contact.h"

using namespace std;
class Primitive
{
protected:
    
        RigidBody * body;
    //position de la primitive par rapport au centre de l'objet
		Vector3D Position;
    struct BoundingSphere
    {
        Vector3D center;
        float rayon;
    };

	BoundingSphere boundingsphere;
	//attribut pour plane
	Vector3D normal;
	float offset;

public:
        Primitive(){boundingsphere = {Vector3D(), 0.0}; };
    Primitive(float InverseMass, float LinearDamping, float AngularDamping, Vector3D Positionrigid,
              Quaternion Orientation, Vector3D Position);
		Primitive(RigidBody * body, Vector3D Position);
	float getRayonVolemeEng() { return boundingsphere.rayon; };	
	Vector3D getCenterVolumeEng() { return boundingsphere.center; };
    void setRayonVolemeEng(float rayon) { boundingsphere.rayon = rayon; };
	void setCenterVolumeEng(Vector3D vector) { boundingsphere.center = vector; };
    RigidBody* getRigidBody() { return body; };
        Vector3D getPosition() { return Position; };
    Vector3D getnormal() { return normal; };
    float getoffset() { return offset; };
};