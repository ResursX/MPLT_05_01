#include <iostream>
#include "MPLT_05_01_INT.h"

enum class NodeColor
{
    BLACK,
    RED
};

typedef struct TTree {
    MPLT_05_01::GameObject *object;
    TTree *parent, *left, *right;
    NodeColor color;

    TTree(MPLT_05_01::GameObject *_o)
    {
        object = _o;

        parent = NULL;
        left = NULL;
        right = NULL;

        color = NodeColor::BLACK;
    }

    ~TTree()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }

        delete object;
    }

    TTree* RotateLeft()
    {
        TTree *l = this->left;

        this->left = l->right;
        l->right->parent = this;
        l->right = this;
        this->parent = l;

        return l;
    }

    TTree* RotateRight()
    {
        PTree r = this->right;

        this->right = r->left;
        r->left = this;

        return r;
    }
} *PTree;

int main()
{
    MPLT_05_01::Tank *t = new MPLT_05_01::Tank(0, 50000, "tank.png", 800, 800);
    MPLT_05_01::Plane *p = new MPLT_05_01::Plane(1, 60000, "plane.png", 16000, 25000);
    MPLT_05_01::Projectile *pr = new MPLT_05_01::Projectile(2, 2500, 400);

    std::cout << t->print() << std::endl << p->print() << std::endl << pr->print() << std::endl;

    std::cout << "Hello World!\n";

    return 0;
}
