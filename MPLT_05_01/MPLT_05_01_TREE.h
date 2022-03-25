#pragma once
#include "MPLT_05_01_INT.h"

namespace MPLT_05_01 {
	enum NodeColor
	{
		BLACK,
		RED
	};

	class TNode {
	public:
		TNode(GameObject*, TNode*);
		~TNode();

		MPLT_05_01::GameObject* Data;
		TNode* Parent, * Left, * Right;
		NodeColor Color;

		void Destroy();

		TNode* Insert(GameObject*);
		TNode* Remove(int);
		TNode* Find(int);

		std::string Print();
	private:
		static void RotateLeft(TNode*, TNode*&);
		static void RotateRight(TNode*, TNode*&);

		static void Insert(TNode*&, TNode*, TNode*&, GameObject*);
		static void InsertFix(TNode*, TNode*&);

		static void Remove(TNode*, TNode*&);
		static void RemoveFix(TNode*, TNode*&);

		std::string Print(int);
	};

	typedef TNode *PNode;

	class TTree {
	public:
		TTree();
		~TTree();

		PNode Root;

		void Add(GameObject*);
		void Remove(int);
		PNode Find(int);
		std::string Print();
	private:
	};

	typedef TTree* PTree;
}