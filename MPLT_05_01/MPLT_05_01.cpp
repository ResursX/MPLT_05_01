#include <iostream>
#include "MPLT_05_01_INT.h"
#include "MPLT_05_01_TREE.h"

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

        color = NodeColor::RED;
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
        TTree *l = left;

        left = l->right;
        l->right->parent = this;
        l->right = this;
        parent = l;

        return l;
    }

    TTree* RotateRight()
    {
        PTree r = right;

        right = r->left;
        r->left->parent = this;
        r->left = this;
        parent = r;

        return r;
    }

    void Insert(MPLT_05_01::GameObject* x)
    {
        if (!this)
        {
            *this = *(new TTree(x));
        }

        if (x->GetID() < object->GetID())
        {
            if (left)
            {
                left->Insert(x);
            }
            else
            {
                left = new TTree(x);
                left->parent = this;
            }
        }
        else
        {
            if (right)
            {
                right->Insert(x);
            }
            else
            {
                right = new TTree(x);
                right->parent = this;
            }
        }
    }

    std::string print()
    {
        if (!this)
            return "";

        return left->print(1) + std::to_string(object->GetID()) + '\n' + right->print(1);
    }

private:
    std::string print(int i)
    {
        if (!this)
            return "";

        return left->print(i + 1) + std::string(i * 3, ' ') + std::to_string(object->GetID()) + '\n' + right->print(i + 1);
    }
} *PTree;

int main()
{
    MPLT_05_01::PTree tree = new MPLT_05_01::TTree();

    //MPLT_05_01::Tank* o = new MPLT_05_01::Tank(0, 50000, "tank.png", 800, 800);
    tree->Add(new MPLT_05_01::Tank(0, 50000, "tank.png", 800, 800));
    tree->Add(new MPLT_05_01::Plane(1, 60000, "plane.png", 16000, 25000));
    tree->Add(new MPLT_05_01::Projectile(2, 2500, 400));
    tree->Add(new MPLT_05_01::Projectile(-2, 2500, 400));
    tree->Add(new MPLT_05_01::Projectile(-3, 2500, 400));
    tree->Add(new MPLT_05_01::Projectile(-1, 2500, 400));

    std::cout << tree->Print();

    //std::cout << o->print();

    return 0;
}
