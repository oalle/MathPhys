#pragma once
#include "Primitive.h"
#include "Vector3D.h"

using namespace std;
class BVH
{
private:
    
        Primitive * object;
        BVH* tleft;
        BVH* tright;
        BVH* parent;
    

public:
        BVH() { object = new Primitive(); parent = NULL;
    tleft = NULL;
    tright = NULL;};
    BVH(Primitive * object);
    void Insertion(Primitive * object, BVH * tree);
    void Suppression(BVH * tree);
    BVH* getLeftSon() { return tleft; };
	BVH* getRightSon() { return tright; };
	BVH* getparent() { return parent; };
        Primitive* getobject() { return object; };
        int isLeaf();
        void setRightSon(BVH* tright) { this->tright = tright; };
		void setLeftSon(BVH* tleft) { this->tleft = tleft; };
};