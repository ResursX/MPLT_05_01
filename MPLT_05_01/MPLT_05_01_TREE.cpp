#include "MPLT_05_01_INT.h"
#include "MPLT_05_01_TREE.h"

namespace MPLT_05_01 {
	void TreeInsert(PNode&, PNode, GameObject*);
	void TreeRemove(PNode&, int);

	//TTree

	TTree::TTree()
	{
		Root = NULL;
	}

	TTree::~TTree()
	{
		delete Root;
	}

	void TTree::Add(GameObject* x)
	{
		TreeInsert(Root, NULL, x);
	}

	void TTree::Remove(int x)
	{
		TreeRemove(Root, x);
	}

	std::string TTree::Print()
	{
		return Root->Print();
	}

	//TNode

	TNode::TNode(GameObject* x)
	{
		Data = x;

		Parent = NULL;
		Left = NULL;
		Right = NULL;

		Color = NodeColor::RED;
	}

	TNode::~TNode()
	{
		if (Left)
		{
			delete Left;
		}

		if (Right)
		{
			delete Right;
		}

		delete Data;
	}

	std::string TNode::Print()
	{
		return (Left ? Left->Print(1) : "") + std::to_string(Data->GetID()) + '\n' + (Right ? Right->Print(1) : "");
	}

	std::string TNode::Print(int l)
	{
		return (Left ? Left->Print(l + 1) : "") + std::string(l * 3, ' ') + std::to_string(Data->GetID()) + '\n' + (Right ? Right->Print(l + 1) : "");
	}

	void TreeInsert(PNode& node, PNode parent, GameObject* x)
	{
		if (!node)
		{
			node = new TNode(x);
			node->Parent = parent;
		}
		else
		{
			if (x->GetID() < node->Data->GetID())
			{
				TreeInsert(node->Left, node, x);
			}
			else
			{
				TreeInsert(node->Right, node, x);
			}
		}
	}

	void _TreeRemove(PNode& node, PNode& q)
	{
		if (node->Right)
		{
			_TreeRemove(node->Right, q);
		}
		else
		{
			q->Data = node->Data;
			q = node;
			node = node->Left;
		}
	}

	void TreeRemove(PNode& node, int x)
	{
		if (node)
		{
			if (x < node->Data->GetID())
			{
				TreeRemove(node->Left, x);
			}
			else if (x > node->Data->GetID())
			{
				TreeRemove(node->Right, x);
			}
			else
			{
				PNode t = node;
				if (!node->Left)
				{
					node = node->Left;
				}
				else if (!node->Right)
				{
					node = node->Right;
				}
				else
				{
					_TreeRemove(node->Left, t);
				}

				node->Parent = t->Parent;
				t->Left = NULL;
				t->Right = NULL;

				delete t;
			}
		}
	}
}