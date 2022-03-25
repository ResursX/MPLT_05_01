#include "MPLT_05_01_INT.h"
#include "MPLT_05_01_TREE.h"
#include <iostream>

namespace MPLT_05_01 {
	void TreeRemove(PNode&, PNode&);

	//TTree

	TTree::TTree()
	{
		Root = nullptr;
	}

	TTree::~TTree()
	{
		Root->Destroy();
	}

	void TTree::Add(GameObject* x)
	{
		Root = Root->Insert(x);
	}

	void TTree::Remove(int x)
	{
		Root = Root->Remove(x);
	}

	PNode TTree::Find(int x)
	{
		return Root->Find(x);
	}

	std::string TTree::Print()
	{
		if (!Root)
			return "Empty tree.\n";

		return Root->Print();
	}

	//TNode

	TNode::TNode(GameObject* x, TNode* parent)
	{
		Data = x;

		Parent = parent;
		Left = nullptr;
		Right = nullptr;

		Color = RED;
	}

	TNode::~TNode()
	{
		if (Parent)
		{
			if (Parent->Left == this)
			{
				Parent->Left = nullptr;
			}
			else if (Parent->Right == this)
			{
				Parent->Right = nullptr;
			}
		}
		delete Data;
	}

	void TNode::Destroy()
	{
		if (this == nullptr)
			return;

		this->Left->Destroy();
		this->Right->Destroy();

		delete this;
	}

	// Rotations

	void TNode::RotateLeft(TNode* node, TNode*& root)
	{
		PNode r = node->Right;

		node->Right = r->Left;

		if (r->Left)
		{
			r->Left->Parent = node;
		}

		r->Left = node;
		r->Parent = node->Parent;
		node->Parent = r;

		if (r->Parent)
		{
			if (r->Parent->Left == node)
			{
				r->Parent->Left = r;
			}
			else
			{
				r->Parent->Right = r;
			}
		}
		else
		{
			root = r;
		}
	}

	void TNode::RotateRight(TNode* node, TNode*& root)
	{
		PNode l = node->Left;

		node->Left = l->Right;

		if (l->Right)
		{
			l->Right->Parent = node;
		}

		l->Right = node;
		l->Parent = node->Parent;
		node->Parent = l;

		if (l->Parent)
		{
			if (l->Parent->Left == node)
			{
				l->Parent->Left = l;
			}
			else
			{
				l->Parent->Right = l;
			}
		}
		else
		{
			root = l;
		}
	}

	// Insert

	TNode* TNode::Insert(GameObject* x)
	{
		TNode* t = this, *r = this;

		TNode::Insert(t, t ? t->Parent : nullptr, r, x);

		return r;
	}

	void TNode::Insert(TNode*& node, TNode* parent, TNode*& root, GameObject* x)
	{
		if (!node)
		{
			node = new TNode(x, parent);

			if (!root)
			{
				root = node;
			}

			InsertFix(node, root);

			return;
		}

		if (x->GetID() < node->Data->GetID())
		{
			Insert(node->Left, node, root, x);
		}
		else
		{
			Insert(node->Right, node, root, x);
		}
	}

	void TNode::InsertFix(TNode* n, TNode*& root)
	{
		while (n->Parent && n->Parent->Color == RED)
		{
			PNode g = n->Parent->Parent, u;

			if (g->Left == n->Parent)
			{
				u = g->Right;

				if (u && u->Color == RED)
				{
					n->Parent->Color = BLACK;
					u->Color = BLACK;
					g->Color = RED;

					n = g;
				}
				else
				{
					if (n->Parent->Right == n)
					{
						n = n->Parent;
						RotateLeft(n, root);
					}

					RotateRight(g, root);

					g->Color = RED;

					if (n->Parent)
						n->Parent->Color = BLACK;
				}
			}
			else
			{
				u = g->Left;

				if (u && u->Color == RED)
				{
					n->Parent->Color = BLACK;
					u->Color = BLACK;
					g->Color = RED;

					n = g;
				}
				else
				{
					if (n->Parent->Left == n)
					{
						n = n->Parent;
						RotateRight(n, root);
					}

					RotateLeft(g, root);

					g->Color = RED;

					if (n->Parent)
						n->Parent->Color = BLACK;
				}
			}
		}

		if (!n->Parent)
			n->Color = BLACK;
	}

