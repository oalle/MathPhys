#pragma once
#include "RigidBody.h"
#include "Vector3D.h"

using namespace std;
class BVH
{
private:
    
        RigidBody * object;
        BVH* tleft;
        BVH* tright;
        BVH* parent;
    

public:
        BVH() { };
    BVH(RigidBody * object);
    void Insertion(RigidBody * object, BVH * tree);
    void Suppression(BVH * tree);
    void getLeafCount(BVH * tree);
};