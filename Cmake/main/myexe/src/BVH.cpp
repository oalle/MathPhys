#include "..\include\BVH.h"

// Constructeur a un parametre de la classe BVH
// param : object : la primitive de l'objet
BVH::BVH(Primitive* object)
{
    this->object = object;

    parent = NULL;
    tleft = NULL;
    tright = NULL;
}

// Methode qui ajoute une primitive dans un bvh
// param : object : La primitive de l'objet
// param : tree : le bvh
void BVH::Insertion(Primitive* pobject, BVH* tree)
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
        tree->object = new Primitive();
        tree->tright = &movenode;
        tree->tleft = &Newnode;
        // on calcul le volume englobant du parent
        Vector3D vectorBetween = (tree->tleft->object->getCenterVolumeEng() -
                                  tree->tright->object->getCenterVolumeEng());
        tree->object->setRayonVolemeEng(tree->tright->object->getRayonVolemeEng() +
                                        tree->tleft->object->getRayonVolemeEng() +
                                        vectorBetween.norme());

        // on calcul le centre de ce volume englobant
        Vector3D position =
            tree->tleft->object->getCenterVolumeEng() + vectorBetween.mulScalaireResult(0.5);
        tree->object->setCenterVolumeEng(position);
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
                // std::cout <<"1"<< vectorBetween.getx() << vectorBetween.gety() <<
                // vectorBetween.getz() << std::endl;
                volumeenglobantleft = vectorBetween.norme();
            }
        }
        else if (tree->tright != NULL)
        {
            if (tree->tright->tleft == NULL && tree->tright->tright == NULL)
            {
                Vector3D vectorBetween =
                    (tree->tright->object->getCenterVolumeEng() - pobject->getCenterVolumeEng());
                // std::cout <<"2"<< vectorBetween.getx() << vectorBetween.gety() <<
                // vectorBetween.getz() << std::endl;
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

// Methode pour la suppression d'un noeud du BVH
// param : tree : le BVH
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

// Methode pour savoir si le noeud est une feuille
int BVH::isLeaf()
{
    if (tleft == NULL && tright == NULL) { return 1; }
    else
    {
        return 0;
    }
}