	// Removal

	TNode* TNode::Remove(int x)
	{
		TNode* t = this, *f = Find(x);

		Remove(f, t);

		return t;
	}

	void TreeRemove(PNode& node, PNode& q)
	{
		if (node->Right)
		{
			TreeRemove(node->Right, q);
		}
		else
		{
			GameObject* t = q->Data;

			q->Data = node->Data;
			node->Data = t;

			q = node;

			if (node->Left)
				node->Left->Parent = node->Parent;

			node = node->Left;
		}
	}

	void TNode::Remove(TNode* node, TNode*& root)
	{
		if (node)
		{
			PNode t = node, p = node->Parent;

			if (!node->Left)
			{
				node = node->Right;
			}
			else if (!node->Right)
			{
				node = node->Left;
			}
			else
			{
				TreeRemove(node->Left, t);
			}

			if (node)
			{
				node->Parent = p;
			}

			if (p)
			{
				if (p->Left == t)
				{
					p->Left = node;
				}
				else if (p->Right == t)
				{
					p->Right = node;
				}
			}
			else
			{
				root = node;
			}

			if (t->Color == BLACK)
			{
				RemoveFix(node, root);
			}

			delete t;
		}
	}

	void TNode::RemoveFix(TNode* n, TNode*& root)
	{
		TNode* s;

		while (n && n != root && n->Color == BLACK)
		{
			if (n == n->Parent->Left)
			{
				s = n->Parent->Right;

				if (s->Color == RED)
				{
					s->Color = BLACK;
					n->Parent->Color = RED;

					RotateLeft(n->Parent, root);

					s = n->Parent->Right;
				}

				if ((!s->Left || s->Left->Color == BLACK) && (!s->Right || s->Right->Color == BLACK))
				{
					s->Color = RED;
					n = n->Parent;
				}
				else
				{
					if (s->Right)
					{
						if (s->Right->Color == BLACK)
						{
							s->Left->Color = BLACK;
							s->Color = RED;

							RotateRight(s, root);

							s = n->Parent->Right;
						}

						s->Right->Color = BLACK;
					}

					s->Color = s->Parent->Color;
					s->Parent->Color = BLACK;

					RotateLeft(n->Parent, root);

					n = root;
				}
			}
			else
			{
				s = n->Parent->Left;

				if (s->Color == RED)
				{
					s->Color = BLACK;
					n->Parent->Color = RED;

					RotateRight(n->Parent, root);

					s = n->Parent->Left;
				}

				if ((!s->Left || s->Left->Color == BLACK) && (!s->Right || s->Right->Color == BLACK))
				{
					s->Color = RED;
					n = n->Parent;
				}
				else
				{
					if (s->Left)
					{
						if (s->Left->Color == BLACK)
						{
							s->Right->Color = BLACK;
							s->Color = RED;

							RotateLeft(s, root);

							s = n->Parent->Left;
						}

						s->Left->Color = BLACK;
					}

					s->Color = s->Parent->Color;
					s->Parent->Color = BLACK;

					RotateRight(n->Parent, root);

					n = root;
				}
			}
		}

		if (n)
			n->Color = BLACK;
	}

	// Search

	TNode* TNode::Find(int x)
	{
		if (this == nullptr || x == Data->GetID())
		{
			return this;
		}
		else if (x < Data->GetID())
		{
			return Left->Find(x);
		}
		else
		{
			return Right->Find(x);
		}
	}

	std::string TNode::Print()
	{
		if (this == nullptr)
			return "";

		return Left->Print(1) + (Parent ? std::to_string(Parent->Data->GetID()) : "-") + ' ' + (Color == NodeColor::BLACK ? "B" : "R") + ' ' + (Data ? std::to_string(Data->GetID()) : "-") + '\n' + Right->Print(1);
	}

	std::string TNode::Print(int l)
	{
		if (this == nullptr)
			return "";

		return Left->Print(l + 1) + std::string(l * 8, ' ') + (Parent ? std::to_string(Parent->Data->GetID()) : "-") + ' ' + (Color == NodeColor::BLACK ? "B" : "R") + ' ' + (Data ? std::to_string(Data->GetID()) : "-") + '\n' + Right->Print(l + 1);
	}
}