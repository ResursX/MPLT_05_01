#include <iostream>
#include "MPLT_05_01_INT.h"
#include "MPLT_05_01_TREE.h"
using namespace std;

int ReadID();

int main()
{
    MPLT_05_01::PTree tree = new MPLT_05_01::TTree();

    //MPLT_05_01::Tank* o = new MPLT_05_01::Tank(0, 50000, "tank.png", 800, 800);
    tree->Add(new MPLT_05_01::Tank(0, 50000, "tank.png", 800, 800));
    tree->Add(new MPLT_05_01::Plane(2, 60000, "plane.png", 16000, 25000));
    tree->Add(new MPLT_05_01::Projectile(1, 2500, 400));
    tree->Add(new MPLT_05_01::Projectile(3, 2500, 400));
    tree->Add(new MPLT_05_01::Projectile(-2, 2500, 400));
    tree->Add(new MPLT_05_01::Projectile(-1, 2500, 400));
    tree->Add(new MPLT_05_01::Projectile(-3, 2500, 400));
    tree->Add(new MPLT_05_01::Projectile(-4, 2500, 400));

    //std::cout << tree->Print();
    
    char c;
    int ID;
    MPLT_05_01::PNode node;
    bool exit = false;

    while (!exit)
    {
        cout << "Enter command: ";
        cin >> c;

        switch (c)
        {
        case 'a':
            ID = ReadID();

            node = tree->Find(ID);

            if (!node)
            {
                int type, Caliber, ArmorThickness;
                double Weight, EnginePower, Capacity;
                string Texture;

                cout << "Object types:\n-1 - Cancel\n0 - Projectile\n1 - Transport Vehicle\n2 - Tank\n3 - Plane" << endl;
                do {
                    cout << "Enter object type: ";
                    cin >> type;
                    if (type < -1 || type > 3)
                    {
                        cout << "Incorrect type." << endl;
                    }
                } while (type < -1 || type > 3);
                
                if (type == -1)
                    break;

                cout << "Enter weight: ";
                cin >> Weight;

                if (type == 0)
                {
                    cout << "Enter caliber: ";
                    cin >> Caliber;
                }

                if (type == 1 || type == 2 || type == 3)
                {
                    cout << "Enter engine power: ";
                    cin >> EnginePower;
                }

                if (type == 2 || type == 3)
                {
                    cout << "Enter texture path: ";
                    cin >> Texture;
                }

                if (type == 2)
                {
                    cout << "Enter armor thickness: ";
                    cin >> ArmorThickness;
                }

                if (type == 3)
                {
                    cout << "Enter cargo capacity: ";
                    cin >> Capacity;
                }

                switch (type)
                {
                case 0:
                    tree->Add(new MPLT_05_01::Projectile(ID, Weight, Caliber));
                    break;
                case 1:
                    tree->Add(new MPLT_05_01::TransportVehicle(ID, Weight, EnginePower));
                    break;
                case 2:
                    tree->Add(new MPLT_05_01::Tank(ID, Weight, Texture, EnginePower, ArmorThickness));
                    break;
                case 3:
                    tree->Add(new MPLT_05_01::Plane(ID, Weight, Texture, EnginePower, Capacity));
                    break;
                }
            }
            else
            {
                std::cout << "Object already exists:" << endl;
                std::cout << node->Data->print() << std::endl;
            }

            break;
        case 'f':
            ID = ReadID();

            node = tree->Find(ID);

            if (node)
            {
                std::cout << "Object found (Type: ";

                if (typeid(*node->Data) == typeid(MPLT_05_01::Projectile))
                {
                    std::cout << "Projectile";
                }
                else if (typeid(*node->Data) == typeid(MPLT_05_01::TransportVehicle))
                {
                    std::cout << "Transport Vehicle";
                }
                else if (typeid(*node->Data) == typeid(MPLT_05_01::Tank))
                {
                    std::cout << "Tank";
                }
                else if (typeid(*node->Data) == typeid(MPLT_05_01::Plane))
                {
                    std::cout << "Plane";
                }

                std::cout << ")" << endl << node->Data->print();
            }
            else
            {
                std::cout << "Object not found." << endl;
            }

            break;
        case 'r':
            ID = ReadID();

            node = tree->Find(ID);

            if (node)
            {
                std::cout << "Object deleted." << endl;
                tree->Remove(ID);
            }
            else
            {
                std::cout << "Object not found." << endl;
            }

            break;
        case 't':
            cout << "Tree scheme: " << endl;
            cout << tree->Print();
            break;
        case 'y':
            cout << "Root: " << tree->Root->Data->GetID() << endl;
            break;
        case 'e':
            exit = true;
            break;
        default:
            cout << "Unknown command."<< endl;
            break;
        }
    }

    delete tree;

    return 0;
}

int ReadID()
{
    int id;

    cout << "Enter ID: ";
    cin >> id;

    return id;
}