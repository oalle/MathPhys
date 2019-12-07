#include "..\include\BVH.h"

BVH::BVH(RigidBody* object)
{
    this->object = object;
	object->getRayonVolemeEng();
    parent = NULL;
    tleft = NULL;
    tright = NULL;
}

void BVH::Insertion(RigidBody* pobject, BVH* tree)
{
    BVH Newnode = BVH(pobject);
    // si le noeud courant est une feuille
    if (tree->tleft == NULL && tree->tright == NULL)
    {
        // on met à jour le fils de droite avec l'objet du parent et on met à jour son parent
        BVH movenode = BVH(tree->object);
        movenode.parent = tree;
        // on met à jour le fils de gauche avec le nouvel objet et on met à jour son parent
        Newnode.parent = tree;
        // on met à jour le node parent
        tree->object = NULL;
        tree->tright = &movenode;
        tree->tleft = &Newnode;
    }
    // si le noeud courant n'est pas une feuille on va chercher parmi les feuilles lequel permet
    // d'avoir un volume englobant minime
    else
    {
        float volumeenglobantleft = 0;
        float volumeenglobantright = 0;
        if (tree->tleft != NULL)
        {
            if (tree->tleft->tleft == NULL && tree->tleft->tright == NULL)
            {
                Vector3D vectorBetween =
                    (tree->tleft->object->getCenterVolumeEng() - pobject->getCenterVolumeEng());
                volumeenglobantleft = vectorBetween.norme();
            }
        }
        else if (tree->tright != NULL)
        {
            if (tree->tright->tleft == NULL && tree->tright->tright == NULL)
            {
                Vector3D vectorBetween =
                    (tree->tright->object->getCenterVolumeEng() - pobject->getCenterVolumeEng());
                volumeenglobantright = vectorBetween.norme();
            }
        }
        if (volumeenglobantright >= volumeenglobantleft) { Insertion(pobject, tree->tleft); }
        else
        {
            Insertion(pobject, tree->tright);
        }
    }
}

void BVH::Suppression(BVH* tree)
{
    BVH* Temptree;
    if (tree->parent != NULL)
    {
        if (tree->parent->tleft == tree) { Temptree = tree->parent->tright; }
        else
        {
            Temptree = tree->parent->tleft;
        }
        tree->parent = Temptree;
    }
    else
    {
        tree == NULL;
    }
}