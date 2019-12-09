#pragma once
#include "Primitive.h"
#include "Vector3D.h"

using namespace std;
class BVH
{
private:
    Primitive* object;
    BVH* tleft;
    BVH* tright;
    BVH* parent;

public:
    // Constructeur par défaut de la classe BVH
    BVH()
    {
        object = new Primitive();
        parent = NULL;
        tleft = NULL;
        tright = NULL;
    };

    // Constructeur a un parametre de la classe BVH
    // param : object : la primitive de l'objet
    BVH(Primitive* object);

    // Methode qui ajoute une primitive dans un bvh
    // param : object : La primitive de l'objet
    // param : tree : le bvh
    void Insertion(Primitive* object, BVH* tree);

    // Methode pour la suppression d'un noeud du BVH
    // param : tree : le BVH
    void Suppression(BVH* tree);

    // Gettter pour  l'attribut tleft de la class BVH
    // return : la valeur de l'attribut tleft
    BVH* getLeftSon() { return tleft; };

    // Getter pour l'attribut tright de la classe BVH
    // return : la valeur de tright
    BVH* getRightSon() { return tright; };

    // Getter pour l'attribut parent de la classe BVH
    // return : la valeur de parent
    BVH* getparent() { return parent; };

    // Getter pour l'attribut object de la classe BVH
    // return : la valeur de object
    Primitive* getobject() { return object; };

    // Methode pour savoir si le noeud est une feuille
    int isLeaf();

    // Setter pour l'attribut tright de la classe BVH
    // param : tright : la nouvelle valeur pour l'attribut tright
    void setRightSon(BVH* tright) { this->tright = tright; };

    // Setter pour l'attribut tleft de la classe BVH
    // param : tleft : la nouvelle valeur pour l'attribut tleft
    void setLeftSon(BVH* tleft) { this->tleft = tleft; };
};