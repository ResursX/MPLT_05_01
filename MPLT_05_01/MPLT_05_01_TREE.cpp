#include "MPLT_05_01_INT.h"
#include "MPLT_05_01_TREE.h"

namespace MPLT_05_01 {
	void TreeInsert(PNode&, PNode, GameObject*);
	void TreeRemove(PNode&, PNode, int);

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
		TreeRemove(Root, NULL, x);
	}

	std::string TTree::Print()
	{
		return Root->Print();
	}

	//TNode

	TNode::TNode(GameObject* x)
	{
		Object = x;

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

		delete Object;
	}

	std::string TNode::Print()
	{
		return (Left ? Left->Print(1) : "") + std::to_string(Object->GetID()) + '\n' + (Right ? Right->Print(1) : "");
	}

	std::string TNode::Print(int l)
	{
		return (Left ? Left->Print(l + 1) : "") + std::string(l * 3, ' ') + std::to_string(Object->GetID()) + '\n' + (Right ? Right->Print(l + 1) : "");
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
			if (x->GetID() < node->Object->GetID())
			{
				TreeInsert(node->Left, node, x);
			}
			else
			{
				TreeInsert(node->Right, node, x);
			}
		}
	}

	void TreeRemove(PNode& node, PNode parent, int x)
	{
		//if (!node)
		//{
		//	node = new TNode(x);
		//	node->Parent = parent;
		//}
		//else
		//{
		//	if (x->GetID() < node->Object->GetID())
		//	{
		//		TreeInsert(node->Left, node, x);
		//	}
		//	else
		//	{
		//		TreeInsert(node->Right, node, x);
		//	}
		//}
	}
}